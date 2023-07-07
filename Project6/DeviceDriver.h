#pragma once
#include "FlashMemoryDevice.h"
#include <stdexcept>

class ReadException : public std::exception
{
public:
	explicit ReadException(char const* msg)
		:exception(msg)
	{
		
	}
};

class DeviceDriver
{
public:
    DeviceDriver(FlashMemoryDevice* hardware);
    int read(long address);
    void write(long address, int data);

protected:
    FlashMemoryDevice* m_hardware;
};
