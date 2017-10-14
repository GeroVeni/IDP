#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

enum MoveType
{
    STOP,
    FORWARDS,
    BACKWARDS,
    TURN_LEFT,
    TURN_RIGHT,
    ROTATE_LEFT,
    ROTATE_RIGHT,
    TILT_LEFT,
    TILT_RIGHT
};

bool move(MoveType type, int arg)
{
    switch (type)
    {
    }
}

bool connect()
{
    return true;
}

bool calibrate()
{
    return true;
}

int main ()
{
    printf("Starting\n");

    // Connect
    int thresConnect = 10, countConnect = 0;
    while (countConnect < thresConnect && !connect()) countConnect+=1;
    if (countConnect == thresConnect)
    {
        printf("Failure to connect\n");
        return 1;
    }

    // Calibrate
    calibrate();

    // Start

    return 0;
}
