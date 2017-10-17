// Routine functions

#include "utility.h"

// Returns the appropriate drop-off point depending on the type of the ball
int DropPosition(int type)
{
    static int nextDR = 1;
    if (type == 1) return D1;
    if (type == 3) return D2;
    if (type == 5) return D3;
    if (nextDR == 2)
    {
        nextDR++;
        return DR2;
    }
    nextDR++;
	return DR1;
}

// Returns the path sequence to connect start and dest
std::string FindPath(int start, int dest)
{
    return std::string();
}
