/**********************************************************
 *
 *	libcomponent.c
 *
 *	Author: Henrik Söderlund
 *	Date:   2018
 *	
 *	This file is used as a part of a library used
 *	to compute at most three equivalent resistances
 *	from the e12 series based on a given resistance.
 *
 *********************************************************/

#include "libcomponent.h"

#include <stdio.h>

// toClosestPower10(num, power)
//
// input:  a value x and a power p
//
// output: a number that is x rounded to the closest
//         rounded number corresponding to the power
//         chosen.
int toClosestPower10(int num, int power)
{
    return (num * 10 / pow(10, power))*pow(10, power-1); 
}    

// numDigits(num)
//
// input: a value x
//
// output: number of digits in x
int numDigits(int num)
{    
    int digits = 0;
    while (num != 0) 
    {
        num /= 10;
        digits++;
    }
    return digits;
}

// e_resistance(orig_resistance, res_array)
//
// input: a resistance value and an empty pointer
//
// output: number of equivalent resistances needed and
//         also fills the pointer with the equivalent
//         resistances needed to get the original.
int e_resistance(int orig_resistance, int *res_array) {
	
	int resistance = orig_resistance;

	// Allocate memory for pointer.
	free(res_array);
	res_array = (int*) malloc(numEquivalent*sizeof(int));
	int counter = 0;
	
	// Get initial information of digits and rounded resistance.
	int digits = numDigits(resistance);
	int nom_resistance = toClosestPower10(resistance, digits-1);
	
	// Will be equal to the original resistance at the end of the
	// algorithm (hopefully).
	int accumulated_res = 0;
	
	// While we still have digits to process and we haven't reached the limit
	// of 3 equivalent resistances...
	while (digits > 0 && counter < numEquivalent) {
		// The following value will be the closest to the current rounded
		// resistance number.
		int closest_e12_resistance = 0;
		// Iterate through the e12 series.
		int e12_series_len = sizeof(e12_series)/sizeof(int);
		for (int i = 0; i < e12_series_len; i++)
		{
			// Convert e12 value to a resistance with the same number of
			// digits as the one we are trying to match.
			int cur_e12_resistance = (e12_series[i]*pow(10, digits-1))/10;
			// Check if the current e12 resistance hasn't exceeded the
			// value of the desired, rounded resistance.
			if (nom_resistance -  cur_e12_resistance >= 0)
			{
				// Then we can assign it as the closest.
				closest_e12_resistance = cur_e12_resistance;
			}
			else { break; }
		}

		// Assign the found resistance to the current index in the pointer.
		res_array[counter++] = closest_e12_resistance;
		// Update accumulated resistance value.
		accumulated_res += closest_e12_resistance;
		
		// Assign new values for the rounded resistance that we want to find next
		// and the number of digits in that value.
		nom_resistance = toClosestPower10(resistance - accumulated_res, digits-1);
		digits = numDigits(nom_resistance);
	}
	
	// Add zeroes to the remaining slots in the resistance pointer.
	if (counter < numEquivalent) {
		for (int i = counter; i < numEquivalent; i++)
			res_array[i] = 0;
	}
	
	return counter; 
}
