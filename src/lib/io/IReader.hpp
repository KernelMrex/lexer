#ifndef LEXER_IREADER_HPP
#define LEXER_IREADER_HPP

class IReader
{
public:
	virtual bool Read(char& ch) = 0;

	virtual ~IReader() = default;
};

#endif // LEXER_IREADER_HPP
