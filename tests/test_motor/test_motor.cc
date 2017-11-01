#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <robot_instr.h>
#include <robot_link.h>
#include <robot_delay.h>

#include "../../topkek/values.h"
#include "../../topkek/utility.h"
#include "../../topkek/core.h"

#define ROBOT_NUM 16   // The id number (see below)

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

using namespace std;

int main ()
{                             // data from microprocessor
	if (!rlink.initialise ("127.0.0.1")) { // setup the link
		cout << "Cannot initialise link" << endl;
		rlink.print_errs("  ");
		return -1;
	}
	
	int a, b;
	while (1)
	{
		printf("Give values: ");
		scanf("%d %d", &a, &b);
		LeftMotor(a);
		RightMotor(b);
	}

	return 0;
}

