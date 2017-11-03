#include <iostream>
#include <stdio.h>

#define ROBOT_NUM 16   // The id number
#include <robot_instr.h>
#include <robot_link.h>

#include "../../topkek/utility.h"
#include "../../topkek/values.h"

#include <vector>
#include <map>


using namespace std;

// Global variables declaration
robot_link rlink;
int current_position;	// The current position of the robot
int speed = 100;		// Current speed of robot
int linetracker = 1;	// linetracker turns to 0 to input next map instruction
char direction = 'f';	// Turn direction
std::map <std::pair<int, int>, std::string> pathMap;	// The container of the path directions
int diff = 20;
int lastPosition = 10;

// Unused
std::vector <MotorValues> motorHistory;
std::vector <SensorValues> sensorHistory;

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

	while (1)
	{
		printf("port 0: %d\nport 1: %d\n\n", rlink.request(READ_PORT_0), rlink.request(READ_PORT_1));
	}
    return 0;
}
