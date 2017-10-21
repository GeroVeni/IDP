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
	int val;                              // data from microprocessor
	
	if (!rlink.initialise ("127.0.0.1")) // setup the link
	{
		cout << "Cannot initialise link" << endl;
		rlink.print_errs("  ");
		return -1;
	}
	//~ val = rlink.request (TEST_INSTRUCTION); // send test instruction
	//~ if (val == TEST_INSTRUCTION_RESULT)   // check result
	//~ {
		//~ cout << "Test passed" << endl;
		//~ return 0;                            // all OK, finish
	//~ }
	//~ else if (val == REQUEST_ERROR)
	//~ {
		//~ cout << "Fatal errors on link:" << endl;
		//~ rlink.print_errs();
	//~ }
	//~ else
		//~ cout << "Test failed (bad value returned)" << endl;
	
	//~ return -1;                          // error, finish
	
	val = rlink.request(TEST_INSTRUCTION);
	if ( val == TEST_INSTRUCTION_RESULT ) printf("Passed\n");
	else printf("Failed\n");
	
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
