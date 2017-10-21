#include <iostream>
using namespace std;
#include <robot_instr.h>
#include <robot_link.h>
#include <robot_delay.h>
#define ROBOT_NUM 16   // The id number (see below)
robot_link rlink;      // datatype for the robot link

int main ()
{                             // data from microprocessor
cout<<"hello";
/*
if (!rlink.initialise ("127.0.0.1")) { // setup the link
  cout << "Cannot initialise link" << endl;
  rlink.print_errs("  ");
  return -1;
}
*/
if (!rlink.initialise (ROBOT_NUM)) { // setup the link
  cout << "Cannot initialise link" << endl;
  rlink.print_errs("  ");
  return -1;
}
else
//cout<<rlink.request (STATUS);
{
	
for(int i=0;i<=2;i++)
{
rlink.command(MOTOR_1_GO, 120); //red - BUSTED
rlink.command(MOTOR_2_GO, 50); // green
rlink.command(MOTOR_3_GO, 120); //blue
rlink.command(MOTOR_4_GO, 119+128); //yellow
//rlink.command(BOTH_MOTORS_GO_SAME, 60);
}
}
}
