#include "DeviceDriver.h"
#include <windows.h>

DeviceDriver::DeviceDriver(FlashMemoryDevice* hardware) : m_hardware(hardware)
{}

int DeviceDriver::read(long address)
{
    int result = (int)(m_hardware->read(address));
    for (int i = 1; i < 5; i++)
    {
        Sleep(200);
        if (result != (int)(m_hardware->read(address)))
        {
            throw ReadException("read fail");
        }
    }
    return result;
}

void DeviceDriver::write(long address, int data)
{
    // TODO: implement this method
    m_hardware->write(address, (unsigned char)data);
}