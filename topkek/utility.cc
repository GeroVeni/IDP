// Routine functions

#include "utility.h"
#include <string>

// Returns the appropriate drop-off point depending on the type of the ball
int DropPosition(int type)
{
    static nextDR = 1;
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
string FindPath(int start, int dest)
{

}
