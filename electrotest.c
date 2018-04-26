#include <stdio.h>
#include <stdlib.h>
#include "./Bibliotek1/lib/libresistance.h"
#include "./Bibliotek2/src/power.h"
#include "./Bibliotek3/src/libcomponent.h"

int main(void)
{
	int volt, i, antal = 0;
 	char koppling;
	float *rval = NULL;
	float resistance = 0;

	//Ange spänningskälla
	printf("Ange spänningskälla i V: ");
	scanf(" %d", &volt);

	//Ange koppling
	printf("Ange koppling [ S | P ]: ");
	scanf(" %c", &koppling);

	//Ange antal komponenter
	printf("Antal komponenter: ");
	scanf(" %d", &antal);

	//Minnesallokering av arrayen rval
	rval = (float*) malloc(antal * sizeof(float));
	for(i = 0; i < antal; ++i)
	{
		//Ange komponentvärden
		printf("Komponent %d i ohm: ", i + 1);
		scanf(" %f", rval+i);
	}

	//Skriv ut ersättningsresistans
	resistance = calc_resistance(antal,koppling,rval);
	printf("Ersättningsresistans: \n%.1f ohm\n", resistance);
	//Frigör minnet
	free(rval);

	//Skriv ut effekt:
	printf("Effekt: \n%3.2f W\n", calc_power_r(volt, resistance));

	//Skriv ut ersättningsresistanser:
	//Minnesallokering av arrayen rval
	rval = (float*) malloc(3 * sizeof(float));
	antal = e_resistance(resistance, rval);
	printf("Ersättingsresistanser i E12-serien kopplade i serie: \n");
	for(i = 0; i < antal; ++i)
	{
		printf("%d\n", rval[i]);
	}
	//Frigör minnet
	free(rval);

	return 0;
}
