#ifndef LEXER_CBUFFEREDREADER_HPP
#define LEXER_CBUFFEREDREADER_HPP

#include "IReader.hpp"
#include <istream>
#include <vector>

class CBufferedReader : public IReader
{
public:
	explicit CBufferedReader(std::istream& in, std::size_t bufferSize = 256)
		: m_in(in)
		, m_buf(std::vector<char>(bufferSize, 0))
		, m_currentBufferSize(0)
		, m_index(0)
	{
	}

	bool Read(char& ch) override;

private:
	std::istream& m_in;
	std::vector<char> m_buf;
	std::size_t m_currentBufferSize;
	std::size_t m_index;

	bool ReadNextChunk();
};

#endif // LEXER_CBUFFEREDREADER_HPP
