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
        int computerNumber, startNumber = 1, endNumber = 99;
        srand(time(NULL));
        do
        {
            computerNumber = rand()%(endNumber - startNumber + 1) + startNumber;
            printf("%d\n", computerNumber);
            printf("Am I right? (-1/0/1)\n");
            scanf("%d", &answerInt);
            if(answerInt == -1)
            {
                startNumber = computerNumber + 1;
            }
            else if(answerInt == 1)
            {
                endNumber = computerNumber - 1;
            }
        } while(answerInt != 0);
        printf("\nCongratulations!\nWanna play again with me? (y/n):\n");
        scanf(" %c", &answerChar);
    } while(answerChar == 'y');
    printf("\nIt was pleasant to play with you! Goodbye!\n");
    return 0;
}

