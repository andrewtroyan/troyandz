
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    while (a % b != 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return b;
}

int lcm(int a, int b)
{
    return a * (b / gcd(a, b));
}

int checkForPrimality(int number)
{
    int indicator = 0;
    for(int i = 2; i * i <= number; i++)
    {
        if(number % i == 0)
            indicator = 1;
    }
    if(indicator)
        return -1;
    else
        return 1;
}
