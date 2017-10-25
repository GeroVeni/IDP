#ifndef __VALUES_H__
#define __VALUES_H__

class request_instruction;

// Variables describing the motors
const request_instruction RIGHT_MOTOR = MOTOR_3;
const request_instruction LEFT_MOTOR = MOTOR_4;

struct ColorValue
    // Struct that contains information about a color taken from the color sensor
{
    int R, G, B;
};

struct MotorValues
    // Struct containing the variables read from the robot
{
	int right, left;
};

struct SensorValues
    // Struct containing the input from the line tracking sensors
{
    SensorValues(): data(0) {}
    int data;

    bool right  () { return data & 1; }
    bool mid    () { return data & 2; }
    bool left   () { return data & 4; }
};

#endif // __VALUES_H__
