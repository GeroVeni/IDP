#include <iostream>
#include <stdio.h>
#include <map>
#include <string>

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

const int colorCount = 5;
ColorValue means[colorCount];
std::string colorNames[colorCount];

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

	means[0] = ColorValue(33, 33, 83);
	colorNames[0] = std::string("White");
	means[1] = ColorValue(23, 24, 52);
	colorNames[1] = std::string("Yellow 1");
	means[2] = ColorValue(10, 18, 127);
	colorNames[2] = std::string("Yellow 2");
	means[3] = ColorValue(16, 13, 35);
	colorNames[3] = std::string("Multi");
	means[4] = ColorValue(0, 0, 0);
	colorNames[4] = std::string("Empty");

    /*
	ColorValue whiteMean(33, 33, 83);
    ColorValue yellow1Mean(23, 24, 52);
    ColorValue yellow2Mean(10, 18, 127);
    ColorValue multiMean(16, 13, 35);
	*/

    ColorValue res = readColor();
    printf("R G B %d %d %d\n", res.R, res.G, res.B);
    
	int minErr = 3 * 255 * 255;
	int minPos = 0;
	for (int i = 0; i < colorCount; i++)
	{
		int err = colorError(res, means[i]);
		if (err < minErr)
		{
			minErr = err;
			minPos = i;
		}
	}

	printf("%s\n", colorNames[minPos].c_str());
	
	/*
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
	*/

    return 0;
}

