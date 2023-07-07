#pragma once
#include "FlashMemoryDevice.h"
#include <exception>

class WriteException : public std::exception
{
public:
    explicit WriteException(const char* msg)
        :exception(msg)
    {

    }
};

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
