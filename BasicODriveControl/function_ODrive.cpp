#include "control_ODrive.hpp"
#include "Arduino.h"


// Three ModeChange Functions
void calibration()
{
    requested_state_0 = AXIS_STATE_FULL_CALIBRATION_SEQUENCE;
    Serial << "Axis0: Requesting state " << requested_state_0 << '\n';
    if(!odrive.run_state(motor_0, requested_state_0, true, 25.0f)) return;

    requested_state_1 = AXIS_STATE_FULL_CALIBRATION_SEQUENCE;
    Serial << "Axis1: Requesting state " << requested_state_1 << '\n';
    if(!odrive.run_state(motor_1, requested_state_1, true, 25.0f)) return;
}

void closedLoop()
{
    requested_state_0 = AXIS_STATE_CLOSED_LOOP_CONTROL;
    Serial << "Axis0: Requesting state " << requested_state_0 << '\n';
    if(!odrive.run_state(motor_0, requested_state_0, false)) return;

    requested_state_1 = AXIS_STATE_CLOSED_LOOP_CONTROL;
    Serial << "Axis1: Requesting state " << requested_state_1 << '\n';
    if(!odrive.run_state(motor_1, requested_state_1, false)) return;
}

void emergencyStop()
{
    requested_state_0 = AXIS_STATE_IDLE;
    Serial << "Axis0: Requesting state " << requested_state_0 << '\n';
    if(!odrive.run_state(motor_0, requested_state_0, false)) return;

    requested_state_1 = AXIS_STATE_IDLE;
    Serial << "Axis1: Requesting state " << requested_state_1 << '\n';
    if(!odrive.run_state(motor_1, requested_state_1, false)) return;    
}


// Posi,Velo,Torq Control Functions
void positionControl(int joint_number, float position)
{
    if(joint_number == 0)
    {
        odrive.SetPosition(motor_0, position);
        odrive.SetPosition(motor_1, position);
    }

    if(joint_number == 1)
    {
        odrive.SetPosition(motor_0, position);
        odrive.SetPosition(motor_1, -position);
    }
}

void velocityControl(int joint_number, float velocity)
{
    if(joint_number == 0)
    {
        odrive.SetVelocity(motor_0, velocity);
        odrive.SetVelocity(motor_1, velocity);
    }

    if(joint_number == 1)
    {
        odrive.SetVelocity(motor_0, velocity);
        odrive.SetVelocity(motor_1, -velocity);
    }
}

void torqueControl(int joint_number, float current)
{
    float torque = torque_constant*current;  // current to torque (daitai 1/2 ninaru.)

    if(joint_number == 0)
    {
        odrive.SetTorque(motor_0, torque);
        odrive.SetTorque(motor_1, torque);
    }

    if(joint_number == 1)
    {
        odrive.SetTorque(motor_0, torque);
        odrive.SetTorque(motor_1, -torque);
    }
}


// Posi,Velo Print Functions
void printPosition()
{
    Serial << "Axis0: Position " << odrive.GetPosition(motor_0) << '\t';
    Serial << "Axis1: Position " << odrive.GetPosition(motor_1) << '\n';
    print_position = false;
}

void printVelocity()
{
    Serial << "Axis0: Velocity " << odrive.GetVelocity(motor_0) << '\t';
    Serial << "Axis1: Velocity " << odrive.GetVelocity(motor_1) << '\n';
    print_velocity = false;
}



