#include <iostream>
#include <stdio.h>

#include <robot_instr.h>
#include <robot_link.h>
#include <stopwatch.h>

#include <map>
#include <string>
#include <vector>

#include "../../topkek/utility.h"
#include "../../topkek/values.h"

#define ROBOT_NUM 16   // The id number

using namespace std;

robot_link rlink;      // datatype for the robot link
stopwatch wt;


// Global variables declaration
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

	rlink.command(RAMP_TIME, 0);

	rlink.command(MOTOR_3_GO, 100 + 128);
	rlink.command(MOTOR_4_GO, 100);
	while(1)
	{
		SensorValues res = readSensors();
		printf("res %d\n", res.data);
		if (((res.data) & 7) == 7)
		{
			rlink.command(MOTOR_3_GO, 0);
			rlink.command(MOTOR_4_GO, 0);
			wt.start();
			break;
		}
	}
	
	while (rlink.request(MOTOR_3) || rlink.request(MOTOR_4)) {}
	int val = wt.read();
	printf("Time = %d\n", val);

    return 0;
}

