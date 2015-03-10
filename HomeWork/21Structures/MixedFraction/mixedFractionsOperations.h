#ifndef MIXEDFRACTIONSOPERATIONS_H_INCLUDED
#define MIXEDFRACTIONSOPERATIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../../../Modules/include/mathx.h"

typedef struct MixedFraction_
{
    int integer, numerator, denominator;
} MixedFraction;

void convertFraction(MixedFraction *pointer);
void enterMixedFraction(MixedFraction *);
void showMixedFraction(MixedFraction);
double turnToDouble(MixedFraction);
MixedFraction summarize(MixedFraction, MixedFraction);

#endif // MIXEDFRACTIONSOPERATIONS_H_INCLUDED
