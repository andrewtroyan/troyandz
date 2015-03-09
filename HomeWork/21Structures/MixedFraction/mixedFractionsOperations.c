#include "mixedFractionsOperations.h"

void enterMixedFraction(MixedFraction *pointer)
{
    scanf("%d.%d/%d", &pointer->integer, &pointer->numerator, &pointer->denominator);
}

void showMixedFraction(MixedFraction *pointer)
{
    printf("%d.%d/%d", pointer->integer, pointer->numerator, pointer->denominator);
}
