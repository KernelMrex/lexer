#ifndef LEXER_CLEXER_HPP
#define LEXER_CLEXER_HPP

#include "../io/CBufferedReader.hpp"
#include "../io/CMemorizedReader.hpp"
#include "../io/IReader.hpp"
#include "ILexer.hpp"
#include <iostream>
#include <memory>

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
			default:
				if (IsIdentifierStart(ch))
				{
					return ParseIdentifier(ch);
				}

				return Token{ Token::Type::ERROR, "", m_line, m_column };
			}
		}
		return Token{ Token::Type::END_OF_FILE, "", m_line, m_column + 1 };
	}

private:
	std::unique_ptr<CMemorizedReader> m_reader;
	std::size_t m_line, m_column;

	static bool IsIdentifierStart(char ch)
	{
		return std::isalpha(ch);
	}

	static bool IsIdentifierChar(char ch)
	{
		return std::isalnum(ch);
	}

	Token ParseIdentifier(char firstCh)
	{
		std::size_t idBeginColumn = m_column;
		std::string identifier{firstCh};
		char ch;
		while (m_reader->ReadWithMemorize(ch) && IsIdentifierChar(ch))
		{
			m_reader->Reset();
			m_column++;
			identifier.push_back(ch);
		}
		return { Token::Type::ID, identifier, m_line, idBeginColumn };
	}
};

#endif // LEXER_CLEXER_HPP
