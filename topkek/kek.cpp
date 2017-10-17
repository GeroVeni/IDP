// The main loop of the system

#include <iostream>
#include <stdio.h>
#include "utility.h"
#include "core.h"

int current_position;

// create enum for PICK and DROP

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
