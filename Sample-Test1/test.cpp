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

TEST(TestFlashMemory, TestReadFail)
{
	MockFlashMemory mock;
	EXPECT_CALL(mock, read(0xCC))
		.Times(5)
		.WillOnce(Return('C'))
		.WillOnce(Return('C'))
		.WillOnce(Return('C'))
		.WillOnce(Return('C'))
		.WillOnce(Return('A'));

	DeviceDriver dd(&mock);
	EXPECT_THROW(dd.read(0xCC), ReadException);
}