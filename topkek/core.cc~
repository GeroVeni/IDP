#include "core.h"
#include "utility.h"
#include "values.h"
#include <map>
#include <stdio.h>
#include <string>

extern int speed;
extern std::map<std::pair<int, int>, std::string> pathMap;
extern int current_position;

void Initialise()
    // Initiallises variables and sets up connection
{
	PathLoader();
	
    // Reach starting point
    // TODO

    // Set position to zero
    // TODO
}

void LineTracking(int dest)
    // Follows the white line until dest is reached
{
    static SensorValues prevValues = SensorValues();
    static int prevSit = 0;
	std::string path = pathMap[std::make_pair(current_position, dest)];
	int next_instruction = 0;
    //0 or 1 reading from the light sensors, sit is a 
	// int s1 = 0, s2 = 0, s3 = 0, sit = s1 * 100 + s2 * 10 + s3;
    

	while (linetracker == 1)
	{
        // Read sensor values
        SensorValues values = readSensors();
        int sit = 100 * values.left() + 10 * values.mid() + 1 * values.right();
        printf("Loop\n");

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
			JunctionMode(path[next_instruction]); // direction = 0 or 128 repending on whether the robot has to turn left or right. Don't know the exact declaration or variables yet because we didn't implement the hardcoding of the path //SUBJECT TO CHANGE
			next_instruction ++;
			break;
		}
	}
}

void ArmMove(ArmType type)
    // Moves the mechanical arm
{
    if (type == PICK)
    {
        // Pick ball
    }
    else
    {
        // Drop ball
    }
}

int Identify()
    // Identifies the type of the ball picked up - returns 0 if none found
{
	return 0;
}
