#include "mixedFractionsOperations.h"

void enterMixedFraction(MixedFraction *pointer)
{
    int greatComDiv;
    scanf("%d.%d/%d", &pointer->integer, &pointer->numerator, &pointer->denominator);
    assert((pointer->numerator == 0 && pointer->denominator == 0) || (pointer->numerator > 0 && pointer->denominator > 0));
    if(pointer->numerator > pointer->denominator)
    {
        pointer->integer += pointer->numerator / pointer->denominator;
        pointer->numerator %= pointer->denominator;
    }
    else if(pointer->numerator == pointer->denominator && pointer->numerator && pointer->denominator)
    {
        ++pointer->integer;
        pointer->numerator = 0;
        pointer->denominator = 0;
    }
    else if(pointer->numerator && pointer->denominator && (greatComDiv = gcd(pointer->numerator, pointer->denominator)) != 1)
    {
        pointer->numerator /= greatComDiv;
        pointer->denominator /= greatComDiv;
    }
}

void showMixedFraction(MixedFraction fraction)
{
    printf("%d.%d/%d\n", fraction.integer, fraction.numerator, fraction.denominator);
}

MixedFraction summarize(MixedFraction firstFraction, MixedFraction secondFraction)
{
    MixedFraction result;
    result.integer = firstFraction.integer + secondFraction.integer;
    if((firstFraction.numerator == 0 && firstFraction.denominator == 0) || (secondFraction.numerator == 0 && secondFraction.denominator == 0))
    {
        result.numerator = firstFraction.numerator + secondFraction.numerator;
        result.denominator = firstFraction.denominator + secondFraction.denominator;
    }
    else
    {
        int commonDenominator = lcm(firstFraction.denominator, secondFraction.denominator), greatComDiv;
        result.numerator = firstFraction.numerator * (commonDenominator / firstFraction.denominator) + secondFraction.numerator * (commonDenominator / secondFraction.denominator);
        result.denominator = commonDenominator;
        if(result.numerator > result.denominator)
        {
            ++result.integer;
            result.numerator -= result.denominator;
        }
        else if(result.numerator == result.denominator && result.numerator && result.denominator)
        {
            ++result.integer;
            result.numerator = 0;
            result.denominator = 0;
        }
        else if((greatComDiv = gcd(result.numerator, result.denominator)) != 1)
        {
            result.numerator /= greatComDiv;
            result.denominator /= greatComDiv;
        }
    }
    return result;
}

double turnToDouble(MixedFraction fraction)
{
    return (double)fraction.integer + (double)fraction.numerator / (double)fraction.denominator;
}
