#include <stdio.h>
#include <stdlib.h>

int main()
{
    char mama[]="mama", mila[]="mila", ramu[]="ramu";
    printf("%s %s %s\n", mama, mila, ramu);
    printf("%s %s %s\n", mama, ramu, mila);
    printf("%s %s %s\n", mila, mama, ramu);
    printf("%s %s %s\n", mila, ramu, mama);
    printf("%s %s %s\n", ramu, mama, mila);
    printf("%s %s %s", ramu, mila, mama);

    return 0;
}
