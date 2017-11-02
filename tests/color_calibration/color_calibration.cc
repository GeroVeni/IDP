#include <iostream>
#include <stdio.h>
#include <map>

#include "../../topkek/values.h"
#include "../../topkek/utility.h"
#include "../../topkek/core.h"

#include <robot_instr.h>
#include <robot_link.h>
#include <robot_delay.h>

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
    
    rlink.command(WRITE_PORT_0, 0x0f);
	rlink.command(WRITE_PORT_1, 0x08);

    while (1)
    {
		printf("Write a random integer: ");
		int a;
		scanf("%d", &a);
		int sumv = 0;
		int reps = 10;
		
		// Read blue component
		rlink.command(WRITE_PORT_1, 6);
		for (int i = 0 ; i < reps ; ++i)
		{
			delay(500);
			int v = rlink.request(ADC0);
			//~ printf("%d\n", v);
			sumv += v;
		}
		int blue = sumv / reps;
		
		// Read green component
		sumv = 0;
		rlink.command(WRITE_PORT_1, 5);
		for (int i = 0 ; i < reps ; ++i)
		{
			delay(500);
			int v = rlink.request(ADC0);
			//~ printf("%d\n", v);
			sumv += v;
		}
		int green = sumv / reps;
		
		// Read red component
		sumv = 0;
		rlink.command(WRITE_PORT_1, 3);
		for (int i = 0 ; i < reps ; ++i)
		{
			delay(500);
			int v = rlink.request(ADC0);
			//~ printf("%d\n", v);
			sumv += v;
		}
		int red = sumv / reps;
		
		printf("%d, %d, %d\n", red, green, blue);
	}
	
    return 0;
}

 
