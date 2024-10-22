#include "WireHelper.h"
#include "DebugLog.h"

using namespace i2c_tools; 

WireHelper::WireHelper(TwoWire& wire) : wire_ref(wire)
{

}

uint8_t WireHelper::scan_for_first_address()
{
    for (uint8_t i = 0; i < 128; i++)
    {
        if (scan_address(i))
        {
            return i; 
        }
    }
    return 0; 
}

bool WireHelper::scan_address(uint8_t address)
{
    wire_ref.begin(); 
    wire_ref.beginTransmission(address); 
    auto error = wire_ref.endTransmission(); 
    if(!error)
    {
        return true; 
    }
    return false; 
}