#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Hello!\n");
    int computerNumber;
    char answer;
    do
    {
        srand(time(NULL));
        computerNumber = rand()%99+1;
        int userNumber = 0, shot = 0;                      //shot - попытка
        printf("\nEnter the number from 1 to 99:\n");
        while (userNumber != computerNumber)
        {
            scanf("%d", &userNumber);
            if(userNumber > computerNumber)
            {
                printf("Too big!\n");
            }
            else if(userNumber < computerNumber)
            {
                printf("Too little!\n");
            }
            ++shot;
        }
        printf("You won! You tried for %d time(s). Do you want to play again? (y/n):\n", shot);
        scanf(" %c", &answer);
    } while(answer == 'y');
    printf("\nGoodbye!");
    return 0;
}





