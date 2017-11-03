// Routine functions

#include "utility.h"
#include "values.h"
#include <stdio.h>
#include <map>


#include <robot_instr.h>
#include <robot_delay.h>
#include <stopwatch.h>

extern std::map <std::pair<int, int>, std::string> pathMap;
extern robot_link rlink;   // Global robot link
extern int current_position;
extern int diff;
extern int lastPosition;

void PathLoader()
    // Loads the paths.txt file
{
    int n;
    FILE * in = fopen("paths.txt", "r");
    fscanf(in, "%d", &n);
    int start, dest;
    char str[20];
    std::string path;
    pathMap.clear();
    for (int i = 0; i < n; i++)
    {
        fscanf(in, "%d %d %s", &start, &dest, str);
        pathMap[std::make_pair(start, dest)] = str;
    }
}

int DropPosition(int type)
    // Returns the appropriate drop-off point depending on the type of the ball
{
    // Set appropriate LED on
    // TODO

    // Always go for DR1 ? TODO

    // Returns destination
    static int nextDR = 1;
    if (type == 1) return D1;
    if (type == 3) return D2;
    if (type == 5) return D3;
    if (nextDR == 2)
    {
        nextDR--;
        return DR2;
    }
    nextDR++;
	return DR1;
}

int colorError(ColorValue col1, ColorValue col2)
{
	int dif1 = col1.R - col2.R;
	int dif2 = col1.G - col2.G;
	int dif3 = col1.B - col2.B;
	
	return dif1 * dif1 + dif2 * dif2 + dif3 * dif3;
}

MotorValues readMotors()
    // Reads the input from the motor and saves it into the motor history
{
    MotorValues res;

    // Read input
    // TODO Identify which motor is which
    res.right = rlink.request(MOTOR_3);
    res.left = rlink.request(MOTOR_4);

    // Save it into motor history
    // TODO
    
    return res;
}

SensorValues readSensors()
    // Reads the input from the sensors and saves it into the motor history
{
    SensorValues res;

    res.data = rlink.request(READ_PORT_0);

    // Save it into sensor history
    // TODO
    
    return res;
}

int readWeight()
{
    int val = rlink.request(READ_PORT_1);
    return val & (1 << 3);
}

ColorValue readColor()
{
	static int pause = 1000;
	ColorValue res;

	// Read blue color
	int temp = rlink.request(READ_PORT_1);
	rlink.command(WRITE_PORT_1, (temp | 6) & (~1));
	delay(pause);
	res.B = rlink.request(ADC0);

	// Read green color
	rlink.command(WRITE_PORT_1, (temp | 5) & (~2));
	delay(pause);
	res.G = rlink.request(ADC0);
	
	// Read red color
	rlink.command(WRITE_PORT_1, (temp | 3) & (~4));
	delay(pause);
	res.R = rlink.request(ADC0);

	//  Light LEDs to show color
	//  TODO
	
	return res;
}

void Forward()
    // Sets the motor speed to move forward
{
    rlink.command(MOTOR_3_GO, speed + 4);
    rlink.command(MOTOR_4_GO, speed + 128);
    delay(10);
}

void TurnLeft()
    // Sets the motor speeds to turn left
{
    rlink.command(MOTOR_3_GO, speed + 4);
    rlink.command(MOTOR_4_GO, speed + diff + 20 + 128);
    delay(10);
}


void TurnRight()
    // Sets the motor speeds to turn right
{
    rlink.command(MOTOR_3_GO, speed + 4 + diff + 20);
    rlink.command(MOTOR_4_GO, speed + 128);
    delay(10);
}


void SharpLeft()
    // Sets the motor speeds to sharply turn left
{
    rlink.command(MOTOR_3_GO, 0);
    rlink.command(MOTOR_4_GO, speed + 128);
    delay(10);
}

void SharpRight()
    // Sets the motor speeds to sharply turn right
{
    rlink.command(MOTOR_3_GO, speed);
    rlink.command(MOTOR_4_GO, 0);
    delay(10);
}

void JunctionMode(char direction)
    // Enters the junction mode
{
    /*code for junction
    when we think we exited a junction, we have to exit the main linetracking loop
    */
	switch (direction)
	{
		case 'f':
		{
			printf("Junction f\n");
			rlink.command(MOTOR_3_GO, speed );
			rlink.command(MOTOR_4_GO, speed + 128);
			delay(350); //go past the junction#
			break;
		}
		
		case 'l':
		{
			printf("Junction l\n");
			rlink.command(MOTOR_3_GO, speed);
			rlink.command(MOTOR_4_GO, speed + 128);
			delay(350);
			rlink.command(MOTOR_3_GO, speed - 128);
			rlink.command(MOTOR_4_GO, speed - 128);
			delay(1200);
			rlink.command(MOTOR_3_GO, speed - 128);
			rlink.command(MOTOR_4_GO, speed - 128);
			printf("Re-adjusting...\n");
			while (1)
			{
				int v = rlink.request(READ_PORT_0);
				int rightSensor = v & 2;
				//~ rlink.command(MOTOR_3_GO, speed - 128);
				//~ rlink.command(MOTOR_4_GO, speed - 128);
				delay(5);
				if (rightSensor != 0) break;
			}
			printf("Successful re-adjustment\n");
			break;
		}
		
		case 'r':
		{
			printf("Junction r\n");
			speed += 128;
			rlink.command(MOTOR_3_GO, speed);
			rlink.command(MOTOR_4_GO, speed + 128);
			delay(350);
			rlink.command(MOTOR_3_GO, speed - 128);
			rlink.command(MOTOR_4_GO, speed - 128);
			delay(1200);
			rlink.command(MOTOR_3_GO, speed - 128);
			rlink.command(MOTOR_4_GO, speed - 128);
			printf("Re-adjusting...\n");
			while (1)
			{
				int v = rlink.request(READ_PORT_0);
				int rightSensor = v & 2;
				printf("junction : %d\n", rightSensor);
				//~ rlink.command(MOTOR_3_GO, speed - 128);
				//~ rlink.command(MOTOR_4_GO, speed - 128);
				delay(5);
				if (rightSensor != 0) break;
			}
			printf("Successful re-adjustment\n");
			speed -= 128;
			break;
		}

		case 'T':
		{
			rlink.command(MOTOR_3_GO, speed + 128);
			rlink.command(MOTOR_4_GO, speed);
			delay(300);
			rlink.command(MOTOR_3_GO, 0);
			rlink.command(MOTOR_4_GO, 0);
			printf("Junction T\n");
			linetracker = 0; // reinitialised as 1 in the map track
			
			break;
		}
	}
}

void FailSafe()
    // Enters the failsafe mode
{
    switch (lastPosition)
    {
        case 10:
            Forward();
            break;
        case 100:
            SharpLeft();
            break;
        case 1:
            SharpRight();
            break;
    }
}
