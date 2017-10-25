// The main loop of the system

#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
#include "utility.h"
#include "values.h"
#include "core.h"

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
	printf("JJJ\n");
	Initialise();
	for (int ball = 1; ball <= 6; ball++)
	{
		printf("Start\n");
		LineTracking(ball); // updates current_position to ball position after movement
		printf("Here\n");
		ArmMove(PICK);
		int type = Identify();
		int drop_position = DropPosition(type);
		LineTracking(drop_position);
		ArmMove(DROP);
	}
	return 0;
}
