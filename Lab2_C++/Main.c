#include "SquareEquationHeader.h"

extern void User_Interface(Equation const* OurEquation);
extern void GetSolution(Equation const* OurEquation, Solution* const OurSolution);
extern void ShowSolution(Solution const* OurSolution);


int manya(int argc, char* argv)
{
	Equation OurEquation;
	Solution OurSolution;

	User_Interface(&OurEquation);
	GetSolution(&OurEquation, &OurSolution);
	ShowSolution(&OurSolution);


	return 0;
}