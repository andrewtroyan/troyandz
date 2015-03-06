#include "bisectionOperations.h"

double bisection(double startPoint, double finalPoint, double eps, double (*function)(double))
{
    double middle = (startPoint + finalPoint) / 2;
    if(function(middle) == 0 || fabs(finalPoint - startPoint) <= eps)
    {
        return middle;
    }
    else
    {
        double resultForStart = function(startPoint), resultForMiddle = function(middle);
        if(resultForStart * resultForMiddle < 0)
        {
            bisection(startPoint, middle, eps, function);
        }
        else
        {
            bisection(middle, finalPoint, eps, function);
        }
    }
}

double firstExample(double x)
{
    return pow(x, 3) - 2 * pow(x, 2) - 4 * x + 7;
}

double secondExample(double x)
{
    return pow(EXP, (-x)) - 0.5 * pow(sin(x), 2);
}

double thirdExample(double x)
{
    return acos(x) - x;
}
