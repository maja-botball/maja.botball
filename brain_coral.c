/*
 * SUMMARY: This is the main function that will take the robot to the coral;
 * 
 *
 * Which robot(s) the functions are for: Create.
 *
 * What the function in this file do:
 *   -- Moves the Create robot:
 *         forward, backward, left, right.
 *
 * Major function in the file:
 *  -- test_coral
 *
 * Authors: Klayton Lawson
 *
 * When written: April 10 and following, 2012.
*/

void test_create_coral();

#include <stdio.h>
#include "library_both.c"

int main() 
{
	ROBOT = CREATE_ROBOT;
	create_connect();
	set_speeds();

	
	test_create_coral();
	return 0;
}


void test_create_coral() {
	forward(MEDIUM, 71);
	left(TURN_MEDIUM, 90);
	forward(MEDIUM, 66);
	left(TURN_MEDIUM, 90);
	forward(MEDIUM, 63);
	right(TURN_MEDIUM, 90);
	
	
}
