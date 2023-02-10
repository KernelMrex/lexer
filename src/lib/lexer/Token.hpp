#ifndef LEXER_TOKEN_HPP
#define LEXER_TOKEN_HPP

#include <string>

struct Token
{
	enum class Type
	{
		ERROR,
		END_OF_FILE,
		ARITH_OP,
		SEPARATOR,
		ASSIGN,
	};

	Type type;
	std::string lexem;
	std::size_t line;
	std::size_t column;
};

#endif // LEXER_TOKEN_HPP
