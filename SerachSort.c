/*******************************************************************
DESCRIPTION: Searching and Sorting practice
AUTHOR:Salek Khan
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <memory.h>
#include <string.h>

#define SIZE_OF_VAR 256

void BubbleSort(char NameArray[][256], int End);
int CustBSearch(char ArrOrg[][256], int Len, int BeforeEnd, char NameArray[256]);

void BubbleSort(char NameArray[][256], int End)
{ 
	char TempArray[256];
	for (int i = 0; i < End - 1; i++)
	{
		for (int j = i + 1; j < End; j++)
		{
			if (strcmp(NameArray[i], NameArray[j]) > 0)
			{
				strcpy(TempArray, NameArray[i]);
				strcpy(NameArray[i], NameArray[j]);
				strcpy(NameArray[j], TempArray);
			}
		}
	}
}

int CustBSearch(char ArrOrg[][256], int Len, int BeforeEnd, char NameArray[256])
{
	if (BeforeEnd >= Len) 
	{
		int HalfwayPt = Len + (BeforeEnd - Len) / 2;
		if (strcmp(ArrOrg[HalfwayPt], NameArray) == 0)
		{
			return HalfwayPt;
		}
		if (strcmp(ArrOrg[HalfwayPt], NameArray) > 0)
		{
			return CustBSearch(ArrOrg, Len, HalfwayPt - 1, NameArray);
		}
		return CustBSearch(ArrOrg, HalfwayPt + 1, BeforeEnd, NameArray);
	}
	else
	{
		return -1;
	}

}

int main()
{
	char NamesWithIndex[SIZE_OF_VAR][256], NameArray[256];
	int Index;
	int Length;
	int x = 0, y = 0;

	while (1)
	{
		printf("Please enter name #%d:", x+1);
		fgets(NameArray, sizeof(NameArray), stdin);
		if (NameArray[0] == '\n')
		{
			break;
		}
		Length = strlen(NameArray);
		NameArray[Length - 1] = '\0';
		strcpy(NamesWithIndex[x], NameArray);
		x++;
	}

	printf("\nArray before sorting:\n");
	for (int z = 0; z < x; z++)
	{
		printf("Index[%d] %s\n", z,NamesWithIndex[z]);
	}
	BubbleSort(NamesWithIndex, x);
	printf("\nArray after sorting: \n");
	for (int f = 0; f < x; f++)
	{
		printf("Index[%d] %s\n", f, NamesWithIndex[f]);
	}

	while (1)
	{
		printf("Please enter the name you want to search:");
		fgets(NameArray, sizeof(NameArray), stdin);
		if (NameArray[0] == '\n')
		{
			break;
		}
		Length = strlen(NameArray);
		NameArray[Length - 1] = '\0';
		Index = CustBSearch(NamesWithIndex, 0, x, NameArray);
		if (Index >= 0)
		{
			printf("Found! The term you searched for is at index %d \n", Index);
		}
		else
		{
			printf("Sorry! %s is not present in the array \n", NameArray);
		}
	}
	return 0;
}




