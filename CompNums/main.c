/*************************************************************
DESCRIPTION: Learning structs with comp nums
AUTHOR:Salek Khan
*************************************************************/

#include <stdio.h>
#include "ComplexNum.h"

ComplexNum Add(ComplexNum Num1, ComplexNum Num2);
ComplexNum Sub(ComplexNum Num1, ComplexNum Num2);
ComplexNum Mul(ComplexNum Num1, ComplexNum Num2);
ComplexNum Div(ComplexNum Num1, ComplexNum Num2);

int main()
{
	struct ComplexNum Num1, Num2, Ans;
	printf("Enter real and imaginary part for Num 1 (real space imaginary):");
	scanf("%f %f", &Num1.RealPart, &Num1.ImagPart);

	printf("Enter real and imaginary part for Num 2 (real space imaginary):");
	scanf("%f %f", &Num2.RealPart, &Num2.ImagPart);

	if (Num1.RealPart == 0 && Num1.ImagPart == 0 && Num2.RealPart == 0 && Num2.ImagPart == 0)
	{
		printf("Error! Divide by zero");
		exit(0);
	}
	if (Num1.RealPart != 0 && Num1.ImagPart == 0 && Num2.RealPart == 0 && Num2.ImagPart == 0)
	{
		printf("Error! Divide by zero");
		exit(0);
	}
	if (Num1.RealPart == 0 && Num1.ImagPart != 0 && Num2.RealPart == 0 && Num2.ImagPart == 0)
	{
		printf("Error! Divide by zero");
		exit(0);
	}
	if (Num1.RealPart != 0 && Num1.ImagPart != 0 && Num2.RealPart == 0 && Num2.ImagPart == 0)
	{
		printf("Error! Divide by zero");
		exit(0);
	}

	printf("\nThe numbers you entered were: %.2f + %.2fi and %.2f + %.2fi", Num1.RealPart, Num1.ImagPart, Num2.RealPart, Num2.ImagPart);

	Ans = Add(Num1, Num2);
	printf("\nSum = %.2f + %.2fi\n", Ans.RealPart, Ans.ImagPart);
	Ans = Sub(Num1, Num2);
	printf("Differnce = %.2f + %.2fi\n", Ans.RealPart, Ans.ImagPart);
	Ans = Mul(Num1, Num2);
	printf("Product = %.2f + %.2fi\n", Ans.RealPart, Ans.ImagPart);
	Ans = Div(Num1, Num2);
	printf("Quotient = %.2f + %.2fi\n", Ans.RealPart, Ans.ImagPart);

	return 0;
}

ComplexNum Add(ComplexNum Num1, ComplexNum Num2)
{
	ComplexNum Ans;

	Ans.RealPart = Num1.RealPart + Num2.RealPart;
	Ans.ImagPart = Num1.ImagPart + Num2.ImagPart;

	return(Ans);
}

ComplexNum Sub(ComplexNum Num1, ComplexNum Num2)
{
	ComplexNum Ans;

	Ans.RealPart = Num1.RealPart - Num2.RealPart;
	Ans.ImagPart = Num1.ImagPart - Num2.ImagPart;

	return(Ans);
}

ComplexNum Mul(ComplexNum Num1, ComplexNum Num2)
{
	ComplexNum Ans;

	Ans.RealPart = (Num1.RealPart * Num2.RealPart)-(Num1.ImagPart * Num2.ImagPart);
	Ans.ImagPart = (Num1.RealPart*Num2.ImagPart) + (Num1.ImagPart*Num2.RealPart);

	return(Ans);
}

ComplexNum Div(ComplexNum Num1, ComplexNum Num2)
{
	ComplexNum Ans;

	Ans.RealPart = ((Num1.RealPart*Num2.RealPart) + (Num1.ImagPart*Num2.ImagPart)) / ((Num2.RealPart*Num2.RealPart) + (Num2.ImagPart*Num2.ImagPart));
	Ans.ImagPart = ((Num1.ImagPart*Num2.RealPart) - (Num1.RealPart*Num2.ImagPart)) / ((Num2.RealPart*Num2.RealPart) + (Num2.ImagPart*Num2.ImagPart));

	return(Ans);
}
