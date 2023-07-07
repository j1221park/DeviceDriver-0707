#pragma once
#include "FlashMemoryDevice.h"
#include <stdexcept>

class ReadExexception : public std::exception
{
	
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
