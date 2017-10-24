// Routine functions

#include "utility.h"
#include <stdio.h>
#include <map>


#include <robot_instr.h>
#include <robot_delay.h>
#include <stopwatch.h>

extern std::map <std::pair<int, int>, std::string> pathMap;
extern robot_link rlink;   // Global robot link
extern int diff;
extern int lastPosition; // Records the last nonzero position of the robot

// Loads the paths.txt file
void PathLoader()
{
    int n;
    FILE * in = fopen("paths.txt", "r");
    fscanf(in, "%d", &n);
    int start, dest;
    char str[20];
    std::string path;
    pathMap.clear();
    for (int i = 0; i < n; i++)
    {
        fscanf(in, "%d %d %s", &start, &dest, str);
        pathMap[std::make_pair(start, dest)] = str;
    }
}

// Returns the appropriate drop-off point depending on the type of the ball
int DropPosition(int type)
{
    // Set appropriate LED on
    // TODO

    // Returns destination
    static int nextDR = 1;
    if (type == 1) return D1;
    if (type == 3) return D2;
    if (type == 5) return D3;
    if (nextDR == 2)
    {
        nextDR--;
        return DR2;
    }
    nextDR++;
	return DR1;
}

void Forward()
// Sets the motor speed to move forward
{
	rlink.command(MOTOR_3_GO, speed);
	rlink.command(MOTOR_4_GO, speed +128);
	delay(10);
}

void TurnLeft()
// Sets the motor speeds to turn left
{
	//int speed = 100;
	rlink.command(MOTOR_3_GO, speed - diff);
	rlink.command(MOTOR_4_GO, speed + 128);
	delay(10);
}


void TurnRight()
// Sets the motor speeds to turn right
{
	//int speed = 100;
	rlink.command(MOTOR_3_GO, speed );
	rlink.command(MOTOR_4_GO, speed -diff + 128);
	delay(10);
}


void SharpLeft()
// Sets the motor speeds to sharply turn left
{
	//int speed = 100;
	rlink.command(MOTOR_3_GO, speed -diff/2);
	rlink.command(MOTOR_4_GO, speed  + 3*diff + 128);
	delay(10);
}

void SharpRight()
// Sets the motor speeds to sharply turn right
{
	//int speed = 100;
	rlink.command(MOTOR_3_GO, speed + 3*diff);
	rlink.command(MOTOR_4_GO, speed - diff/2 + 128);
	delay(10);
}


void JunctionMode(char direction)
// Enters the junction mode
{
 /*code for junction
 when we think we exited a junction, we have to exit the main linetracking loop
 
 */
	return; //for testing purposes
	switch (direction)
	{
		case 'f':
		{
			rlink.command(MOTOR_3_GO, speed + 128);
			rlink.command(MOTOR_4_GO, speed - 2);
			delay(1000); // timed 90 degree turn to the left or to the right
		}
		
		case 'l':
		{
			rlink.command(MOTOR_3_GO, speed + 128);
			rlink.command(MOTOR_4_GO, speed - 2 + 128);
			delay(1800); // timed 90 degree turn to the left or to the right
		}
		
		case 'r':
		{
			rlink.command(MOTOR_3_GO, speed);
			rlink.command(MOTOR_4_GO, speed - 2);
			delay(1800); // timed 90 degree turn to the left or to the right
		}
	}
	
	linetracker = 0; // reinitialised as 1 in the map track 
}


void FailSafe()
// Enters the failsafe mode
{
	switch (lastPosition)
	{
		case 10:
			Forward();
			break;
		case 100:
			SharpLeft();
			break;
		case 1:
			SharpRight();
			break;
	}
}
