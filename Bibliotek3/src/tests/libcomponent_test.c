/**********************************************************
 *
 *	libcomponent_test.c
 *
 *	Author: Henrik Söderlund
 *	Date:   2018
 *	
 *	This file is used as a part of a test suite of
 *	a library to compute at most three equivalent
 *	resistancesfrom the e12 series based on a given
 *	resistance.
 *
 *********************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "../libcomponent.h"

int main(int argc, char *argv[])
{
	// Set default resistance.
	float test_resistance = 4700;
	
	// Take in program args.
	if (argc == 2)
		test_resistance = atoi(argv[1]);
		
	// Allocate dummy memory so compiler doesn't complain,
	// it will be freed in function e_resistance anyways.
	float* res_array = (float*) malloc(3*sizeof(float));

	// Compute equivalent e12 series resistances.
	int count = e_resistance(test_resistance,  res_array);
	
	// Print results.
	printf("Count:\t%d\n", count);
	for (int i = 0; i < numEquivalent; i++)
		printf("Equiv. resistance %d:\t%f\n", i+1, res_array[i]);

	// Free memory.
	free(res_array);
	return 0;
}	
