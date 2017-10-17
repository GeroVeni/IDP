// The main loop of the system

#include <iostream>
#include <stdio.h>
#include <map>
#include "utility.h"
#include "core.h"

// Global variables declaration
int current_position;	// The current position of the robot
std::map <std::pair<int, int>, std::string> pathMap;

int main ()
{
	Initialise(); // sets pos to 0
	for (int ball = 1; ball <= 6; ball++)
	{
		LineTracking(ball); // updates current_position to ball position after movement
		ArmMove(PICK);
		int type = Identify();
		int drop_position = DropPosition(type); // Drop_position also sends signals to LEDS for identification
		LineTracking(drop_position);
		ArmMove(DROP);
	}
	return 0;
}
