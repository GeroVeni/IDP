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

int Forward()
{
    return 0;
}

int TurnLeft()
{
    return 0;
}


int TurnRight()
{
    return 0;
}


int SharpLeft()
{
    return 0;
}


int SharpRight()
{
    return 0;
}


int JunctionMode()
{
    return 0;
}


int FailSafe()
{
    return 0;
}
