#include "timeOperations.h"

int main()
{
    Time commonTime = {0, 0, 0}, firstTime, secondTime;
    int answer;
    long int seconds, result;

    printf("Instruction\nEnter the time in this order:\nHOURS:MINUTES:SECONDS.\n\n"
           "Select an operation:\n1. Enter\n2. Show\n3. Add seconds to the time\n4. Difference between two moments of time in seconds\n5. Exit\n\n");

    scanf("%d", &answer);
    while(answer > 0 && answer < 5)
    {
        system("clear");
        printf("Instruction\nEnter the time in this order:\nHOURS:MINUTES:SECONDS.\n\n"
               "Select an operation:\n1. Enter\n2. Show\n3. Add seconds to the time\n4. Difference between two moments of time in seconds\n5. Exit\n\n");

        switch(answer)
        {
        case 1:
            printf("Enter the time: ");
            enterTime(&commonTime);
            break;
        case 2:
            printf("Your entered time: ");
            showTime(commonTime);
            break;
        case 3:
            printf("Enter the amount of seconds that you want to add to your last entered time: ");
            scanf("%d", &seconds);
            addSeconds(&commonTime, seconds);
            printf("The result: ");
            showTime(commonTime);
            break;
        case 4:
            printf("Enter the first time: ");
            enterTime(&firstTime);
            printf("Enter the second time: ");
            enterTime(&secondTime);
            result = differenceInSeconds(firstTime, secondTime);
            printf("The difference between these two periods is %d second(s).\n", result);
            break;
        }

        printf("\nSelect an operation: ");
        scanf("%d", &answer);
    }

    return 0;
}

