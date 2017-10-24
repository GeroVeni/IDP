#ifndef __VALUES_H__
#define __VALUES_H__

enum Motors
{
    RIGHT_MOTOR = MOTOR_3,
    LEFT_MOTOR = MOTOR_4
};

struct ColorValue
{
    int R, G, B;
};

struct MotorValues
{
	int right, left;
};

struct SensorValues
{
    SensorValues(): data(0) {}
    int data;

    int right   () { return data & 1; }
    int mid     () { return data & 2; }
    int left    () { return data & 4; }
};

#endif // __VALUES_H__
