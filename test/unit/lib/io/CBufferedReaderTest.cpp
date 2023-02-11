#include "../../../../src/lib/io/CBufferedReader.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(CBufferedReaderTest, ReadWithoutBufferUpdate)
{
	std::istringstream iss("abc");
	CBufferedReader reader(iss);
	char ch;

	ASSERT_TRUE(reader.Read(ch));
	ASSERT_EQ(ch, 'a');

	ASSERT_TRUE(reader.Read(ch));
	ASSERT_EQ(ch, 'b');

	ASSERT_TRUE(reader.Read(ch));
	ASSERT_EQ(ch, 'c');

	ASSERT_FALSE(reader.Read(ch));
	ASSERT_EQ(ch, 'c');

	ASSERT_FALSE(reader.Read(ch));
	ASSERT_EQ(ch, 'c');
}

TEST(CBufferedReaderTest, ReadWithBufferUpdate)
{
	std::istringstream iss("abcde");
	CBufferedReader reader(iss, 3);
	char ch;

	ASSERT_TRUE(reader.Read(ch));
	ASSERT_EQ(ch, 'a');

	ASSERT_TRUE(reader.Read(ch));
	ASSERT_EQ(ch, 'b');

	ASSERT_TRUE(reader.Read(ch));
	ASSERT_EQ(ch, 'c');

	ASSERT_TRUE(reader.Read(ch));
	ASSERT_EQ(ch, 'd');

	ASSERT_TRUE(reader.Read(ch));
	ASSERT_EQ(ch, 'e');

	ASSERT_FALSE(reader.Read(ch));
	ASSERT_EQ(ch, 'e');

	ASSERT_FALSE(reader.Read(ch));
	ASSERT_EQ(ch, 'e');
}
