/*
 * SUMMARY: This has the program to score the Tilapia.
 *
 * Which robot(s) the functions are for: Create.
 *
 * What the functions in this file do:
 *   -- XXX.
 *
 * Major functions in the file:
 *   -- tilapia
 *
 * Authors: Saayeh Siahmakoun, Hannah Close,
 *          Caaveh Siahmakoun and Stephen Cornwell.
 *
 * When written: March 27 and following, 2012.
*/

#include "library_both.c"

void tilapia();

int main()
{
	ROBOT = XXX;
	set_speeds();
	
	tilapia();
	
	return SUCCESS;
}

/*
 * tilapia():
 *   -- Scores the tilipia by: XXX.
 *
 */
void tilapia()
{
	forward(FAST, 147);
	sleep(2.5);
	backward(FAST, 12);
	left(MEDIUM,90);
	forward(FAST, 183);
	right(MEDIUM, 90);
	forward(FAST, 81);
}
