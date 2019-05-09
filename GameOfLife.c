/******************************************************
DESCRIPTION:Game of Life Simulation (Martin Gardner)
AUTHOR:Salek Khan
******************************************************/

#include <stdio.h>
#include <Windows.h> //if loop of frames wanted use this and function Sleep()
#define ROWS 60
#define COLS 60
#define ALIVE 1
#define DEAD 0
typedef int PlayingBoard[ROWS][COLS];

void TablePrint(PlayingBoard Board) 
{
	int Row, Col;
	for (Row = 0; Row < ROWS; Row++)
	{
		for (Col = 0; Col < COLS; Col++) 
		{
			if (Board[Row][Col] == ALIVE)
			{
				printf("X");
			}
			else 
			{
				printf("O");
			}
		}
		printf("\n");
	}
}

void AllDead(PlayingBoard Board)
{
	int Row, Col;
	for (Row = 0; Row < ROWS; Row++) 
	{
		for (Col = 0; Col < COLS; Col++) 
		{
			Board[Row][Col] = DEAD;
		}
	}
}

void UserInput(PlayingBoard Board) 
{
	int Row, Col;
	printf("Enter the row and column posistions of the alive cells:\n");
	printf("Enter 61 61 to when you are done\n");
	do {
		
		scanf("%d %d", &Row, &Col);
		if ((Row == 61) || (Col == 61))
		{
			break;
		}

		if ((Row <0) || (Row > ROWS - 1) || (Col < 0) || (Col > COLS - 1 ))
		{
			printf("Row or columns values are out of bound, try again.\n");
		}
		else
		{
			Board[Row][Col] = ALIVE;
			
		}
	} while (1);

	TablePrint(Board);
	printf("\nGeneration 0\n");
}

int NeighborAliveOrDead(PlayingBoard Board, int Row, int Col)
{
	if (Row < 0 || Row >= ROWS || Col < 0 || Col >= COLS || Board[Row][Col] != ALIVE)
	{
		return 0;
	}
	else 
	{
		return 1;
	}

}

int NumNeighbors(PlayingBoard Board, int Row, int Col) {

		int NeighborCount = 0;

		NeighborCount += NeighborAliveOrDead(Board, Row, Col - 1);
		NeighborCount += NeighborAliveOrDead(Board, Row, Col + 1);

		NeighborCount += NeighborAliveOrDead(Board, Row + 1, Col);
		NeighborCount += NeighborAliveOrDead(Board, Row + 1, Col + 1);

		NeighborCount += NeighborAliveOrDead(Board, Row - 1, Col - 1);
		NeighborCount += NeighborAliveOrDead(Board, Row - 1, Col + 1);

		NeighborCount += NeighborAliveOrDead(Board, Row - 1, Col);
		NeighborCount += NeighborAliveOrDead(Board, Row + 1, Col - 1);
		
		return NeighborCount;
}

void ApplyRules(PlayingBoard Board) 
{
	PlayingBoard BoardCopy;
	int NeighborCount, Row, Col;

	for (Row = 0; Row < ROWS; Row++) 
	{
		for (Col = 0; Col < COLS; Col++) 
		{
			NeighborCount = NumNeighbors(Board, Row, Col);
			if (NeighborCount == 3) 
			{
				BoardCopy[Row][Col] = ALIVE;
			}
			else if (NeighborCount == 2 && Board[Row][Col] == ALIVE) 
			{
				BoardCopy[Row][Col] = ALIVE;
			}
			else 
			{
				BoardCopy[Row][Col] = DEAD;
			}
		}
	}
	for (Row = 0; Row < ROWS; Row++) 
	{
		for (Col = 0; Col < COLS; Col++) 
		{
			Board[Row][Col] = BoardCopy[Row][Col];
		}
	
	}
}

int main(void)
{
	char Escape;
	int GenCount = 0;

	PlayingBoard Board;
	AllDead(Board);
	UserInput(Board);

	do
	{
		printf("Would you like to continue? [y/n]:");
		scanf("%c", &Escape);
		if (Escape == 'y')
		{
			Sleep(2000); //2000ms = 2s
			printf("\n");
			system("cls");
			ApplyRules(Board);
			TablePrint(Board);
			printf("Generation %d\n", (++GenCount));
		}
		else if (Escape == 'n')
			break;
	} while (Escape != 'n');
}
