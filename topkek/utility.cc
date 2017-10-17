// Routine functions

#include "utility.h"
#include <stdio.h>
#include <map>


#include <robot_instr.h>
#include <robot_link.h>
#include <robot_delay.h>

extern std::map <std::pair<int, int>, std::string> pathMap;
robot_link rlink;


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
{
	rlink.command(MOTOR_3_GO, speed);
	rlink.command(MOTOR_4_GO, speed-2 +128);
	delay(50);
}

void TurnLeft()
{
	int speed = 100;
	rlink.command(MOTOR_3_GO, speed - 2);
	rlink.command(MOTOR_4_GO, speed - 2 + 128);
	delay(50);
}


void TurnRight()
{
	int speed = 100;
	rlink.command(MOTOR_3_GO, speed);
	rlink.command(MOTOR_4_GO, speed + 128);
	delay(50);
}


void SharpLeft()
{
	int speed = 100;
	rlink.command(MOTOR_3_GO, speed -2);
	rlink.command(MOTOR_4_GO, speed + 128);
	delay(50);
}


void SharpRight()
{
	int speed = 100;
	rlink.command(MOTOR_3_GO, speed + 2);
	rlink.command(MOTOR_4_GO, speed - 4 + 128);
	delay(50);
}


void JunctionMode(int direction)
{
 /*code for junction
 when we think we exited a junction, we have to exit the main linetracking loop
 
 */
	int speed = 100;
	int junctionok = 1;
	rlink.command(MOTOR_3_GO, speed + direction);
	rlink.command(MOTOR_4_GO, speed - 2 + direction);
	delay(1800); // timed 90 degree turn to the left or to the right
	// Probably here would have a set of delays in order to record some sensor data at the end of the turn. Something like 
	/*
	delay(1500);
	*read sensor and append to sensor history*
	rlink.command(MOTOR_3_GO, speed + direction);
	rlink.command(MOTOR_4_GO, speed - 2 + direction);
	delay(100);
	*read sensor and append to sensor history*
	rlink.command(MOTOR_3_GO, speed + direction);
	rlink.command(MOTOR_4_GO, speed - 2 + direction);
	delay(100);
	*read sensor and append to sensor history*
	rlink.command(MOTOR_3_GO, speed + direction);
	rlink.command(MOTOR_4_GO, speed - 2 + direction);
	delay(100);
	*read sensor and append to sensor history*
	*/


	/*
	check if passed over a line

	*/
	linetracker = 0;
}


void FailSafe()
{
}
