#ifndef CONTROL_ODRIVE_HPP
#define CONTROL_ODRIVE_HPP

#include <ODriveArduino.h>
#include <SoftwareSerial.h>
#include <HardwareSerial.h>

// Define
#define motor_0 0
#define motor_1 1
#define torque_constant 0.447 // odrive no config de 0.44702 ni setteisitakara ittan konoataide define sita.

// Printing with stream operator helper functions
template<class T> inline Print& operator <<(Print &obj,     T arg) { obj.print(arg);    return obj; }
template<>        inline Print& operator <<(Print &obj, float arg) { obj.print(arg, 4); return obj; }

// Set up serial pins to the ODrive
HardwareSerial& odrive_serial = Serial1;

// ODrive object
ODriveArduino odrive(odrive_serial);

// Global Variables
int requested_state_0;
int requested_state_1;
bool print_position = false;
bool print_velocity = false;

// Function
void calibration();
void closedLoop();
void emergencyStop();

void positionControl(int joint_number, float position);
void velocityControl(int joint_number, float velocity);
void torqueControl(int joint_number, float current);

void printPosition();
void printVelocity();

#endif    // CONTROL_ODRIVE_HPP