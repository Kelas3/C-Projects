/*************************************************************
DESCRIPTION:Modifed version of the game "craps"
AUTHOR:Salek Khan
*************************************************************/

/*
Balance = 50.0
Check to make sure New Balance > 0
	-Yes: Continue
	-No: Tell the user they are broke and exit
Ask for bet
	- Check if bet > balance
	- Check if bet < 0
		~Less than 0 --> Tell the user the bet is invalid, ask for another bet
		~Greater than zero --> Continue
Throw a pair of dice (add results of each die together)
	-If sum is 7,11
		~Tell the user they win
		~New Balance = Balance + Bet
		~Ask if they want to play again?
			-> Yes: Go back to the start
			-> No: Exit
	-If sum is 2,3,12
		~Tell the user they lose
		~New Balance = Balance - Bet
		~Ask if they want to play again?
			-> Yes: Go back to the start
			-> No: Exit
	-If sum is anything else (4,5,6,8,9,10)
		~The sum is remebered as "the point"
		~Roll the pair of dice again
			->If the new roll sum = "the point"
				~Tell the user they win
				~New Balance = Balance + Bet
				~Ask if they want to play again?
					-> Yes: Go back to the start
					-> No: Exit
			->If the new roll sum = 7
				~Tell the user they lose
				~New Balance = Balance - Bet
				~Ask if they want to play again?
					-> Yes: Go back to the start
					-> No: Exit
			-If the new roll sum = anyting else
				~Roll again
				~Go back to checking if the roll sum = "the point"
*/

#include <stdio.h>
#include <stdlib.h>	
#include <time.h>

int SumOfThrows = 0;
int ValidBet = 0;
int FirstRun = 0;
double Balance = 50.0;
double Bet = 0.0;
char C;

void ShowBal(int FirstRun);
void CheckBal(double Balance);
void EnterBet(double Balance);
void InputFunc();
int ThrowDicePair();

void ShowBal(int FirstRun)
{
	if (FirstRun == 0)
	{
		printf("Your starting balance is $%.2f", Balance);
	}
	if (FirstRun > 0)
	{
		printf(" Your new balance is $%.2f", Balance);
	}
}

void CheckBal(double Balance)
{
	if (Balance < 0.01)
	{
		printf(" Sorry you are out of money!");
		exit(0);
	}
}

void EnterBet(double Balance)
{
	do
	{
		ValidBet = 0;
		printf("\nPlease enter your bet:");
		scanf("%lf", &Bet);

		if ((Bet > Balance) || (Bet < 0))
		{
			printf("Your bet is invalid, try again.");
		}
		else
		{
			ValidBet = 1;
		}
	} while (ValidBet == 0);
}

void InputFunc()
{
	srand(time(NULL));
	ShowBal(FirstRun);
	CheckBal(Balance);
	EnterBet(Balance);

	ThrowDicePair();
	printf("The dice roll was = %d", SumOfThrows);
}

int ThrowDicePair()
{
	int Throw1 = 0;
	int Throw2 = 0;

	Throw1 = rand() % 6 + 1;
	Throw2 = rand() % 6 + 1;
	SumOfThrows = Throw1 + Throw2;
	return SumOfThrows;
}


int main()
{	
	while (1)
	{
		InputFunc();
		if (SumOfThrows == 7 || SumOfThrows == 11)
		{
			Balance += Bet;
			printf(" You win! Would you like to play again? [y/n]");
			C = getch();
			if (C == 'y')
			{
				FirstRun++;
			}
			else if (C == 'n')
			{
				printf("Thanks for playing");
				exit(0);
			}

		}

		if (SumOfThrows == 2 || SumOfThrows == 3 || SumOfThrows == 12)
		{
			Balance -= Bet;
			printf(" You loose! Would you like to play again? [y/n]");
			C = getch();
			if (C == 'y')
			{
				FirstRun++;
			}
			else if (C == 'n')
			{
				printf("Thanks for playing");
				exit(0);
			}
		}

		else
		{
			int Point = 0;
			Point = SumOfThrows;
			ThrowDicePair();
			printf("\nThe second dice roll = %d  ", SumOfThrows);

			if (SumOfThrows == Point)
			{
				Balance += Bet;
				printf(" You win! Would you like to play again? [y/n]");
				C = getch();
				if (C == 'y')
				{
					FirstRun++;
				}
				else if (C == 'n')
				{
					printf("Thanks for playing");
					exit(0);
				}

			}

			if (SumOfThrows == 7)
			{
				Balance -= Bet;
				printf(" You loose! Would you like to play again? [y/n]");
				C = getch();
				if (C == 'y')
				{
					FirstRun++;
				}
				else if (C == 'n')
				{
					printf("Thanks for playing");
					exit(0);
				}
			}
			else if ((SumOfThrows != Point) && (SumOfThrows != 7))
			{
				printf("Rolling until we get the point or 7");
				do
				{
					ThrowDicePair();
					printf("\nRoll = %d", SumOfThrows);

				} while ((SumOfThrows != Point) && (SumOfThrows != 7));
				if (SumOfThrows == 7)
				{
					Balance -= Bet;
					printf(" You loose! Would you like to play again? [y/n]");
					C = getch();
					if (C == 'y')
					{
						FirstRun++;
					}
					else if (C == 'n')
					{
						printf("Thanks for playing");
						exit(0);
					}
				}

				else if (SumOfThrows = Point)
				{
					Balance += Bet;
					printf(" You win! Would you like to play again? [y/n]");
					C = getch();
					if (C == 'y')
					{
						FirstRun++;
					}
					else if (C == 'n')
					{
						printf("Thanks for playing");
						exit(0);
					}
				}
			}
		}
	}
}


