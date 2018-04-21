#include <stdio.h>
#include <stdlib.h>
#include "libresistance.h"

float calc_resistance(int count, char conn, float *array)
	{
	float totres = 0;
	int i = 0;
	// int count anger antalet resistorer som används.
	// char conn kan anta värdena: P eller S
	// float *array ger adressen till den array med information
	//  kring storleken på resistorerna. Lika stor/lång som count.
	// varje plats av arrayn ges genom *array+n
	if(array == NULL)
	{
		printf("Minne ej allokerat");
		exit(0);
	}
	if(conn == 'S')
	{
		goto series;
	}
	else if(conn == 'P')
	{
		goto parallell;
	}
	else
	{
		printf("Felaktigt val! \n");
		return -1;
	}
	// Ersättningsresistans vid seriekoppling:
	series:
		for(i = 0; i < count; ++i)
		{
			totres += *(array + i);
		}
		return totres;

	parallell:
		for(i = 0; i < count; ++i)
		{
			totres  = totres + 1/(*(array + i));
		}
		totres = 1/totres;
		return totres;
	}
