// The main loop of the system

#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
#include "utility.h"
#include "values.h"
#include "core.h"
#include <stopwatch.h>
#include <robot_delay.h>
#include <robot_instr.h>
#include <robot_link.h>

// Global variables declaration
robot_link rlink;
int current_position;	// The current position of the robot
int speed = 80+128;		// Current speed of robot
int linetracker = 1;	// linetracker turns to 0 to input next map instruction
char direction = 'f';	// Turn direction
std::map <std::pair<int, int>, std::string> pathMap;	// The container of the path directions
int diff = 20;
int lastPosition = 10;
int etime;

stopwatch watch;

// Unused
std::vector <MotorValues> motorHistory;
std::vector <SensorValues> sensorHistory;

int main ()
{
	printf("Starting ...\n");
	watch.start();
	
	Initialise();
	for (int ball = 1; ball <= 6; ball++)
	{
		LineTracking(ball); // updates current_position to ball position after movement
		ArmMove(PICK);
		int type = Identify();
		int drop_position = DropPosition(type);
		LineTracking(drop_position);
		ArmMove(DROP);
		int etime = watch.read();
		if (ball > 2 && etime > 3.5 * 60 * 1000)
		{
			LineTracking(S);
			break;
		}
	}

	printf("DONE!\n");
	return 0;
}
