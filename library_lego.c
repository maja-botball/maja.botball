/*
 * SUMMARY: This is the library file for the Lego robot.
 *          It contains all library functions specific to the Lego robot:
 *            -- movement commands.
 *
 * Which robot(s) the functions are for: Lego.
 *
 * What the functions in this file do:
 *   -- Moves the Lego robot:
 *         forward, backward, left, right.
 *
 * Major functions in the file:
 *   -- lego_forward
 *   -- lego_backward
 *   -- lego_left
 *   -- lego_right
 *
 * Authors: Saayeh Siahmakoun, Hannah Close,
 *          Caaveh Siahmakoun and Stephen Cornwell.
 *
 * When written: March 27 and following, 2012.
*/

/*
 * TODO:
 *   For FORWARD:
 *   1. Make the speed be in centimeters per second.
 *   2. Decide whether to FREEZE or COAST.
 *   3. Make the robot go straight:
 *        -- Any remaining physical changes.
 *        -- Adjust speeds for veer:
 *             -- At full charge, at HIGH, MEDIUM and LOW speeds.
 *   4. Adjust the constant for CENTIMETERS_IN_ONE_ROTATION.
 *   5. Decide if need an overshoot adjustment.
 *   6. Fill in the XXX with the maximum speed attainable.
 *
 *   Then repeat the above for BACKWARD.
 *   Then repeat the above for LEFT and RIGHT:
 *      -- In degrees and degrees per second.
 *      -- The conversion for TURNs has NOT been determined yet.
 *      -- TURNs may require a NON-linear conversion.
*/

#define LEFT_MOTOR 0
#define RIGHT_MOTOR 3

#define LEGO_FAST 1000 // TODO: Change to cm / sec.
#define LEGO_MEDIUM 500 // TODO: Change to cm / sec.
#define LEGO_SLOW 200 // TODO: Change to cm / sec.

#define CENTIMETERS_IN_ONE_ROTATION 14.15
#define TICKS_PER_REVOLUTION 1100
#define TICKS_PER_DEGREE 15 // TODO: Determine this number

void lego_forward(int speed, int centimeters);
void lego_backward(int speed, int centimeters);
void lego_left(int speed, int degrees);
void lego_right (int speed, int degrees);

/*
 * lego_forward(speed, centimeters):
 *   -- Moves the Lego robot FORWARD the given distance (in centimeters)
 *        at the given speed (in centimeters / second).
 * 
 * Speed and centimeters must be non-negative integers.
 * The maximum speed the robot can accomplish is about XXX.
 *
 * The distance travelled is as reported by the LEFT motor.
*/
void lego_forward(int speed, int centimeters)
{
	float ticks_to_travel;
	int ticks_travelled;
	
	ticks_to_travel = (centimeters / CENTIMETERS_IN_ONE_ROTATION)
						* TICKS_PER_REVOLUTION;
	
	ticks_travelled = 0;
	clear_motor_position_counter(LEFT_MOTOR);
	
	mav(LEFT_MOTOR, speed);
	mav(RIGHT_MOTOR, speed);
	
	while (TRUE)
	{
		ticks_travelled = get_motor_position_counter(LEFT_MOTOR);
		if (ticks_travelled >= ticks_to_travel) {
			break;
		}
	}
	
	freeze(LEFT_MOTOR);
	freeze(RIGHT_MOTOR);
}

/*
 * lego_backward(speed, centimeters):
 *   -- Moves the Lego robot BACKWARD the given distance (in centimeters)
 *        at the given speed (in centimeters / second).
 * 
 * Speed and centimeters must be non-negative integers.
 * The maximum speed the robot can accomplish is about XXX.
 *
 * The distance travelled is as reported by the LEFT motor.
*/
void lego_backward(int speed, int centimeters)
{
	float ticks_to_travel;
	int ticks_travelled;
	
	ticks_to_travel = (centimeters / CENTIMETERS_IN_ONE_ROTATION)
						* TICKS_PER_REVOLUTION;
	
	ticks_travelled = 0;
	clear_motor_position_counter(LEFT_MOTOR);
	
	mav(LEFT_MOTOR, -speed);
	mav(RIGHT_MOTOR, -speed);
	
	while (TRUE)
	{
		ticks_travelled = -get_motor_position_counter(LEFT_MOTOR);
		if (ticks_travelled >= ticks_to_travel) {
			break;
		}
	}
	
	freeze(LEFT_MOTOR);
	freeze(RIGHT_MOTOR);
}

/*
 * lego_left(speed, degrees):
 *   -- Turns the Lego robot LEFT (counterclockwise from above)
 *        the given distance (in degrees)
 *        at the given speed (in degrees / second).
 * 
 * Speed and degrees must be non-negative integers.
 * The maximum speed the robot can accomplish is about XXX.
 *
 * The distance travelled is as reported by the LEFT motor.
*/
void lego_left(int speed, int degrees)
{
	int ticks_to_travel;
	int ticks_travelled;
	
	ticks_to_travel = degrees * TICKS_PER_DEGREE;
	
	ticks_travelled = 0;
	clear_motor_position_counter(RIGHT_MOTOR);
	
	mav(LEFT_MOTOR, speed);
	mav(RIGHT_MOTOR, -speed);
	
	while (TRUE)
	{
		ticks_travelled = get_motor_position_counter(RIGHT_MOTOR);
		if (ticks_travelled >= ticks_to_travel) {
			break;
		}
	}
	
	freeze(LEFT_MOTOR);
	freeze(RIGHT_MOTOR);
}

/*
 * lego_right(speed, degrees):
 *   -- Turns the Lego robot RIGHT (clockwise from above)
 *        the given distance (in degrees)
 *        at the given speed (in degrees / second).
 * 
 * Speed and degrees must be non-negative integers.
 * The maximum speed the robot can accomplish is about XXX.
 *
 * The distance travelled is as reported by the LEFT motor.
*/
void lego_right(int speed, int degrees)
{
	int ticks_to_travel;
	int ticks_travelled;
	
	ticks_to_travel = degrees * TICKS_PER_DEGREE;
	
	ticks_travelled = 0;
	clear_motor_position_counter(RIGHT_MOTOR);
	
	mav(LEFT_MOTOR, -speed);
	mav(RIGHT_MOTOR, speed);
	
	while (TRUE)
	{
		ticks_travelled = -get_motor_position_counter(RIGHT_MOTOR);
		if (ticks_travelled >= ticks_to_travel) {
			break;
		}
	}
	
	freeze(LEFT_MOTOR);
	freeze(RIGHT_MOTOR);
}




