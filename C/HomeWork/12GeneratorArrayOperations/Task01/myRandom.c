#define FIRSTNUMBER 1 //0 <= FIRSTNUMBER < m

int random()
{
    static int x = FIRSTNUMBER;
    x = (3613 * x + 45289) % 214326; //( (a * x + c) % m )
    return x;
}

int myRandom()
{
    static int number = FIRSTNUMBER;
    number = (3301 * number + 39679) % 653400;
    return number;
}






