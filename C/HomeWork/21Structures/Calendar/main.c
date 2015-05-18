#include "calendarOperations.h"

int main()
{
    Date currentDate, enteredDate = {0, 0, 0}, firstDate, secondDate;
    int answer;
    long int days, result;

    time_t rawdate;
    struct tm *dateinfo;

    printf("Instruction\nEnter the date in this order:\nYEAR:MONTH:DAY.\n\n"
           "Select an operation:\n1. Enter\n2. Show date entered by you\n3. Show current date\n4. Add days to the date entered by you\n5. Difference between two dates in days\n6. Exit\n\n");

    scanf("%d", &answer);
    while(answer > 0 && answer < 6)
    {
        system("clear");
        printf("Instruction\nEnter the date in this order:\nYEAR:MONTH:DAY.\n\n"
               "Select an operation:\n1. Enter\n2. Show date entered by you\n3. Show current date\n4. Add days to the date entered by you\n5. Difference between two dates in days\n6. Exit\n\n");

        switch(answer)
        {
        case 1:
            printf("Enter the date: ");
            while(enterDate(&enteredDate))
            {
                printf("Try again: ");
            }
            break;
        case 2:
            printf("Your entered date: ");
            showDate(enteredDate);
            break;
        case 3:
            time (&rawdate);
            dateinfo = localtime (&rawdate);

            currentDate.year = dateinfo->tm_year + 1900;
            currentDate.month = dateinfo->tm_mon + 1;
            currentDate.day = dateinfo->tm_mday;

            printf("The current date: ");
            showDate(currentDate);
            break;
        case 4:
            printf("Enter the amount of days that you want to add to your last entered date: ");
            scanf("%ld", &days);
            addDays(&enteredDate, days);
            printf("The result: ");
            showDate(enteredDate);
            break;
        case 5:
            printf("Enter the first date: ");
            enterDate(&firstDate);
            printf("Enter the second date: ");
            enterDate(&secondDate);
            result = differenceInDays(firstDate, secondDate);
            printf("The difference between these two periods is %ld day(s).\n", result);
            break;
        }

        printf("\nSelect an operation: ");
        scanf("%d", &answer);
    }

    return 0;
}

