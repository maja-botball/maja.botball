/*
 * SUMMARY: This is the library file for the Create robot.
 *          It contains all library functions specific to the Create robot:
 *            -- movement commands.
 *
 * Which robot(s) the functions are for: Create.
 *
 * What the functions in this file do:
 *   -- Moves the Create robot:
 *         forward, backward, left, right.
 *
 * Major functions in the file:
 *   -- create_forward
 *   -- create_backward
 *   -- create_left
 *   -- create_right
 *
 * Authors: Saayeh Siahmakoun, Hannah Close,
 *          Caaveh Siahmakoun and Stephen Cornwell.
 *
 * When written: March 27 and following, 2012.
*/

/*
 * TODO:
 *   For FORWARD:
 *   1. Measure to be sure the speed is in centimeters per second.
 *   2. Measure to be sure that distance is accurate.
 *      BUT: Decide if need an overshoot adjustment.
 *   3. Fill in the XXX with the maximum speed attainable.
 *   4. Make sure that LAG is OK.
 *
 *   Then repeat the above for BACKWARD.
 *   Then repeat the above for LEFT and RIGHT:
 *      -- In degrees and degrees per second.
 *      -- The conversion for TURNs has NOT been determined yet.
 *      -- TURNs may require a NON-linear conversion.
 *
 *   Then:
 *   5. Make a start_create function that connects to the create
 *      (with error control) and sets the speed constants
 *      and ... [ALSO fix LEGO speed constant initialization].
*/

#include <math.h>

#define	CREATE_FASTEST 50
#define CREATE_FAST 40 // TODO: Make sure these numbers are reasonable.
#define CREATE_MEDIUM 30
#define CREATE_SLOW 20
#define CREATE_SLOWEST 10

#define CREATE_TURN_MAX 150
#define CREATE_TURN_FASTEST 100
#define CREATE_TURN_FAST 80
#define CREATE_TURN_MEDIUM 65
#define CREATE_TURN_SLOW 50
#define CREATE_TURN_SLOWEST 30
#define CREATE_TURN_MIN 20

void create_forward(int speed, int centimeters);
void create_backward(int speed, int centimeters);
void create_left(int speed, int degrees);
void create_right (int speed, int degrees);

/*
 * create_forward(speeed, centimeters):
 *   -- Moves the Create robot FORWARD the given distance (in centimeters)
 *        at the given speed (in centimeters / second).
 * 
 * Speed and distance must be non-negative integers.
 * The maximum speed the robot can accomplish is about XXX.
 */
void create_forward(int speed, int centimeters)
{
	float mm_to_travel;
	int mm_travelled;
	int mm_per_second;
	float lag;
	
	mm_to_travel = centimeters * 10;
	mm_per_second = speed * 10;
	// lag = 5.0 / mm_per_second;
	lag = sqrt(mm_to_travel) / mm_per_second;
	if (lag < 0.01)
	{
		lag = 0.01;
	}
	printf("Lag is %0.3f\n", lag);
	
	mm_travelled = 0;
	set_create_distance(0);
	create_drive_straight(mm_per_second);
	
	while (TRUE)
	{
		mm_travelled = get_create_distance(lag);
		if (mm_travelled >= mm_to_travel) {
			break;
		}
	}
	
	create_stop();
	
	printf("Actual distance travelled: %0.1f centimeters.\n",
		mm_travelled / 10.0);
}

/*
 * create_backward(speeed, centimeters):
 *   -- Moves the Create robot BACKWARD the given distance (in centimeters)
 *        at the given speed (in centimeters / second).
 * 
 * Speed and distance must be non-negative integers.
 * The maximum speed the robot can accomplish is about XXX.
 *
 * The distance travelled is as reported by the LEFT motor.
 */
void create_backward(int speed, int centimeters)
{
	float mm_to_travel;
	int mm_travelled;
	int mm_per_second;
	float lag;
	
	mm_to_travel = centimeters * 10;
	mm_per_second = speed * 10;
	//lag = 5.0 / mm_per_second;
	lag = sqrt(mm_to_travel) / mm_per_second;
	if (lag < 0.01)
	{
		lag = 0.01;
	}
	printf("Lag is %0.3f\n", lag);
	
	mm_travelled = 0;
	set_create_distance(0);
	create_drive_straight(-mm_per_second);
	
	while (TRUE)
	{
		mm_travelled = -get_create_distance(lag);
		if (mm_travelled >= mm_to_travel) {
			break;
		}
	}
	create_stop();
	
	printf("Actual distance travelled: %0.1f centimeters.\n",
		mm_travelled / 10.0);
}

/*
 * create_left(speeed, degrees):
 *   -- Turns the Create robot LEFT (counterclockwise from above)
 *        the given distance (in degrees)
 *        at the given speed (in degrees / second).
 * 
 * Speed and degrees must be non-negative integers.
 * The maximum speed the robot can accomplish is about XXX.
 *
 * The distance travelled is as reported by the LEFT motor.
 */
void create_left(int speed, int degrees)
{
	int angle_to_travel;
	int angle_travelled;
	int angle_per_second;
	float lag;
	
	angle_to_travel = degrees;
	angle_per_second = speed;
	//lag = 40.0 / angle_per_second;
	//lag = 10;
	lag = sqrt(angle_to_travel) / angle_per_second;
	if (lag < 0.01)
	{
		lag = 0.01;
	}
	printf("Lag is %0.3f\n", lag);
	
	angle_travelled = 0;
	set_create_total_angle(0);
	create_spin_CCW(angle_per_second);
	
	while (TRUE)
	{
		angle_travelled = get_create_total_angle(lag);
		if (angle_travelled >= angle_to_travel) {
			break;
		}
	}
	
	create_stop();
	
	printf("Actual distance turned: %d degrees.\n",
		angle_travelled);
}

/*
 * create_right(speeed, degrees):
 *   -- Turns the Create robot RIGHT (clockwise from above)
 *        the given distance (in degrees)
 *        at the given speed (in degrees / second).
 * 
 * Speed and degrees must be non-negative integers.
 * The maximum speed the robot can accomplish is about XXX.
 *
 * The distance travelled is as reported by the LEFT motor.
 */
void create_right(int speed, int degrees)
{
	int angle_to_travel;
	int angle_travelled;
	int angle_per_second;
	float lag;
	
	angle_to_travel = degrees;
	angle_per_second = speed;
	//lag = 40.0 / angle_per_second;
	//lag = 10;
	lag = sqrt(angle_to_travel) / angle_per_second;
	if (lag < 0.01)
	{
		lag = 0.01;
	}
	printf("Lag is %0.3f\n", lag);
	
	angle_travelled = 0;
	set_create_total_angle(0);
	create_spin_CW(angle_per_second);
	
	while (TRUE)
	{
		angle_travelled = -get_create_total_angle(lag);
		if (angle_travelled >= angle_to_travel) {
			break;
		}
	}
	
	create_stop();
	
	printf("Actual distance turned: %d degrees.\n",
		angle_travelled);
}
