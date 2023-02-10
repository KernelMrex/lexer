#ifndef LEXER_CMEMORIZEDREADER_HPP
#define LEXER_CMEMORIZEDREADER_HPP

#include "IReader.hpp"
#include <memory>
#include <stack>
#include <utility>

class CMemorizedReader
{
public:
	explicit CMemorizedReader(std::shared_ptr<IReader> reader)
		: m_reader(std::move(reader))
		, m_stack(std::stack<char>())
	{
	}

	bool Read(char& ch)
	{
		if (!m_stack.empty())
		{
			ch = m_stack.top();
			m_stack.pop();
			return true;
		}
		return m_reader->Read(ch);
	}

	bool ReadWithMemorize(char& ch)
	{
		char tmpCh;
		auto res = m_reader->Read(tmpCh);
		if (res)
		{
			m_stack.push(tmpCh);
		}
		ch = tmpCh;
		return res;
	}

	void Reset()
	{
		std::stack<char>().swap(m_stack);
	}

private:
	std::shared_ptr<IReader> m_reader;
	std::stack<char> m_stack;
};

#endif // LEXER_CMEMORIZEDREADER_HPP
