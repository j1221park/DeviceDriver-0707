#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Project6/DeviceDriver.cpp"

using namespace testing;

class MockFlashMemory : public FlashMemoryDevice
{
public:
	MOCK_METHOD(unsigned char, read, (long address), (override));
	MOCK_METHOD(void, write, (long address, unsigned char data), (override));
};

TEST(TestFlashMemory, TestRead)
{
	MockFlashMemory mock;
	EXPECT_CALL(mock, read)
		.Times(5);

	DeviceDriver dd(&mock);
	dd.read(0xCC);
}