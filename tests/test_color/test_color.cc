#include <iostream>

#include "values.h"
#include "utility.h"
#include "core.h"

#include <robot_instr.h>
#include <robot_link.h>

#define ROBOT_NUM 16   // The id number

using namespace std;

robot_link rlink;      // datatype for the robot link

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

	ColorValue white, yellow, multi;
    ColorValue res = readColor();
    

    return 0;
}
