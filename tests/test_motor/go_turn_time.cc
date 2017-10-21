#include <iostream>
using namespace std;
#include <robot_instr.h>
#include <robot_link.h>
#include <robot_delay.h>
#include <stopwatch.h>
#define ROBOT_NUM 16   // The id number (see below)
robot_link rlink;      // datatype for the robot link
stopwatch watch;

int main ()
{ 
	if (!rlink.initialise (ROBOT_NUM)) 
	{ // setup the link
		cout << "Cannot initialise link" << endl;
		rlink.print_errs("  ");
		return -1;
	}
	else
	{
		for (int i = 1;i<=4;i++)
		{
		rlink.command(MOTOR_3_GO, 120+128);
		rlink.command(MOTOR_4_GO, 121); 
		delay(4000); //forwards
		
		rlink.command(MOTOR_3_GO, 100+128);
		rlink.command(MOTOR_4_GO, 100+128);
		delay(1580); // turn
		
	}
	rlink.command(MOTOR_3_GO, 120+128);
		rlink.command(MOTOR_4_GO, 121
		); 
		delay(3000); //forwards

	}
}
