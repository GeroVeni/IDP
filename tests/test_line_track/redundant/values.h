#ifndef __VALUES_H__
#define __VALUES_H__

enum Motors
{
    RIGHT_MOTOR = MOTOR_3,
    LEFT_MOTOR = MOTOR_4
}

struct MotorValues
{
	int right, left;
};

struct SensorValues
{
	int right, mid, left;
};

#endif // __VALUES_H__
