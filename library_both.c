/*
 * SUMMARY: This is a library file that applies
 *          to BOTH the Lego and Create robots.
 *          It contains 
 *            -- movement commands.
 
 * Which robot(s) the functions are for: Lego and Create.
 *
 * What the functions in this file do:
 *   -- Moves the robot (Lego or Create):
 *         forward, backward, left, right.
 *
 * Major functions in the file:
 *   -- forward
 *   -- backward
 *   -- left
 *   -- right
 *
 * Authors: Saayeh Siahmakoun, Hannah Close,
 *          Caaveh Siahmakoun and Stephen Cornwell.
 *
 * When written: March 27 and following, 2012.
*/

/*
 * TODO:
 *   1. Incorporate the set_speeds function into
 *         initialize_lego and initialize_create functions.
 *   2. Add functions for arms, etc.
 *   3. Add other functions as needed.
 */
 
#define FALSE 0
#define TRUE 1

#define SUCCESS 0
#define FAILURE 1

#define LEGO_ROBOT 0
#define CREATE_ROBOT 1

int ROBOT;

int FAST;
int MEDIUM;
int SLOW;

int TURN_FAST;
int TURN_MEDIUM;
int TURN_SLOW;

#include "library_lego.c"
#include "library_create.c"

void forward(int speed, int centimeters);
void backward(int speed, int centimeters);
void left(int speed, int degrees);
void right(int speed, int degrees);

void set_speeds();  // TODO: Incorporate this into initialize_lego and initialize_create

/*
 * forward(speeed, centimeters):
 *   -- Moves the robot FORWARD the given distance in centimeters)
 *        at the given speed (in centimeters / second).
 * 
 * Speed and distance must be non-negative integers.
 
 * The   ROBOT   variable determines whether this is the Lego
 *   or Create robot.
 */
void forward(int speed, int centimeters)
{
	if (ROBOT == LEGO_ROBOT)
	{
		lego_forward(speed, centimeters);
	}
	else if (ROBOT == CREATE_ROBOT)
	{
		create_forward(speed, centimeters);
	}
	else
	{
		printf("ERROR:\n");
		printf("The ROBOT must be LEGO_ROBOT or CREATE_ROBOT.\n");
	}
}

/*
 * backward(speeed, centimeters):
 *   -- Moves the robot BACKWARD the given distance in centimeters)
 *        at the given speed (in centimeters / second).
 * 
 * Speed and distance must be non-negative integers.
 
 * The   ROBOT   variable determines whether this is the Lego
 *   or Create robot.
 */
void backward(int speed, int centimeters)
{
	if (ROBOT == LEGO_ROBOT)
	{
		lego_backward(speed, centimeters);
	}
	else if (ROBOT == CREATE_ROBOT)
	{
		create_backward(speed, centimeters);
	}
	else
	{
		printf("ERROR:\n");
		printf("The ROBOT must be LEGO_ROBOT or CREATE_ROBOT.\n");
	}
}

/*
 * left(speeed, degrees):
 *   -- Moves the robot FORWARD the given distance in centimeters)
 *        at the given speed (in centimeters / second).
 * 
 * Speed and distance must be non-negative integers.
 
 * The   ROBOT   variable determines whether this is the Lego
 *   or Create robot.
 */
void left(int speed, int degrees)
{
	if (ROBOT == LEGO_ROBOT)
	{
		lego_left(speed, degrees);
	}
	else if (ROBOT == CREATE_ROBOT)
	{
		create_left(speed, degrees);
	}
	else
	{
		printf("ERROR:\n");
		printf("The ROBOT must be LEGO_ROBOT or CREATE_ROBOT.\n");
	}
}

/*
 * right(speeed, degrees):
 *   -- Moves the robot FORWARD the given distance in centimeters)
 *        at the given speed (in centimeters / second).
 * 
 * Speed and distance must be non-negative integers.
 
 * The   ROBOT   variable determines whether this is the Lego
 *   or Create robot.
 */
void right(int speed, int degrees)
{
	if (ROBOT == LEGO_ROBOT)
	{
		lego_right(speed, degrees);
	}
	else if (ROBOT == CREATE_ROBOT)
	{
		create_right(speed, degrees);
	}
	else
	{
		printf("ERROR:\n");
		printf("The ROBOT must be LEGO_ROBOT or CREATE_ROBOT.\n");
	}
}

void set_speeds()
{
if (ROBOT == LEGO_ROBOT)
	{
		FAST = LEGO_FAST;
		MEDIUM = LEGO_MEDIUM;
		SLOW = LEGO_SLOW;
		
		//TURN_FAST;
		//TURN_MEDIUM;
		//TURN_SLOW;
	}
	else if (ROBOT == CREATE_ROBOT)
	{
		FAST = CREATE_FAST;
		MEDIUM = CREATE_MEDIUM;
		SLOW = CREATE_SLOW;
		
		TURN_FAST = CREATE_TURN_FAST;
		TURN_MEDIUM = CREATE_TURN_MEDIUM;
		TURN_SLOW = CREATE_TURN_SLOW;
	}
	else
	{
		printf("ERROR:\n");
		printf("The ROBOT must be LEGO_ROBOT or CREATE_ROBOT.\n");
	}		
}
