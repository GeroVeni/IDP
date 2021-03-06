#include <iostream>
#include <stdio.h>
using namespace std;
#include <robot_instr.h>
#include <robot_link.h>
#include <stopwatch.h>
#define ROBOT_NUM 16   // The id number (see below)
robot_link rlink;      // datatype for the robot link

stopwatch wt;
// 28 - workstation
// 2 - microproc
int main ()
{
	printf("Hello World!\n");
	int val;                              // data from microprocessor
	
	if (!rlink.initialise ("127.0.0.1")) // setup the link
	{
		cout << "Cannot initialise link" << endl;
		rlink.print_errs("  ");
		return -1;
	}
	
	wt.start();
	val = rlink.request(TEST_INSTRUCTION);
	if ( val == TEST_INSTRUCTION_RESULT ) printf("Passed\n");
	else printf("Failed\n");
	printf("Time : %d\n", wt.read());

	rlink.command(WRITE_PORT_0, 0x0f);
	int x = rlink.request(READ_PORT_0);
	cout<<x<<std::endl;
	
	
	wt.start();
	int COUNT = 100;
	for (int i=0; i < COUNT; i++)
	{
		val = rlink.request(TEST_INSTRUCTION);
	}
	int time = wt.read();
	printf("%d\n", time / COUNT);
	return 0;
}
