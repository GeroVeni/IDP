#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <string>
#include <robot_link.h>

class MotorValues;
class SensorValues;
class ColorValue;

extern robot_link rlink;
extern int speed; 
extern int linetracker;
extern char direction;

enum Location
    // Enum mapping the locations
{
    S = 0,
    P1 = 1,
    P2 = 2,
    P3 = 3,
    P4 = 4,
    P5 = 5,
    P6 = 6,
    D1 = 9,
    D2 = 8,
    D3 = 7,
    DR1 = 11,
    DR2 = 10
};

void            PathLoader();

MotorValues     readMotors();
SensorValues    readSensors();
int             readWeight();
ColorValue      readColor();

int             DropPosition(int);
int				colorError(ColorValue, ColorValue);

void            Forward();
void            TurnLeft();
void            TurnRight();
void            SharpLeft();
void            SharpRight();
void            JunctionMode(char direction);
void            FailSafe();

inline void		RightMotor(int a)
{
	rlink.command(MOTOR_4_GO, a);
}

inline void		LeftMotor(int a)
{
	rlink.command(MOTOR_3_GO, a + 128);
}

#endif // __UTILITY_H__
