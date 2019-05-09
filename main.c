/*********************************************
DESCRIPTION:A palindrome detector (Lab 6)
CLASS:COSC 1420.S01
AUTHOR:Salek Khan
DATE: Feb 22, 2019
*********************************************/

#include <stdio.h>
#include <ctype.h>

int main()
{
	char UserString[100];
	char ChangedString[100];
	int Start = 0;
	char Escape[10] = "END";
	do
	{
		printf("Please enter a word or sentence:");
		fgets(UserString, 100, stdin);
		UserString[Length(UserString) - 1] = '\0';

		if (Compare(UserString, Escape) == 0)
		{
			printf("Bye!");
			exit(0);
		}

		for (int Place = 0; Place < Length(UserString); Place++)
			UserString[Place] = tolower(UserString[Place]);

		int End = Length(UserString) - 1;

		for (Start = 0; Start < Length(UserString); Start++)
		{
			ChangedString[Start] = UserString[End];
			End--;
		}
		ChangedString[Start] = '\0';

		if (Compare(ChangedString, UserString) == 0)
		{
			printf("The entered word/sentence is a palindrome\n");
		}
		else
		{
			printf("The entered word/sentence is a not palindrome\n");
		}
	} while (1);
} 

int Compare(char *str1, char *str2) 
{
	while (*str1 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

int Length(const char *str)
{
	const char *s;

	for (s = str; *s; s++)
		;
	return (s - str);
}

