/***************************************************
DESCRIPTION: Learning macros and bit ops
AUTHOR:Salek Khan
***************************************************/

#include <stdio.h>
#include "BitMacros.h"

int main()
{
	unsigned int CurrentStatus = 0;
	int BitToCheck = 0;
	unsigned int IsOnResult = 0;
	unsigned int TurnOnResult = 0;
	unsigned int TurnOffResult = 0;
	unsigned int ToggleResult = 0;
	do
	{
		printf("\nEnter the current status in hex:");
		scanf("%x", &CurrentStatus);
		printf("\nEnter the bit to check:");
		scanf("%d", &BitToCheck);

		IsOnResult = IsOn(CurrentStatus, BitToCheck);
		printf("\nIsOn Result = %x", IsOnResult);

		TurnOnResult = TurnOn(CurrentStatus, BitToCheck);
		printf("\nTurnOn Result= %x", TurnOnResult);

		TurnOffResult = TurnOff(CurrentStatus, BitToCheck);
		printf("\nTurnOff Result = %x", TurnOffResult);

		ToggleResult = Toggle(CurrentStatus, BitToCheck);
		printf("\nToggle Result = %x", ToggleResult);

	} while (1);
}
