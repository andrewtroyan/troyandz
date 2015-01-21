#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dices.h"
#include "../../../modules/include/compatibility.h"

int main()
{
    srand(time(NULL));
    int humanScore, computerScore;
    char answer;
    printf("Hello! Do you want to play dices? (y/n) ");
    scanf(" %c", &answer);
    if(answer == 'y')
    {
        do
        {
            universalClear();
            printf("You roll the dices...\r");
            universalSleep(3);
            printf("\n");
            humanScore = playDices();
            printf("Computer rolls the dices...\r");
            universalSleep(3);
            printf("\n");
            computerScore = playDices();
            humanScore > computerScore? printf("You won!\n") : (humanScore < computerScore? printf("Computer won!\n") : printf("No sides!\n"));
            printf("Do you want to play again? (y/n) ");
            scanf(" %c", &answer);
        }
        while (answer == 'y');
    }
    printf("Goodbye!");
    return 0;
}
