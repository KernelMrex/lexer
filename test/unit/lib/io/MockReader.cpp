#include "../../../../src/lib/io/IReader.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

class MockReader : public IReader
{
public:
	MOCK_METHOD(bool, Read, (char& ch), (override));
};