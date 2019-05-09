/***************************************************************************************
DESCRIPTION:A four function calculator with clear and reset, done with functions
AUTHOR:Salek Khan
***************************************************************************************/

#include <stdio.h>
#include <conio.h>

typedef	char BOOL;

#define FALSE	0
#define	TRUE	1

char Op;
int RunCount = 1;


int ReadInt()
{
	char	C;
	int		CharCount;
	BOOL	IsNeg;
	double	Num;


	CharCount = 0;
	IsNeg = FALSE;
	Num = 0;
	//if (RunCount%2 != 0)
	if (RunCount == 1)
	{
		printf("\nEnter 1st number:");
	}
	//else if (RunCount%2 == 0)
	else if (RunCount >= 2)
	{
		printf("\nEnter 2nd number:");
	}

	while ((C = _getch()) != '\r')	
	{
		switch (C)
		{
		case '-':
			if (CharCount == 0)
			{
				IsNeg = TRUE;
				CharCount++;
			}
			else
				C = '\a';
			break;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			CharCount++;
			Num = (Num * 10) + (C - '0');
			break;
		case '\b':
			if (CharCount > 0)
			{
				Num /= 10;
				_putch('\b');
				_putch(' ');
				CharCount--;
				if (CharCount == 0)
					IsNeg = FALSE;
				else;
			}
			else
				C = '\a';
			break;
		default:
			C = '\a';	
		}
		_putch(C);
	}
	_putch('\n');
	if (IsNeg)
		Num = -Num;
	else;

	return Num;
	
}

double Add(double Num1, double Num2)
{
	double Result = Num1 + Num2;
	return Result;
}

double Sub(double Num1, double Num2)
{
	double Result = Num1 - Num2;
	return Result;
}

double Mult(double Num1, double Num2)
{
	double Result = Num1 * Num2;
	return Result;
}

double Div(double Num1, double Num2)
{
	double Result;
	if (Num2 == 0)
	{
		printf("Divide by zero");
		exit(0);
	}
	else
	{
		Result = Num1 / Num2;
	}
	return Result;
}


BOOL GetOp(char ValidOps, char Opr)
{
	BOOL IsValid;

	do
	{
		printf("Enter operator:");
		Opr = _getch();
		printf("%c", Opr);
		if (Opr != '+' && Opr != '-' && Opr != '*' && Opr != '/')
		{
			printf("\nInvalid operator, try again.");
			IsValid = FALSE;

		}
		else
		{
			IsValid = TRUE;
			Op = Opr;
			break;
		}
	} while (IsValid == FALSE);

	return IsValid;
}

double Calculate(char Op, double Num1, double Num2)
{
	double Result = 0;
	switch (Op)
	{
	case '+': 
		Result = Add(Num1, Num2);
		break;
	case '-':
		Result = Sub(Num1, Num2);
		break;
	case '*':
		Result = Mult(Num1, Num2);
		break;
	case '/':
		Result = Div(Num1, Num2);
		break;
	default:
		break;
	}

	return Result;
}


int main()
{
		BOOL IsV = FALSE;
		char ValidOps[4] = { '+','-','*','/' };

		double Num1 = ReadInt();
		RunCount++;
		IsV = GetOp(ValidOps, Op);
		double Num2 = ReadInt();

		double Answer = Calculate(Op, Num1, Num2);
		printf("Your answer is: %f \n", Answer);

}



