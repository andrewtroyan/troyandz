#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Hello!\n");
    int answerInt;  // 0 - компьютер угадал, -1 - компьютер выдал маленькое число, 1 - компьютер выдал большое число;
    char answerChar;
    do
    {
        printf("\nImagine the number between 1 and 99.\n");
        int computerNumber;
        srand(time(NULL));
        computerNumber = rand()%99+1;
        printf("%d\n", computerNumber);
        printf("Am I right? (-1/0/1)\n");
        scanf("%d", &answerInt);
        while (answerInt != 0)
        {
            if(answerInt == -1)
            {
                computerNumber = rand()%(99-computerNumber+1)+computerNumber;
            }
            else if(answerInt == 1)
            {
                computerNumber = rand()%computerNumber+1;
            }
            printf("%d\n", computerNumber);
            printf("Am I right? (-1/0/1)\n");
            scanf("%d", &answerInt);
        }
        printf("Congratulations!\nWanna play again with me? (y/n):\n");
        scanf(" %c", &answerChar);
    } while(answerChar == 'y');
    printf("\nIt was pleasant to play with you! Goodbye!\n");
    return 0;
}

