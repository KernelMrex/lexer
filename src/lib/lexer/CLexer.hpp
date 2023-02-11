#ifndef LEXER_CLEXER_HPP
#define LEXER_CLEXER_HPP

#include "../io/CBufferedReader.hpp"
#include "../io/CMemorizedReader.hpp"
#include "../io/IReader.hpp"
#include "ILexer.hpp"
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <set>

class CLexer : public ILexer
{
public:
	explicit CLexer(std::istream& in)
		: m_reader(std::make_unique<CMemorizedReader>(std::make_shared<CBufferedReader>(in)))
		, m_line(1)
		, m_column(0)
	{
	}

	Token Next() override
	{
		for (char ch; m_reader->Read(ch);)
		{
			m_column++;

			switch (ch)
			{
			case '\n':
				m_column = 0;
				m_line++;
				continue;
			case ' ':
				continue;
			case '+':
			case '-':
			case '/':
			case '*':
				return Token{ Token::Type::ARITH_OP, std::string{ ch }, m_line, m_column };
			case ',':
			case ';':
				return Token{ Token::Type::SEPARATOR, std::string{ ch }, m_line, m_column };
			case '=':
				return Token{ Token::Type::ASSIGN, "=", m_line, m_column };
			case '(':
			case ')':
				return Token{ Token::Type::BRACKET, std::string{ ch }, m_line, m_column };
			case '{':
			case '}':
				return Token{ Token::Type::CURLY_BRACES, std::string{ ch }, m_line, m_column };
			case '\'':
				return ParseString(ch);
			case '#':
				SkipComment();
				continue;
			default:
				if (IsIdentifierStart(ch))
				{
					return ParseIdentifier(ch);
				}

				if (IsNumberStart(ch))
				{
					return ParseNumber(ch);
				}

				return Token{ Token::Type::ERROR, "", m_line, m_column };
			}
		}
		return Token{ Token::Type::END_OF_FILE, "", m_line, m_column + 1 };
	}

private:
	std::unique_ptr<CMemorizedReader> m_reader;
	std::size_t m_line, m_column;

	inline static const std::map<std::string, Token::Type> m_reservedWords = {
		{ "read", Token::Type::IO_OP },
		{ "write", Token::Type::IO_OP },
		{ "int", Token::Type::TYPE },
		{ "float", Token::Type::TYPE },
		{ "string", Token::Type::TYPE },
		{ "if", Token::Type::IF_OP },
		{ "while", Token::Type::LOOP_OP },
	};

	static bool IsIdentifierStart(char ch)
	{
		return std::isalpha(ch);
	}

	static bool IsIdentifierChar(char ch)
	{
		return std::isalnum(ch);
	}

	static bool IsNumberStart(char ch)
	{
		return ch >= '0' && ch <= '9';
	}

	Token ParseIdentifier(char firstCh)
	{
		std::size_t idBeginColumn = m_column;
		std::string identifier{ firstCh };
		char ch;
		while (m_reader->ReadWithMemorize(ch) && IsIdentifierChar(ch))
		{
			m_reader->Reset();
			m_column++;
			identifier.push_back(ch);
		}

		auto it = m_reservedWords.find(identifier);
		return {
			.type = (it != m_reservedWords.end()) ? it->second : Token::Type::ID,
			.lexem = identifier,
			.line = m_line,
			.column = idBeginColumn
		};
	}

	Token ParseString(char firstCh)
	{
		std::size_t idBeginColumn = m_column;
		std::string string{ firstCh };

		char ch = 0;
		while (ch != '\'')
		{
			if (!m_reader->Read(ch))
			{
				return Token{ Token::Type::ERROR, "", m_line, m_column };
			}
			m_column++;
			string.push_back(ch);
		}

		return { Token::Type::STRING, string, m_line, idBeginColumn };
	}

	Token ParseNumber(char firstCh)
	{
		std::size_t fistCharColumn = m_column;
		char ch;
		if (!m_reader->ReadWithMemorize(ch))
		{
			return Token{ Token::Type::INT, std::string{ firstCh }, m_line, fistCharColumn };
		}

		switch (ch)
		{
		case 'x':
			m_reader->Reset();
			m_column++;
			return ParseHexNumber(fistCharColumn);
		case 'o':
			m_reader->Reset();
			m_column++;
			return ParseOctNumber(fistCharColumn);
		case 'b':
			m_reader->Reset();
			m_column++;
			return ParseBinNumber(fistCharColumn);
		case '.':
			m_reader->Reset();
			m_column++;
			return ParseFloatNumber(fistCharColumn, std::string{ firstCh, ch });
		default:
			if (ch >= '0' && ch <= '9')
			{
				m_reader->Reset();
				m_column++;
				return ParseDecNumber(fistCharColumn, std::string{ firstCh, ch });
			}
			return { Token::Type::INT, std::string{ ch }, m_line, m_column };
		}
	}

	Token ParseHexNumber(std::size_t fistCharColumn)
	{
		return ParseInNumberSystem(fistCharColumn, "0x", [](char ch) -> bool {
			return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f');
		});
	}

	Token ParseOctNumber(std::size_t fistCharColumn)
	{
		return ParseInNumberSystem(fistCharColumn, "0o", [](char ch) -> bool {
			return ch >= '0' && ch <= '7';
		});
	}

	Token ParseBinNumber(std::size_t fistCharColumn)
	{
		return ParseInNumberSystem(fistCharColumn, "0b", [](char ch) -> bool {
			return ch == '0' || ch == '1';
		});
	}

	Token ParseInNumberSystem(std::size_t firstCharColumn, const std::string& prefix, const std::function<bool(char)>& isInRangeCallback)
	{
		std::string num(prefix);
		for (char ch; m_reader->ReadWithMemorize(ch);)
		{
			if (!isInRangeCallback(ch))
			{
				break;
			}

			m_column++;
			num.push_back(ch);
			m_reader->Reset();
		}

		if (num == prefix)
		{
			return Token{ Token::Type::ERROR, "", m_line, m_column + 1 };
		}

		return Token{ Token::Type::INT, num, m_line, firstCharColumn };
	}

	Token ParseDecNumber(std::size_t firstCharColumn, const std::string& prefix)
	{
		std::string num(prefix);

		for (char ch; m_reader->ReadWithMemorize(ch);)
		{
			if (ch == '.')
			{
				m_column++;
				num.push_back(ch);
				m_reader->Reset();
				return ParseFloatNumber(firstCharColumn, num);
			}

			if (!(ch >= '0' && ch <= '9'))
			{
				break;
			}

			m_column++;

			num.push_back(ch);
			m_reader->Reset();
		}

		return Token{ Token::Type::INT, num, m_line, firstCharColumn };
	}

	Token ParseFloatNumber(std::size_t firstCharColumn, const std::string& prefix)
	{
		std::string num(prefix);

		for (char ch; m_reader->ReadWithMemorize(ch);)
		{
			if (!(ch >= '0' && ch <= '9'))
			{
				break;
			}

			m_column++;
			num.push_back(ch);
			m_reader->Reset();
		}

		return Token{ Token::Type::FLOAT, num, m_line, firstCharColumn };
	}

	void SkipComment()
	{
		for (char ch; m_reader->Read(ch);)
		{
			m_column++;
			if (ch == '\n')
			{
				m_column = 0;
				m_line++;
				return;
			}
		}
	}
};

#endif // LEXER_CLEXER_HPP
