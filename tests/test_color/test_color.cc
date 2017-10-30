#include <iostream>
#include <stdio.h>
#include <map>

#include "../../topkek/values.h"
#include "../../topkek/utility.h"
#include "../../topkek/core.h"

#include <robot_instr.h>
#include <robot_link.h>
#include <robot_delay.h>

#define ROBOT_NUM 16   // The id number

using namespace std;

robot_link rlink;      // datatype for the robot link
int current_position;
int linetracker;
std::map <std::pair <int, int>, std::string> pathMap;
int speed;
int diff;
int lastPosition;

int main ()
{
    // Setup the link
    #ifdef __arm__
    if (!rlink.initialise("127.0.0.1"))
    #else
    if (!rlink.initialise(ROBOT_NUM))
    #endif
    {
        cout << "Cannot initialise link" << endl;
        rlink.print_errs("  ");
        return -1;
    }
    
    rlink.command(WRITE_PORT_0, 0xf0);

    ColorValue whiteMean(33, 33, 83);
    ColorValue yellow1Mean(23, 24, 52);
    ColorValue yellow2Mean(10, 18, 127);
    ColorValue multiMean(16, 13, 35);
    ColorValue res = readColor();
    printf("R G B %d %d %d\n", res.R, res.G, res.B);
    int whiteErr = colorError(res, whiteMean);
    int yellowErr1 = colorError(res, yellow1Mean);
    int yellowErr2 = colorError(res, yellow2Mean);
    int multiErr = colorError(res, multiMean);
    if (whiteErr < yellowErr1 && whiteErr < multiErr && whiteErr < yellowErr2)
    {
        // White
        printf("White\n");
    }
    else if (multiErr < yellowErr1 && multiErr < yellowErr2)
    {
        // Multi
        printf("Multi\n");
    }
    else if (yellowErr1 < yellowErr2)
    {
        // Yellow 1
        printf("Yellow 1\n");
    }
    else
    {
		// Yellow 2
		printf("Yellow 2\n");
	}

    return 0;
}

