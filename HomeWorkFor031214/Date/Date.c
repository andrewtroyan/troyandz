#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hour1, minute1, second1;
    printf("Enter hh mm ss (with a space between): ");
    scanf("%d", &hour1);
    scanf("%2d", &minute1);
    scanf("%2d", &second1);

    int hour2, minute2, second2;
    printf("Enter hh mm ss (with a space between): ");
    scanf("%d", &hour2);
    scanf("%2d", &minute2);
    scanf("%2d", &second2);

    int hour3, minute3, second3;
    printf("Enter hh mm ss (with a space between): ");
    scanf("%d", &hour3);
    scanf("%2d", &minute3);
    scanf("%2d", &second3);

    printf("%02d:%02d:%02d\n", hour1, minute1, second1);
    printf("%02d:%02d:%02d\n", hour2, minute2, second2);
    printf("%02d:%02d:%02d", hour3, minute3, second3);

    return 0;
}
