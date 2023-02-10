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

	bool Read(char& ch) override
	{
		if (m_index % m_buf.size() == 0)
		{
			if (!ReadNextChunk())
			{
				return false;
			}
		}

		if (m_index % m_buf.size() >= m_currentBufferSize)
		{
			return false;
		}

		ch = m_buf[m_index++ % m_buf.size()];
		return true;
	}

private:
	std::istream& m_in;
	std::vector<char> m_buf;
	std::size_t m_currentBufferSize;
	std::size_t m_index;

	bool ReadNextChunk()
	{
		if (!m_in)
		{
			return false;
		}

		m_in.read(m_buf.data(), (long) m_buf.size());
		m_currentBufferSize = m_in ? m_buf.size() : m_in.gcount();

		return true;
	}
};

#endif // LEXER_CBUFFEREDREADER_HPP
