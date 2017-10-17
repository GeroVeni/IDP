#include "core.h"
#include "utility.h"

<<<<<<< HEAD
extern int speed;

=======
// Initiallises variables and sets up connection
>>>>>>> 7d42f194412101c009cd9f2b4ad30cdd4ee10e7c
void Initialise()
{
    // Reach starting point
    // TODO

    // Set position to zero
    // TODO
}

// Follows the white line until dest is reached
void LineTracking(int dest)
{
	int s1 = 0, s2 = 0, s3 = 0, sit = s1 * 100 + s2 * 10 + s3; //0 or 1 reading from the light sensors, sit is a 

	while (linetracker == 1)
	{
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
			JunctionMode(direction); // direction = 0 or 128 repending on whether the robot has to turn left or right. Don't know the exact declaration or variables yet because we didn't implement the hardcoding of the path //SUBJECT TO CHANGE
			break;
		}
	}
}

// Moves the mechanical arm
void ArmMove(ArmType type)
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

// Identifies the type of the ball picked up - returns 0 if none found
int Identify()
{
	return 0;
}
