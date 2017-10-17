#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <string>

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

int DropPosition(int);
std::string FindPath(int, int);

#endif // __UTILITY_H__
