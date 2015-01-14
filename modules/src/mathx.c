
int gcd(int a, int b)
{
    if (b == 0)
        return a;
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
