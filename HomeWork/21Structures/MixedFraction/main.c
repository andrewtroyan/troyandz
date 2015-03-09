#include "mixedFractionsOperations.h"

int main()
{
    MixedFraction myFirstFraction, *pointer = &myFirstFraction;

    enterMixedFraction(pointer);
    showMixedFraction(pointer);

    return 0;
}
