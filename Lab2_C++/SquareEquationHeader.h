#pragma once

#ifndef SQUARE_EQUATION_H

#define SQUARE_EQUATION_H
#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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

#endif // !SQUARE_EQUATION_H

