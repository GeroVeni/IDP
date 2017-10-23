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
int speed = 100;	// Current speed of robot
int linetracker = 1;	// Helps with entering and exiting junctions
char direction = 'f';	// Turn direction
std::map <std::pair<int, int>, std::string> pathMap;	// The container of the path directions

std::vector <MotorValues> motorHistory;
std::vector <SensorValues> sensorHistory;

int main ()
{
	Initialise();
	for (int ball = 1; ball <= 6; ball++)
	{
		LineTracking(ball); // updates current_position to ball position after movement
		ArmMove(PICK);
		int type = Identify();
		int drop_position = DropPosition(type);
		LineTracking(drop_position);
		ArmMove(DROP);
	}
	return 0;
}
