#include "basic_ODrive_sequence.hpp"
#include "function_ODrive.hpp"
#include "wait_time.hpp"
#include "Arduino.h"

int keyOperate()
{
    if(Serial.available() > 0)
    {
        char key = Serial.read();

        // caliburation
        if(key == '0')
        {
            return 0;
        }

        // closed loop
        else if(key == '1')
        {
            return 1;
        }

        // emergency stop
        else if(key == 'q')
        {
            return 2;
        }

        // position control
        else if(key == 'p')
        {
            return 3;
        }

        // velocity control
        else if(key == 'v')
        {
            return 4;
        }

        // torque control
        else if(key == 't')
        {
            return 5;
        }

        // print position start
        else if(key == 'l')
        {
            return 6;
        }

        // print position end
        else if(key == 'm')
        {
            return 7;
        }

        // print velosity start
        else if(key == 'n')
        {
            return 8;
        }

        // print velosity end
        else if(key == 'o')
        {
            return 9;
        }
    }
}

void basicSequence()
{
    state = keyOperate();

    switch(state)
    {
        case 0:
            calibration();
            break;

        case 1:
            closedLoop();
            break;

        case 2:
            emergencyStop();
            break;

        case 3:
            positionControl(0, 1.0);
            break;

        case 4:
            velocityControl(1, 0.8);
            break;
        
        case 5:
            torqueControl(1, 1.0);
            break;
        
        case 6:
            print_position = true;
            break;

        case 7:
            print_position = false;
            break;

        case 8:
            print_velocity = true;
            break;

        case 9:
            print_velocity = false;
            break;

        default:
            break;
    }

    if(print_position)
    {
        printPosition();
    }

    if(print_velocity)
    {
        printVelocity();
    }
}
