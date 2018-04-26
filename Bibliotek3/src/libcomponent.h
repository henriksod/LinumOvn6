/**********************************************************
 *
 *	libcomponent.h
 *
 *	Author: Henrik Söderlund
 *	Date:   2018
 *	
 *	This file is used as a part of a library used
 *	to compute at most three equivalent resistances
 *	from the e12 series based on a given resistance.
 *
 *********************************************************/

#ifndef __LIBCOMPONENT_H__
#define __LIBCOMPONENT_H__

// Number of equivalent e12 resistances to find by the e_resistance
// function.
const int numEquivalent = 3;

// e12 series
const int e12_series[] = {0, 10, 12, 15, 18, 22, 27, 33, 39, 47, 56, 68, 82};

// e_resistance(orig_resistance, res_array)
//
// input: A resistance value and a preallocated pointer.
//		  The pointer res_array has to be of size numEquivalent*sizeof(float).
//
// output: Number of equivalent resistances needed and
//         also fills the pointer with the equivalent
//         resistances needed to get the original.
extern int e_resistance(float orig_resistance, float *res_array);

#endif /* __LIBCOMPONENT_H__ */
