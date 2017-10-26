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

    ColorValue whiteMean(33, 33, 83), yellowMean(25, 22, 99), multiMean(16, 13, 35);
    ColorValue res = readColor();
    printf("R G B %d %d %d\n", res.R, res.G, res.B);
    int whiteErr = colorError(res, whiteMean);
    int yellowErr = colorError(res, yellowMean);
    int multiErr = colorError(res, multiMean);
    if (whiteErr < yellowErr && whiteErr < multiErr)
    {
        // White
        printf("White\n");
    }
    else if (yellowErr < multiErr)
    {
        // Yellow
        printf("Yellow\n");
    }
    else
    {
        // Multi
        printf("Multi\n");
    }
    
    rlink.command(WRITE_PORT_1, 6);
    
    for (int i = 0 ; i < 10 ; ++i)
    {
		rlink.command(WRITE_PORT_1, 6);
		delay(500);
		int v = rlink.request(ADC0);
		printf("%d\n", v);
	}

    return 0;
}
