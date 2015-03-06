
void toAnotherNumberSystem(int decimalNumber, int numberSystem)
{
    int anotherSystemNumber, indicator = 1;
    while (indicator <= decimalNumber)
    {
        indicator *= numberSystem;
    }
    indicator /= numberSystem;
    while (indicator != 0)
    {
        anotherSystemNumber = decimalNumber / indicator;
        anotherSystemNumber <= 9? printf("%d", anotherSystemNumber) : printf("%c", 55 + anotherSystemNumber);
        decimalNumber %= indicator;
        indicator /= numberSystem;
    }
}
