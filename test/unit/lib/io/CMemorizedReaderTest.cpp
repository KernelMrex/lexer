#include "../../../../src/lib/io/CBufferedReader.hpp"
#include "../../../../src/lib/io/CMemorizedReader.hpp"
#include "MockReader.cpp"
#include <gtest/gtest.h>

TEST(CMemorizedReaderTest, ReadAndMemorize)
{
	auto mockReader = std::make_shared<MockReader>();
	{
		testing::InSequence s;
		EXPECT_CALL(*mockReader, Read(testing::_))
			.Times(1)
			.WillOnce(testing::DoAll(testing::SetArgReferee<0>('a'), testing::Return(true)));
		EXPECT_CALL(*mockReader, Read(testing::_))
			.Times(1)
			.WillOnce(testing::DoAll(testing::SetArgReferee<0>('b'), testing::Return(true)));
		EXPECT_CALL(*mockReader, Read(testing::_))
			.Times(1)
			.WillOnce(testing::DoAll(testing::SetArgReferee<0>('c'), testing::Return(true)));
		EXPECT_CALL(*mockReader, Read(testing::_))
			.Times(1)
			.WillOnce(testing::DoAll(testing::SetArgReferee<0>('d'), testing::Return(true)));
		EXPECT_CALL(*mockReader, Read(testing::_))
			.Times(1)
			.WillOnce(testing::DoAll(testing::SetArgReferee<0>('e'), testing::Return(true)));
	}

	CMemorizedReader reader(mockReader);
	char ch;

	ASSERT_TRUE(reader.Read(ch));
	ASSERT_EQ(ch, 'a');

	ASSERT_TRUE(reader.ReadWithMemorize(ch));
	ASSERT_EQ(ch, 'b');

	ASSERT_TRUE(reader.Read(ch));
	ASSERT_EQ(ch, 'b');

	ASSERT_TRUE(reader.ReadWithMemorize(ch));
	ASSERT_EQ(ch, 'c');

	reader.Reset();

	ASSERT_TRUE(reader.Read(ch));
	ASSERT_EQ(ch, 'd');

	ASSERT_TRUE(reader.ReadWithMemorize(ch));
	ASSERT_EQ(ch, 'e');

	ASSERT_TRUE(reader.Read(ch));
	ASSERT_EQ(ch, 'e');
}