#include "core.h"
#include "utility.h"
#include "values.h"

#include <robot_delay.h>
#include <iostream>

#include <map>
#include <stdio.h>
#include <string>

extern int speed;
extern robot_link rlink;
extern std::map<std::pair<int, int>, std::string> pathMap;
extern int current_position;

void Initialise()
    // Initiallises variables and sets up connection
{
	printf("Init\n");
	
	PathLoader();
	printf("PathloaderOK\n");
	// Setup the link
    #ifdef __arm__
    if (!rlink.initialise("127.0.0.1"))
    #else
    if (!rlink.initialise(ROBOT_NUM))
    #endif
    {
        std::cout << "Cannot initialise link" << std::endl;
        rlink.print_errs("  ");
        return;
    }
	printf("ConnectionOK\n");
	
	// Set input pins on
	rlink.command(WRITE_PORT_0, 0x0f);
	rlink.command(WRITE_PORT_1, 0x28);

	// Set ramp time to 0
	rlink.command(RAMP_TIME, 0);

	while (linetracker == 1)
	{
		// Read sensor values
		SensorValues values = readSensors();
		int sit = 100 * values.left() + 10 * values.mid() + 1 * values.right();
		printf("Sit: %d \n", sit);
		switch (sit)
		{
		case 10:          //  0    1    0
			Forward();
			break;
		case 11:          //  0    1    1
			TurnRight();
			break;
		case 110:         //  1    1    0
			TurnLeft();
			break;
		case 1:           //  0    0    1
			SharpRight();
			break;
		case 100:         //  1    0    0
			SharpLeft();
			break;
		case 0:           //  0    0    0
			FailSafe();
			break;
		case 111:         //  1    1    1
			printf("speed %d\n", speed);
			linetracker = 0;
			break;
		}
	}
	linetracker = 1;

    // Set position to zero
    current_position = S;
}

void LineTracking(int dest)
    // Follows the white line until dest is reached
{
	printf("Starting LineTracking\n");
    static int prevSit = 2;
	std::string path = pathMap[std::make_pair(current_position, dest)];
	printf("path %s\n", path.c_str());
	int next_instruction = 0;
    
	while (linetracker == 1)
	{
        // Read sensor values
        SensorValues values = readSensors();
        int sit = 100 * values.left() + 10 * values.mid() + 1 * values.right();
        if (sit == prevSit) continue;
        delay(5);

		switch (sit)
		{
		case 10:          //  0    1    0
			Forward();
			break;
		case 11:          //  0    1    1
			TurnRight();
			break;
		case 110:         //  1    1    0
			TurnLeft();
			break;
		case 1:           //  0    0    1
			SharpRight();
			break;
		case 100:         //  1    0    0
			SharpLeft();
			break;
		case 0:           //  0    0    0
			FailSafe();
			break;
		case 111:         //  1    1    1
			JunctionMode(path[next_instruction]);
			next_instruction ++;
			break;
		}
	}
	linetracker = 1; // Robot exits LineTracking so for next loop iteration we need linetracker = 1
	current_position = dest;
}

void ArmMove(ArmType type)
    // Moves the mechanical arm
{
    if (type == PICK)
    {
		int curr = rlink.request(READ_PORT_1);
		curr = curr | 0x10;
		rlink.command(WRITE_PORT_1, curr);
		delay(1000);
		curr = curr & (~0x20);
		rlink.command(WRITE_PORT_1, curr);
		delay(1000);
		curr = curr & (~0x10);
		rlink.command(WRITE_PORT_1, curr);
		delay(1000);
    }
    else
    {
        // Drop ball
		int curr = rlink.request(READ_PORT_1);
		curr = curr | 0x10;
		rlink.command(WRITE_PORT_1, curr);
		delay(1000);
		curr = curr | 0x20;
		rlink.command(WRITE_PORT_1, curr);
		delay(1000);
		curr = curr & (~0x10);
		rlink.command(WRITE_PORT_1, curr);
		delay(1000);
    }
}

int Identify()
	// Identifies the type of the ball picked up - returns 0 if none found
{
	const int colorCount = 5;
	ColorValue means[colorCount];
	std::string colorNames[colorCount];
	int colorId[colorCount];
	// White - 0
	// Yellow - 1
	// Multi - 2
	// Empty - -1
	means[0] = ColorValue(33, 33, 83);
	colorNames[0] = std::string("White");
	colorId[0] = 0;
	means[1] = ColorValue(23, 24, 52);
	colorNames[1] = std::string("Yellow 1");
	colorId[1] = 1;
	means[2] = ColorValue(10, 18, 127);
	colorNames[2] = std::string("Yellow 2");
	colorId[2] = 1;
	means[3] = ColorValue(16, 13, 35);
	colorNames[3] = std::string("Multi");
	colorId[3] = 2;
	means[4] = ColorValue(0, 0, 0);
	colorNames[4] = std::string("Empty");
	colorId[4] = 3;

	ColorValue res = readColor();

	int minErr = 3 * 255 * 255;
	int minPos = 0;
	for (int i = 0; i < colorCount; i++)
	{
		int err = colorError(res, means[i]);
		if (err < minErr)
		{
			minErr = err;
			minPos = i;
		}
	}

	printf("%s\n", colorNames[minPos].c_str());
	
	int out = 0;

	// DROP BALL IN WEIGHTING MECH
	// TODO

	int weight = rlink.request(READ_PORT_0);
	weight = weight & 0x08;
	if (weight) out = 0x80;
	switch (colorId[minPos])
	{
		case 0:
			// White
			out = out | 0x10;
			break;
		case 1:
			// Yellow
			out = out | 0x20;
			break;
		case 2:
			// Multi
			out = out | 0x40;
			break;
	}
	
	rlink.command(WRITE_PORT_0, ~out);
	return 5;
}

