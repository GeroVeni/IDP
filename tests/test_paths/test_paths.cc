#include <iostream>

#include "../../topkek/core.h"
#include "../../topkek/utility.h"
#include "../../topkek/values.h"

#include <map>
#include <string>
#include <vector>

#define ROBOT_NUM 16   // The id number

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
	PathLoader();
	
    return 0;
}

