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

TEST(TestFlashMemory, TestWrite)
{
	MockFlashMemory mock;

	EXPECT_CALL(mock, read(0xAA))
		.Times(1)
		.WillRepeatedly(Return(0xFF));

	DeviceDriver dd(&mock);
	dd.write(0xAA, 100);
}

TEST(TestFlashMemory, TestWriteFail)
{
	MockFlashMemory mock;

	EXPECT_CALL(mock, read(0xAA))
		.Times(1)
		.WillRepeatedly(Return(100));

	DeviceDriver dd(&mock);
	EXPECT_THROW(dd.write(0xAA, 100), WriteException);
}

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