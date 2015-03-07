#include <stdio.h>
#include <stdlib.h>

int main()
{
    char andrew[]="Andrew", elena[]="Elena", anatoly[]="Anatoly", olga[]="Olga";
    double andrewWeight1, andrewWeight2, elenaWeight1, elenaWeight2, anatolyWeight1, anatolyWeight2, olgaWeight1, olgaWeight2;

    printf("Enter %s's weight before: ", andrew);
    scanf("%lf", &andrewWeight1);
    printf("Enter %s's weight after: ", andrew);
    scanf("%lf", &andrewWeight2);

    printf("Enter %s's weight before: ", elena);
    scanf("%lf", &elenaWeight1);
    printf("Enter %s's weight after: ", elena);
    scanf("%lf", &elenaWeight2);

    printf("Enter %s's weight before: ", anatoly);
    scanf("%lf", &anatolyWeight1);
    printf("Enter %s's weight after: ", anatoly);
    scanf("%lf", &anatolyWeight2);

    printf("Enter %s's weight before: ", olga);
    scanf("%lf", &olgaWeight1);
    printf("Enter %s's weight after: ", olga);
    scanf("%lf", &olgaWeight2);

    printf("%7s | % -.3f\n%7s | % -.3f\n%7s | % -.3f\n%7s | % -.3f", andrew, andrewWeight2-andrewWeight1, elena, elenaWeight2-elenaWeight1, anatoly, anatolyWeight2-anatolyWeight1, olga, olgaWeight2-olgaWeight1);

    return 0;
}
