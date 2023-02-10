#ifndef LEXER_IREADER_HPP
#define LEXER_IREADER_HPP

class IReader
{
public:
	virtual char Read() = 0;

	virtual ~IReader() = default;
};

#endif // LEXER_IREADER_HPP
