#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../../modules/include/dices.h"

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
            system("cls");
            for(int i = 0; i < 1000; ++i)
            {
                printf("You roll the dices...\r");
            }
            printf("\n");
            humanScore = playDices();
            for(int i = 0; i < 1000; ++i)
            {
                printf("Computer rolls the dices...\r");
            }
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