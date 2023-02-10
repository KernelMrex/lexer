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
		, m_index(0)
	{
	}

	char Read() override
	{
		if (m_index % m_buf.size() == 0 || m_buf[m_index] == 0)
		{
			if (!ReadNextChunk())
			{
				return 0;
			}
		}

		return m_buf[m_index++ % m_buf.size()];
	}

private:
	std::istream& m_in;
	std::vector<char> m_buf;
	std::size_t m_index;

	bool ReadNextChunk()
	{
		if (!m_in)
		{
			return false;
		}

		m_in.read(m_buf.data(), (long) m_buf.size());
		m_buf[m_in ? m_buf.size() : m_in.gcount()] = 0;

		return true;
	}
};

#endif // LEXER_CBUFFEREDREADER_HPP
