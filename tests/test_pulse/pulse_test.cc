#include <iostream>
using namespace std;
#include <robot_instr.h>
#include <robot_link.h>
#include <robot_delay.h>
#define ROBOT_NUM 16   // The id number (see below)
robot_link rlink;      // datatype for the robot link

int main ()
{
int val;                              // data from microprocessor
if (!rlink.initialise (ROBOT_NUM)) { // setup the link
  cout << "Cannot initialise link" << endl;
  rlink.print_errs("  ");
  return -1;
}
val = rlink.request (TEST_INSTRUCTION); // send test instruction
if (val == TEST_INSTRUCTION_RESULT) {   // check result
  cout << "Test passed" << endl;                           // all OK, finish
}
else if (val == REQUEST_ERROR) {
  cout << "Fatal errors on link:" << endl;
  rlink.print_errs();
}
else
  cout << "Test failed (bad value returned)" << endl;
                     // error, finish

rlink.command(WRITE_PORT_5, 0xff);
delay(500);
rlink.command(WRITE_PORT_5, 0x00);
delay(500);
rlink.command(WRITE_PORT_5, 0xff);
delay(500);
rlink.command(WRITE_PORT_5, 0x00);
delay(500);
rlink.command(WRITE_PORT_5, 0xff);
delay(500);
rlink.command(WRITE_PORT_5, 0x00);
delay(500);
rlink.command(WRITE_PORT_5, 0xff);
delay(500);
rlink.command(WRITE_PORT_5, 0x00);
delay(500);
rlink.command(WRITE_PORT_5, 0xff);
delay(500);
rlink.command(WRITE_PORT_5, 0x00);
delay(500);
rlink.command(WRITE_PORT_5, 0xff);
delay(500);
rlink.command(WRITE_PORT_5, 0x00);
delay(500);


}
