#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <string>

extern int speed = 100; 
extern int linetracker = 1;
extern int direction;

enum Location
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

void PathLoader();

int DropPosition(int);

void Forward();
void TurnLeft();
void TurnRight();
void SharpLeft();
void SharpRight();
void JunctionMode(int direction);
void FailSafe();

#endif // __UTILITY_H__
