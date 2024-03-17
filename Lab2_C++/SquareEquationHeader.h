#pragma once

#ifndef SQUARE_EQUATION_H

#define SQUARE_EQUATION_H
#pragma warning(disable:4996)
#include <cstdio>
#include <cmath>
#include <cstdlib>


struct Equation
{
	double a, b, c;
} typedef Equation;

enum Status
{
	NoSol = 0, OneSol = 1, TwoSol = 2
};
struct Solution
{
	enum Status Cur;
	double* x1, * x2;
} typedef Solution;

extern void GetSolution(Equation const* OurEquation, Solution* const OurSolution);
extern void GetParameters(Equation* const OurEquation, double const par1, double const par2, double const par3);
extern void ShowSolution(Solution const* OurSolution);

#endif // !SQUARE_EQUATION_H

