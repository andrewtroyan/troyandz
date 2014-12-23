#include <stdio.h>
#include <stdlib.h>

int main()
{
    char answer;
    printf("If you want to see the details, press \"y\": ");
    scanf("%c", &answer);
    system("cls");
    if (answer == 'y')
    {
        int Sasha = 1000, Vasya = 1000, SashaTotalBefore = Sasha * 10000, SashaTotalAfter = Sasha * 10000,  VasyaTotal = Vasya * 10000;
        printf("%s%7s%12s\n\n", "Quarter:", "Sasha:", "Vasya:");
        int i = 1;
        while (SashaTotalAfter >= VasyaTotal)
        {
            int centsSasha = 0, dollarsSasha = 0, centsVasya = 0, dollarsVasya = 0;
            SashaTotalAfter += SashaTotalBefore * 6 / 100;
            dollarsSasha = SashaTotalAfter / 10000;
            centsSasha = SashaTotalAfter % 10000;
            VasyaTotal += VasyaTotal * 4 / 100;
            dollarsVasya = VasyaTotal / 10000;
            centsVasya = VasyaTotal % 10000;
            printf("%5d%8d.%04d%7d.%04d\n", i, dollarsSasha, centsSasha, dollarsVasya, centsVasya);
            ++i;
        }
        for (int k = i + 2; i < k; ++i)
        {
            int centsSasha = 0, dollarsSasha = 0, centsVasya = 0, dollarsVasya = 0;
            SashaTotalAfter += SashaTotalBefore * 6 / 100;
            dollarsSasha = SashaTotalAfter / 10000;
            centsSasha = SashaTotalAfter % 10000;
            VasyaTotal += VasyaTotal * 4 / 100;
            dollarsVasya = VasyaTotal / 10000;
            centsVasya = VasyaTotal % 10000;
            printf("%5d%8d.%04d%7d.%04d\n", i, dollarsSasha, centsSasha, dollarsVasya, centsVasya);
        }
        printf("\nVasya will become richer than Sasha in %d quarters.\n", i - 3);
    }
    printf("\nGoodbye!\n");
    return 0;
}
