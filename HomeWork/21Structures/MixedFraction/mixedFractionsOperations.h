#ifndef MIXEDFRACTIONSOPERATIONS_H_INCLUDED
#define MIXEDFRACTIONSOPERATIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct MixedFraction_
{
    int integer, numerator, denominator;
} MixedFraction;

void enterMixedFraction(MixedFraction *);
void showMixedFraction(MixedFraction *);

#endif // MIXEDFRACTIONSOPERATIONS_H_INCLUDED
