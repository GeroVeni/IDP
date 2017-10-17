#ifndef __UTILITY_H__
#define __UTILITY_H__

class string;

enum Location
{
    S = 0,
    P1 = 1,
    P2 = 2,
    P3 = 3,
    P4 = 4,
    P5 = 5,
    P6 = 6,
    D1 = 7,
    D2 = 8,
    D3 = 9,
    DR1 = 10,
    DR2 = 11
}

int DropPosition(int);
string FindPath(int, int);

#endif // __UTILITY_H__
