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

	DeviceDriver dd(&mock);
	dd.write(0xDD, 100);
}