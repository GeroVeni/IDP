// Routine functions

#include "utility.h"
#include <stdio.h>
#include <map>

extern std::map <std::pair<int, int>, std::string> pathMap;

// Loads the paths.txt file
void PathLoader()
{
    int n;
    FILE * in = fopen("paths.txt", "r");
    fscanf(in, "%d", &n);
    int start, dest;
    char str[20];
    std::string path;
    pathMap.clear();
    for (int i = 0; i < n; i++)
    {
        fscanf(in, "%d %d %s", &start, &dest, str);
        pathMap[std::make_pair(start, dest)] = str;
    }
}

// Returns the appropriate drop-off point depending on the type of the ball
int DropPosition(int type)
{
    // Set appropriate LED on
    // TODO

    // Returns destination
    static int nextDR = 1;
    if (type == 1) return D1;
    if (type == 3) return D2;
    if (type == 5) return D3;
    if (nextDR == 2)
    {
        nextDR--;
        return DR2;
    }
    nextDR++;
	return DR1;
}

// Sets the motor speed to move forward
int Forward()
{
    return 0;
}

// Sets the motor speeds to turn left
int TurnLeft()
{
    return 0;
}

// Sets the motor speeds to turn right
int TurnRight()
{
    return 0;
}

// Sets the motor speeds to sharply turn left
int SharpLeft()
{
    return 0;
}

// Sets the motor speeds to sharply turn right
int SharpRight()
{
    return 0;
}

// Enters the junction mode
int JunctionMode()
{
    return 0;
}

// Enters the failsafe mode
int FailSafe()
{
    return 0;
}
