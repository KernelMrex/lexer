#include "../../../src/lib/io/CBufferedReader.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(CBufferedReaderTest, ReadWithoutBufferUpdate)
{
	std::istringstream iss("abc");
	CBufferedReader reader(iss);
	ASSERT_EQ(reader.Read(), 'a');
	ASSERT_EQ(reader.Read(), 'b');
	ASSERT_EQ(reader.Read(), 'c');
	ASSERT_EQ(reader.Read(), 0);
	ASSERT_EQ(reader.Read(), 0);
}

TEST(CBufferedReaderTest, ReadWithBufferUpdate)
{
	std::istringstream iss("abcde");
	CBufferedReader reader(iss, 3);
	ASSERT_EQ(reader.Read(), 'a');
	ASSERT_EQ(reader.Read(), 'b');
	ASSERT_EQ(reader.Read(), 'c');
	ASSERT_EQ(reader.Read(), 'd');
	ASSERT_EQ(reader.Read(), 'e');
	ASSERT_EQ(reader.Read(), 0);
	ASSERT_EQ(reader.Read(), 0);
}
