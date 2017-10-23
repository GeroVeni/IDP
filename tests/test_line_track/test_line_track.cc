#include <iostream>
#include <stdio.h>

#include <robot_instr.h>
#include <robot_link.h>
#include <robot_delay.h>

#include "../../topkek/core.h"
#include "../../topkek/utility.h"

#include <stopwatch.h>

#define ROBOT_NUM 16   // The id number
robot_link rlink;      // datatype for the robot link
int speed = 100;

using namespace std;
void Forward()
// Sets the motor speed to move forward
{
	rlink.command(MOTOR_3_GO, speed + 128);
	rlink.command(MOTOR_4_GO, speed-2 );
	delay(10);
}

void TurnLeft()
// Sets the motor speeds to turn left
{
	//int speed = 100;
	rlink.command(MOTOR_3_GO, speed + 128);
	rlink.command(MOTOR_4_GO, speed - 30 - 2);
	delay(10);
}


void TurnRight()
// Sets the motor speeds to turn right
{
	//int speed = 100;
	rlink.command(MOTOR_3_GO, speed - 30 + 128);
	rlink.command(MOTOR_4_GO, speed);
	delay(10);
}


void SharpLeft()
// Sets the motor speeds to sharply turn left
{
	//int speed = 100;
	rlink.command(MOTOR_3_GO, speed - 30 + 128);
	rlink.command(MOTOR_4_GO, speed + 10);
	delay(10);
}

void SharpRight()
// Sets the motor speeds to sharply turn right
{
	//int speed = 100;
	rlink.command(MOTOR_3_GO, speed + 2 + 10 + 128);
	rlink.command(MOTOR_4_GO, speed - 4 - 30);
	delay(10);
}

void test_junc()
{
	rlink.command(MOTOR_3_GO, speed);
	rlink.command(MOTOR_4_GO, speed-2 );
	delay(1500);
}	

std::string toBinary(int n)
{
	std::string r;
	while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
	return r;
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
    
    //~ rlink.command(WRITE_PORT_0, 0x0f);
	
    while(1)
    {
		int v=rlink.request (READ_PORT_0);
		//std::string res = toBinary(v);
		//~ int mask = 7;
		//~ v = v & mask;
		int leftSensor = v & 4;
		int midSensor = v & 2;
		int rightSensor = v & 1;
		printf("%d %d %d \n", (bool)leftSensor, (bool)midSensor, (bool)rightSensor);
		//~ delay(100);   
		bool s1 = leftSensor, s2 = midSensor, s3 = rightSensor;
		int sit = s1 * 100 + s2 * 10 + s3;
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
			//JunctionMode(path[next_instruction]); // direction = 0 or 128 repending on whether the robot has to turn left or right. Don't know the exact declaration or variables yet because we didn't implement the hardcoding of the path //SUBJECT TO CHANGE
			//next_instruction ++;
			printf("Junction\n");
			test_junc();
			break;
		}
	}
	

    return 0;
}
