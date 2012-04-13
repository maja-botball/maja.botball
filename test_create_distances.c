/*
 * SUMMARY: This tests the DISTANCEs achieved by
 *          the Create robot:
 *          forward/backward and left/right.
 *
 * Which robot(s) the functions are for: Create.
 *
 * What the functions in this file do:
 *   -- Tests the distances achieved by the robot (Create):
 *         forward, backward, left, right.
 *
 * Major functions in the file:
 *   -- test_modest_forward_backward
 *   -- test_modest_left_right
 *
 * Authors: Saayeh Siahmakoun, Hannah Close,
 *          Caaveh Siahmakoun and Stephen Cornwell.
 *
 * When written: March 27 and following, 2012.
*/

/*
 * TODO:
 *   1. Run this program to test a modest distance at a modest speed.
 *          For each movement, determine the accuracy:
 *             -- What distance (in cm) was requested?
 *             -- What distance did the robot report that it went?
 *             -- What distance did the robot actually move?  (Measure it!)
 *      Tell David your results.  If the latter two distances are more than
 *         a centimeter or so from the requested distance,
 *         probably we should do something about it.
 *   2. Comment out the the call to the test that you just did
 *         (that is, the call to test_modest_forward_backward).
 *         Uncomment the next call (to test_modest_left_right).
 *         Repeat the previous step for this call.
 *
 *   CHECK WITH DAVID BEFORE CONTINUING.
 *
 *   3. Get the SPEEDS right by using the     test_create_speeds    file.
 *
 *   4. Back here, uncomment the   test_robot_forward_backward    function call.
 *         Run the program.  As you do so, record the REQUESTED distance
 *         and the ACTUAL distance for each movement.  Get that information
 *         into the     library_create.c     file at an appropriate place.
 *   5. Uncomment the   test_robot_left_right   function herein
 *         and repeat the previous step for TURNS.
 */

#include "test_movement.c"

void test_modest_forward_backward();
void test_modest_left_right();

int main() 
{
	ROBOT = CREATE_ROBOT;
	create_connect();
	set_speeds();
	create_full();
	
	// test_modest_forward_backward();
	test_modest_left_right();
	
	return SUCCESS;
}

// Test a modest distance forward/backward at a modest speed.
void test_modest_forward_backward()
{
	// test_robot(10, 50, FORWARD);
	test_robot(10, 50, BACKWARD);
	
	//test_robot(10, 30, FORWARD);
	//test_robot( 5, 20, BACKWARD);
}

void test_modest_left_right()
{
	test_robot(30, 90, LEFT);
	//test_robot(30, 90, RIGHT);
	
	//test_robot(20, 90, LEFT);
	//test_robot(10, 22, RIGHT);
}
