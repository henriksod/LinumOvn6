/**********************************************************************
 *
 *  power.c
 *
 *  Author: Niclas Hultgren
 *  Date:   2018-04-16
 *  
 *  
 *  File for two functions to calculate power:
 *  calc_power_r(), and calc_power_i() based on provided arguments of
 *  voltage, current and resistance
 *  
 *********************************************************************/

#include <stdio.h>
#include "power.h"

float calc_power_r(float volt, float resistance)
{
  float result = 0;	// Avoid divide by zero, if so return 0
  if (resistance > 0)
  {
    result = (volt * volt / resistance);
  }
  return result;
}

float calc_power_i(float volt, float current)
{
  return(volt * current);
}
