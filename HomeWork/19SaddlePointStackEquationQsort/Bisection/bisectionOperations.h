#ifndef BISECTIONOPERATIONS_H_INCLUDED
#define BISECTIONOPERATIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EXP 2.71828

double firstExample(double x);
double secondExample(double x);
double thirdExample(double x);
double bisection(double startPoint, double finalPoint, double eps, double (*function)(double));

#endif // BISECTIONOPERATIONS_H_INCLUDED
