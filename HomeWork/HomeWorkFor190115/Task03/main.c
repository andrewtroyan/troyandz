#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../../modules/include/dices.h"

int main()
{
    srand(time(NULL));
    int humanCurrentScore, computerCurrentScore, humanGeneralScore = 0, computerGeneralScore = 0;
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
            for(int i = 0; i < 2; ++i)
            {
                humanCurrentScore = dicesScore();
                dicesDraw(humanCurrentScore);
                humanGeneralScore += humanCurrentScore;
            }
            for(int i = 0; i < 1000; ++i)
            {
                printf("Computer rolls the dices...\r");
            }
            printf("\n");
            for(int i = 0; i < 2; ++i)
            {
                computerCurrentScore = dicesScore();
                dicesDraw(computerCurrentScore);
                computerGeneralScore += computerCurrentScore;
            }
            humanGeneralScore > computerGeneralScore? printf("You won!\n") : (humanGeneralScore < computerGeneralScore? printf("Computer won!\n") : printf("No sides!\n"));
            printf("Do you want to play again? (y/n) ");
            scanf(" %c", &answer);
        } while (answer == 'y');
    }
    printf("Goodbye!");
    return 0;
}
