/*
 * SUMMARY: This tests the SPEEDs
 *          of the Create robot:
 *          forward/backward and left/right.
 *
 * Which robot(s) the functions are for: Create.
 *
 * What the functions in this file do:
 *   -- Tests the speeds of the robot (Create):
 *         forward, backward, left, right.
 *
 * Major functions in the file:
 *   -- test_forward_backward_speeds
 *   -- test_left_right_speeeds
 *
 * Authors: Saayeh Siahmakoun, Hannah Close,
 *          Caaveh Siahmakoun and Stephen Cornwell.
 *
 * When written: March 27 and following, 2012.
*/

/*
 * TODO:
 *   1. Run this program.  As you do so, do the following
 *         for each pair of movements:
 *      a. The program prints how long it takes to do each movement.
 *            Note that number.
 *      b. Measure how far the robot moved.  For forward/backward,
 *            it should be 50 centimeters but the robot may overshoot.
 *      c. Compute the speed from the above, in centimeters / second.
 *      d. Note what speed NUMBER causes what actual SPEED.
 *
 *   2. From the above, figure out whether or not you need
 *         a SPEED_FACTOR to make the speed NUMBER match the actual SPEED.
 *         If so, incorporate that into the    library_create.c    file
 *         and test that it works right.
 *
 *   3. Determine the MAXIMUM speed attainable.  Record that speed
 *         at the appropriate place of the    library_create.c    file.
 *
 *   4. Set the FAST, MEDIUM and SLOW speeds appropriately
 *         in the    library_create.c    file, per the tests you just ran.
 *         Add other constants like  SLOWEST  and   FASTEST if you wish.
 *
 *   5. Uncomment the   find_maximum_left_right   function herein
 *         and repeat the above steps to find maximum TURNING speeds.
 *         These are in DEGREES per second.
 *         You may need to add some tests to further fine-tune
 *         to find the maximum TURN speed attainable.
 */

#include "test_movement.c"

void test_forward_backward_speeds();
void test_left_right_speeds();

int main() 
{
	ROBOT = CREATE_ROBOT;
	create_connect();
	set_speeds();
	create_full();
	
	test_forward_backward_speeds();
	
	// test_left_right_speeds();
	
	return SUCCESS;
}

void test_forward_backward_speeds()
{
	test_forward_backward_speed(5);
	test_forward_backward_speed(10);
	test_forward_backward_speed(20);
	test_forward_backward_speed(30);
	test_forward_backward_speed(40);
	test_forward_backward_speed(50);
	
	printf("The documentation suggests that the\n");
	printf("following tests will NOT be any faster\n");
	printf("that the one just concluded.\n");
	
	test_forward_backward_speed(60);
	test_forward_backward_speed(70);
	test_forward_backward_speed(100);
}

void test_left_right_speeds()
{
	// test_left_right_speed(5);
	test_left_right_speed(10);
	test_left_right_speed(20);
	test_left_right_speed(30);
	test_left_right_speed(40);
	test_left_right_speed(50);
	test_left_right_speed(60);
	test_left_right_speed(70);
	test_left_right_speed(80);
	test_left_right_speed(90);
	test_left_right_speed(120);
	test_left_right_speed(150);
	test_left_right_speed(180);
}
