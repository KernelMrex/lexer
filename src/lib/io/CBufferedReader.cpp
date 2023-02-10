#include "CBufferedReader.hpp"

bool CBufferedReader::Read(char& ch)
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

bool CBufferedReader::ReadNextChunk()
{
	if (!m_in)
	{
		return false;
	}

	m_in.read(m_buf.data(), (long) m_buf.size());
	m_currentBufferSize = m_in ? m_buf.size() : m_in.gcount();

	return true;
}