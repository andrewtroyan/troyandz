#include "mixedFractionsOperations.h"

int main()
{
    MixedFraction firstFraction, secondFraction, result;

    enterMixedFraction(&firstFraction);
    enterMixedFraction(&secondFraction);
    result = summarize(firstFraction, secondFraction);
    showMixedFraction(result);

    return 0;
}
