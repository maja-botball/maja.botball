/*
 * SUMMARY: This tests the movement
 *          of the Lego and Create robots.
 *
 * Which robot(s) the functions are for: Lego and Create.
 *
 * What the functions in this file do:
 *   -- Tests the movement of the robot (Lego or Create):
 *         forward, backward, left, right.
 *
 * Major functions in the file:
 *   -- test_robot
 *
 * Authors: Saayeh Siahmakoun, Hannah Close,
 *          Caaveh Siahmakoun and Stephen Cornwell.
 *
 * When written: March 27 and following, 2012.
*/

/*
 * TODO:
 *   1. Finish the   test_robot_forward_backward   function.
 *         Test it using the    test_create_movement.c   file.
 *   2. Ditto the   test_robot_left_right   function,
 *         fixing it as per   forward_backward.
 */

#include "library_both.c"
#include "time.h"

#define FORWARD 0
#define BACKWARD 1
#define LEFT 2
#define RIGHT 3

void test_robot(int speed, int centimeters, int direction);

void test_robot_forward(int speed, int centimeters);
void test_robot_backward(int speed, int centimeters);
void test_robot_left(int speed, int degrees);
void test_robot_right(int speed, int degrees);

void test_forward_backward_speed(int speed);
void test_left_right_speed(int speed);

void test_robot_forward_backward();
void test_robot_left_right();

// General-purpose function for testing movement.
void test_robot(int speed, int distance, int direction)
{
	clock_t start, end;
	float seconds;
	
	printf("Requested speed, distance = %3d %3d.\n",
		speed, distance);
	printf("Press the B button to continue.\n");
	while (b_button() == 0);
	while (b_button() == 1);
	sleep(1.0);
	
	start = clock();
	
	if (direction == FORWARD)
	{
		forward(speed, distance);
	}
	else if (direction == BACKWARD)
	{
		backward(speed, distance);
	}
	else if (direction == LEFT)
	{
		left(speed, distance);
	}
	else if (direction == RIGHT)
	{
		right(speed, distance);
	}
	
	end = clock();
	
	seconds = (end - start) / (float) CLOCKS_PER_SEC;
	//seconds = seconds * 15.0 / 11.0; // CBC CLOCKS_PER_TICK is wrong, it seems
	
	printf("This motion took %0.2f seconds.\n", seconds);
}

// A series of tests for forward and backward movement.
void test_robot_forward_backward()
{
	test_robot_forward(FAST, 50);
	test_robot_backward(FAST, 50);
	// TODO: Finish this.  Then delete test_robot.
}

// A series of tests for turns (left, right).
void test_robot_left_right()
{
	left(FAST, 90);
	sleep(5.0);
	right(FAST, 90);
	sleep(5.0);
}

void test_robot_forward(int speed, int centimeters)
{
	test_robot(speed, centimeters, FORWARD);
}

void test_robot_backward(int speed, int centimeters)
{
	test_robot(speed, centimeters, BACKWARD);
}

void test_robot_left(int speed, int degrees)
{
	test_robot(speed, degrees, LEFT);
}

void test_robot_right(int speed, int degrees)
{
	test_robot(speed, degrees, RIGHT);
}

void test_forward_backward_speed(int speed)
{
	int centimeters;
	centimeters = 50;
	
	printf("Forward/backward %d cm at speed %d.\n",
		centimeters, speed);
	
	test_robot_forward(speed, centimeters);
	test_robot_backward(speed, centimeters);
}

void test_left_right_speed(int speed)
{
	int degrees;
	degrees = 90;
	
	printf("Left/right %d degrees at speed %d.\n",
		degrees, speed);
	
	test_robot_left(speed, degrees);
	test_robot_right(speed, degrees);
}

