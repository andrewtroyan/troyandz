#include "timeOperations.h"

int main()
{
    Time currentTime, enteredTime = {0, 0, 0}, firstTime, secondTime;
    int answer;
    long int seconds, result;

    time_t rawtime;
    struct tm *timeinfo;

    printf("Instruction\nEnter the time in this order:\nHOURS:MINUTES:SECONDS.\n\n"
           "Select an operation:\n1. Enter\n2. Show time entered by you\n3. Show current time\n4. Add seconds to the time entered by you\n5. Difference between two moments of time in seconds\n6. Exit\n\n");

    scanf("%d", &answer);
    while(answer > 0 && answer < 6)
    {
        system("clear");
        printf("Instruction\nEnter the time in this order:\nHOURS:MINUTES:SECONDS.\n\n"
               "Select an operation:\n1. Enter\n2. Show time entered by you\n3. Show current time\n4. Add seconds to the time entered by you\n5. Difference between two moments of time in seconds\n6. Exit\n\n");

        switch(answer)
        {
        case 1:
            printf("Enter the time: ");
            enterTime(&enteredTime);
            break;
        case 2:
            printf("Your entered time: ");
            showTime(enteredTime);
            break;
        case 3:
            time (&rawtime);
            timeinfo = localtime (&rawtime);

            currentTime.hours = timeinfo->tm_hour;
            currentTime.minutes = timeinfo->tm_min;
            currentTime.seconds = timeinfo->tm_sec;

            printf("The current time: ");
            showTime(currentTime);
            break;
        case 4:
            printf("Enter the amount of seconds that you want to add to your last entered time: ");
            scanf("%ld", &seconds);
            addSeconds(&enteredTime, seconds);
            printf("The result: ");
            showTime(enteredTime);
            break;
        case 5:
            printf("Enter the first time: ");
            enterTime(&firstTime);
            printf("Enter the second time: ");
            enterTime(&secondTime);
            result = differenceInSeconds(firstTime, secondTime);
            printf("The difference between these two periods is %ld second(s).\n", result);
            break;
        }

        printf("\nSelect an operation: ");
        scanf("%d", &answer);
    }

    return 0;
}

