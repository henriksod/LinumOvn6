/**********************************************************************
 *
 *  test_libpower.c
 *
 *  Author: Niclas Hultgren
 *  Date:   2018-04-16
 *  
 *  
 *  This file is used to test the two functions in library libpower:
 *  calc_power_r(), and calc_power_i() based on provided arguments of
 *  voltage, current and resistance
 *  
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "../power.h"

int main(int argc, char *argv[])
{
  // Set default values
  float test_voltage = 5;
  float test_current = 0.1;
  float test_resistance = 33;

  if(argc >= 2)
  {
    test_voltage = atoi(argv[1]);
  }
  if(argc >= 3)
  {
    test_current = atoi(argv[2]);
    test_current = test_current / 1000;
  }
  if(argc == 4)
  {
    test_resistance = atoi(argv[3]);
  }
  if(argc > 4)
  {
    printf("Too many arguments, expected three arguments (voltage, current(mA) and resistance)!\n");
  }
  else
  {
    printf("Testing power functions:\n");
    printf("Voltage assigned to:    %3.2f Volts\n", test_voltage);
    printf("Current assigned to:    %3.2f Ampere\n", test_current);
    printf("Resistance assigned to: %3.2f Ohms\n", test_resistance);
    if (test_resistance > 0)
    {
      printf("calc_power_r(%3.2f, %3.2f): %3.2f Watts\n", test_voltage, test_resistance, calc_power_r(test_voltage,test_resistance));
    }
    else
    {
      printf("calc_power_r(%3.2f, %3.2f) not tested since resistance is set to 0\n", test_voltage, test_resistance);
    }
    printf("calc_power_i(%3.2f, %3.2f): %3.2f Watts\n", test_voltage, test_current, calc_power_i(test_voltage,test_current));
  }
  exit(0);
}

