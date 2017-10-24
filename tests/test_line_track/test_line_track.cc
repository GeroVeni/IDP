#include <iostream>
#include <stdio.h>

#include <robot_instr.h>
#include <robot_link.h>
#include <robot_delay.h>

#include "core.h"
#include "utility.h"
#include <map>

#include <stopwatch.h>

#define ROBOT_NUM 16   // The id number
robot_link rlink;
int speed = 120 + 128;
int diff = 20;
int sit = 10;
int lastPosition = 10;
int current_position;
int linetracker;
char direction;
std::map <std::pair<int, int>, std::string> pathMap;

using namespace std;


void test_junc()
{
	int ok =1;
	rlink.command(MOTOR_3_GO, speed );
	rlink.command(MOTOR_4_GO, speed +128);
	delay(250);
	rlink.command(MOTOR_3_GO, speed -128);
	rlink.command(MOTOR_4_GO, speed -128);
	delay(700);
	while (ok==1)
	{
		int v=rlink.request (READ_PORT_0);
		int rightSensor = v & 2;
		printf("junction : %d\n", rightSensor);
		rlink.command(MOTOR_3_GO, speed -128);
		rlink.command(MOTOR_4_GO, speed -128);
		delay(5);
		if(rightSensor != 0)
			ok =0;
		
	}
	
}

int main ()
{
    // Setup the link
    #ifdef __arm__
    if (!rlink.initialise("127.0.0.1"))
    #else
    if (!rlink.initialise(ROBOT_NUM))
    #endif
    {
        cout << "Cannot initialise link" << endl;
        rlink.print_errs("  ");
        return -1;
    }
	
    while(1)
    {
		if (sit != 0)
			lastPosition = sit;
		int v=rlink.request (READ_PORT_0);
		int leftSensor = v & 4;
		int midSensor = v & 2;
		int rightSensor = v & 1;
		
		//printf("%d %d %d \n", (bool)leftSensor, (bool)midSensor, (bool)rightSensor);
		
		bool s1 = leftSensor, s2 = midSensor, s3 = rightSensor;
		sit = s1 * 100 + s2 * 10 + s3;
		printf("sit : %d\n", sit);
		
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
			//FailSafe();
			break;
		case 111:         //  1    1    1
			printf("Junction\n");
			test_junc();
			break;
		}
	}
	

    return 0;
}
