#include "SquareEquationHeader.h"

 void GetParameters(Equation* const OurEquation, double const par1, double const par2, double const par3)
{
	OurEquation->a = par1;
	OurEquation->b = par2;
	OurEquation->c = par3;
}

static enum Status SolutionQuantity(Equation const* OurEquation)
{
	//D = b*b - 4 * a * c
	double Discriminant = OurEquation->b * OurEquation->b - 4 * OurEquation->a * OurEquation->c;
	if (Discriminant < 0)
		return NoSol;
	else if (Discriminant == 0)
		return OneSol;
	else
		return TwoSol;
}

static void NoSolProcedure(Solution* const OurSolution)
{
	OurSolution->Cur = NoSol;
	OurSolution->x1 = NULL;
	OurSolution->x2 = NULL;
}

static void OneSolProcedure(Equation const* OurEquation, Solution* const OurSolution)
{
	OurSolution->Cur = OneSol;
	*OurSolution->x1 = *OurSolution->x2 = OurEquation->b / OurEquation->c;
}

static void TwoSolProcedure(Equation const* OurEquation, Solution* const OurSolution)
{
	OurSolution->Cur = TwoSol;
	*OurSolution->x1 = (-OurEquation->b - sqrt(OurEquation->b * OurEquation->b - 4 * OurEquation->a * OurEquation->c)) / 2 * OurEquation->a;
	*OurSolution->x2 = (-OurEquation->b + sqrt(OurEquation->b * OurEquation->b - 4 * OurEquation->a * OurEquation->c)) / 2 * OurEquation->a;
}

static void FillSolution(Solution* const OurSolution)
{
	OurSolution->x1 = (double*)malloc(sizeof(double));
	OurSolution->x2 = (double*)malloc(sizeof(double));
}

void GetSolution(Equation const* OurEquation, Solution* const OurSolution)
{
	FillSolution(OurSolution);
	if (OurEquation->a != 0)
	{
		OurSolution->Cur = SolutionQuantity(OurEquation);
		if (OurSolution->Cur == OneSol)
			OneSolProcedure(OurEquation, OurSolution);
		else if (OurSolution->Cur == TwoSol)
			TwoSolProcedure(OurEquation, OurSolution);
		else 
			NoSolProcedure(OurSolution);
	}
	else if (OurEquation->a == 0 && OurEquation->b == 0)
		NoSolProcedure(OurSolution);
	else
		OneSolProcedure(OurEquation, OurSolution);
}


void ShowSolution(Solution const* OurSolution)
{
	if (OurSolution->Cur == NoSol)
		printf("There are no solutions for your equation.\n");
	else if (OurSolution->Cur == OneSol)
		printf("There is one solution for your equation and it's %lf.\n", *OurSolution->x1);
	else
		printf("There are two solutions for your equation and they are %lf,%lf.\n", *OurSolution->x1, *OurSolution->x2);
}


