
#include <iostream>
using namespace std;
#include <robot_instr.h>
#include <robot_link.h>
#include <robot_delay.h>
#define ROBOT_NUM 16   // The id number (see below)
robot_link rlink;      // datatype for the robot link

request_instruction readPorts[] = {
	READ_PORT_0,
	READ_PORT_1,
	READ_PORT_2,
	READ_PORT_3,
	READ_PORT_4,
	READ_PORT_5,
	READ_PORT_6,
	READ_PORT_7
};

command_instruction writePorts[] = {
	WRITE_PORT_0,
	WRITE_PORT_1,
	WRITE_PORT_2,
	WRITE_PORT_3,
	WRITE_PORT_4,
	WRITE_PORT_5,
	WRITE_PORT_6,
	WRITE_PORT_7
};

int main ()
{                             // data from microprocessor
if (!rlink.initialise (ROBOT_NUM)) { // setup the link
  cout << "Cannot initialise link" << endl;
  rlink.print_errs("  ");
  return -1;
}
cout<<rlink.request (STATUS);
rlink.command(WRITE_PORT_7, 255);
while(1)
{
	//for (int i = 0; i < 8; ++i)
	//{
		//cout << "Port " << i << endl;
		////rlink.command(writePorts[i], 64+16+4+1);
		//if(int v=rlink.request (readPorts[i])
			//cout << "Value="  <<v << endl;
		//else
			//cout<<"Error in reading";
	//}
	//rlink.command(writePorts[i], 64+16+4+1);
	if(int v=rlink.request (READ_PORT_7))
		cout << "Value="  <<v << endl;
	else
		cout<<"Error in reading";
}
return 0;
}
