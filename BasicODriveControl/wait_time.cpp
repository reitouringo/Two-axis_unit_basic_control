#include "wait_time.hpp"
#include "Arduino.h"

bool Wait::waiting(unsigned int milliseconds)
{
    if(_is_first)
    {
        _start = millis();
        _is_first = false;
    }

    if(millis()-_start >= milliseconds)
    {
        _is_first = true;
        return true;
    }

    return false;
}