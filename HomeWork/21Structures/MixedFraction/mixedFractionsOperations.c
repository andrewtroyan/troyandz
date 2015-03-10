#include "mixedFractionsOperations.h"

void convertFraction(MixedFraction *pointer)
{
    int greatComDiv;
    if((abs)(pointer->numerator) > pointer->denominator)
    {
        pointer->integer += pointer->numerator / pointer->denominator;
        if(pointer->numerator % pointer->denominator == 0)
        {
            pointer->numerator = 0;
            pointer->denominator = 0;
        }
        else
        {
            pointer->numerator = (abs)(pointer->numerator % pointer->denominator);
        }
    }
    else if(pointer->numerator && (abs)(pointer->numerator) == pointer->denominator)
    {
        if(pointer->numerator > 0)
        {
            ++pointer->integer;
        }
        else
        {
            --pointer->integer;
        }
        pointer->numerator = 0;
        pointer->denominator = 0;
    }
    else if(pointer->numerator && (greatComDiv = gcd((abs)(pointer->numerator), pointer->denominator)) != 1)
    {
        pointer->numerator /= greatComDiv;
        pointer->denominator /= greatComDiv;
    }
}

void enterMixedFraction(MixedFraction *pointer)
{
    scanf("%d %d/%d", &pointer->integer, &pointer->numerator, &pointer->denominator);
    assert((pointer->numerator == 0 && pointer->denominator == 0) || (pointer->integer == 0 && pointer->numerator && pointer->denominator > 0) || (pointer->integer && pointer->numerator > 0 && pointer->denominator > 0));
    convertFraction(pointer);
}

void showMixedFraction(MixedFraction fraction)
{
    printf("%d %d/%d\n", fraction.integer, fraction.numerator, fraction.denominator);
}

MixedFraction turnToImproper(MixedFraction fraction)
{
    if(fraction.integer)
    {
        MixedFraction result;
        result.integer = 0;
        if(fraction.integer < 0 && fraction.numerator)
        {
            result.numerator = fraction.integer * fraction.denominator - fraction.numerator;
            result.denominator = fraction.denominator;
        }
        else if(fraction.integer > 0 && fraction.numerator)
        {
            result.numerator = fraction.integer * fraction.denominator + fraction.numerator;
            result.denominator = fraction.denominator;
        }
        else
        {
            result.numerator = fraction.integer;
            result.denominator = 1;
        }
        return result;
    }
    return fraction;
}

double turnToDouble(MixedFraction fraction)
{
    if(fraction.numerator && fraction.denominator)
    {
        if(fraction.integer < 0)
        {
            return (double)fraction.integer - (double)fraction.numerator / (double)fraction.denominator;
        }
        else
        {
            return (double)fraction.integer + (double)fraction.numerator / (double)fraction.denominator;
        }
    }
    else
    {
        return (double)fraction.integer;
    }
}

MixedFraction summarize(MixedFraction firstFraction, MixedFraction secondFraction)
{
    MixedFraction impFrac1 = turnToImproper(firstFraction), impFrac2 = turnToImproper(secondFraction), result;

    int lessComMult = lcm(impFrac1.denominator, impFrac2.denominator);

    impFrac1.numerator *= lessComMult / impFrac1.denominator;
    impFrac2.numerator *= lessComMult / impFrac2.denominator;

    impFrac1.denominator = lessComMult;
    impFrac2.denominator = lessComMult;

    result.integer = 0;
    result.numerator = impFrac1.numerator + impFrac2.numerator;
    result.denominator = result.numerator? lessComMult : 0;

    convertFraction(&result);

    return result;
}

MixedFraction deduct(MixedFraction firstFraction, MixedFraction secondFraction)
{
    MixedFraction impFrac1 = turnToImproper(firstFraction), impFrac2 = turnToImproper(secondFraction), result;

    int lessComMult = lcm(impFrac1.denominator, impFrac2.denominator);

    impFrac1.numerator *= lessComMult / impFrac1.denominator;
    impFrac2.numerator *= lessComMult / impFrac2.denominator;

    impFrac1.denominator = lessComMult;
    impFrac2.denominator = lessComMult;

    result.integer = 0;
    result.numerator = impFrac1.numerator - impFrac2.numerator;
    result.denominator = result.numerator? lessComMult : 0;

    convertFraction(&result);

    return result;
}

MixedFraction multiply(MixedFraction firstFraction, MixedFraction secondFraction)
{
    MixedFraction impFrac1 = turnToImproper(firstFraction), impFrac2 = turnToImproper(secondFraction), result;

    int greatComDiv = gcd(impFrac1.numerator, impFrac2.denominator);
    impFrac1.numerator /= greatComDiv;
    impFrac2.denominator /= greatComDiv;

    greatComDiv = gcd(impFrac2.numerator, impFrac1.denominator);
    impFrac2.numerator /= greatComDiv;
    impFrac1.denominator /= greatComDiv;

    result.integer = 0;
    result.numerator = impFrac1.numerator * impFrac2.numerator;
    result.denominator = impFrac1.denominator * impFrac2.denominator;

    convertFraction(&result);

    return result;
}

MixedFraction divide(MixedFraction firstFraction, MixedFraction secondFraction)
{
    MixedFraction impFrac1 = turnToImproper(firstFraction), impFrac2 = turnToImproper(secondFraction), result;

    int temp = impFrac2.numerator;
    impFrac2.numerator = impFrac2.denominator;
    impFrac2.denominator = temp;

    int greatComDiv = gcd(impFrac1.numerator, impFrac2.denominator);
    impFrac1.numerator /= greatComDiv;
    impFrac2.denominator /= greatComDiv;

    greatComDiv = gcd(impFrac2.numerator, impFrac1.denominator);
    impFrac2.numerator /= greatComDiv;
    impFrac1.denominator /= greatComDiv;

    result.integer = 0;
    result.numerator = impFrac1.numerator * impFrac2.numerator;
    result.denominator = impFrac1.denominator * impFrac2.denominator;

    convertFraction(&result);

    return result;
}





