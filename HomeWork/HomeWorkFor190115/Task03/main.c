#include <stdio.h>
#include <stdlib.h>
#include "../../../modules/include/bones.h"

int main()
{
    int humanScore, computerScore;
    char answer;
    printf("Hello! Do you want to play bones? (y/n) ");
    scanf(" %c", &answer);
    if(answer == 'y')
    {
        do
        {
            system("cls");
            for(int i = 0; i < 1000; ++i)
            {
                printf("You roll the dice...\r");
            }
            printf("\n");
            humanScore = bonesScore();
            for(int i = 0; i < 1000; ++i)
            {
                printf("Computer rolls the dice...\r");
            }
            printf("\n");
            computerScore = bonesScore();
            humanScore > computerScore? printf("You won!\n") : (humanScore < computerScore? printf("Computer won!\n") : printf("No sides!\n"));
            printf("Do you want to pay again? (y/n) ");
            scanf(" %c", &answer);
        } while (answer == 'y');
    }
    printf("Goodbye!");
    return 0;
}
