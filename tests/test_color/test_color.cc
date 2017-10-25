#include <iostream>
#include <map>

#include "../../topkek/values.h"
#include "../../topkek/utility.h"
#include "../../topkek/core.h"

#include <robot_instr.h>
#include <robot_link.h>

#define ROBOT_NUM 16   // The id number

using namespace std;

robot_link rlink;      // datatype for the robot link
int current_position;
int linetracker;
std::map <std::pair <int, int>, std::string> pathMap;
int speed;
int diff;
int lastPosition;

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

    ColorValue whiteMean(127, 127, 127), yellowMean(127, 127, 0), multiMean(63, 63, 63);
    ColorValue res = readColor();
    int whiteErr = colorError(res, whiteMean);
    int yellowErr = colorError(res, yellowMean);
    int multiErr = colorError(res, multiMean);
    if (whiteErr < yellowErr && whiteErr < multiErr)
    {
        // White
    }
    else if (yellowErr < multiErr)
    {
        // Yellow
    }
    else
    {
        // Multi
    }

    return 0;
}
