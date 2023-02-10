#ifndef LEXER_ILEXER_HPP
#define LEXER_ILEXER_HPP

#include "Token.hpp"
#include <vector>

class ILexer
{
public:
	virtual Token Next() = 0;

	virtual ~ILexer() = default;
};

#endif // LEXER_ILEXER_HPP
