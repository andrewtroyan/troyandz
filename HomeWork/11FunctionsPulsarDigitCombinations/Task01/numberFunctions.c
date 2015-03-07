int amountOfDigitsInNumber(int number)
{
    int amountOfDigits = 0;
    if(number == 0)
    {
        return 1;
    }
    else
    {
        while (number)
        {
            amountOfDigits += 1;
            number /= 10;
        }
    }
    return amountOfDigits;
}

int firstDigitInNmuber(int number)
{
    int indicator = 1;
    if(number == 0)
    {
        return 0;
    }
    else
    {
        while(indicator <= number)
        {
            indicator *= 10;
        }
        indicator /= 10;
    }
    return number / indicator;
}

int allDigitsExceptFirst(int number)
{
    int indicator = 1;
    if(number == 0)
    {
        return 0;
    }
    else
    {
        while(indicator <= number)
        {
            indicator *= 10;
        }
        indicator /= 10;
    }
    return number % indicator;
}

int compoundDigit(int number, int digit)
{
    return number * 10 + digit;
}

int cycleShift(int number)
{
    return allDigitsExceptFirst(number) * 10 + firstDigitInNmuber(number);
}
