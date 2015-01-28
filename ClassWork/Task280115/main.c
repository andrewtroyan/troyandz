#include <stdio.h>
#include <stdlib.h>
#include "../../modules/include/array.h"
#include "searchArray.h"

int main()
{
    int array[SIZE], sizeOfPart, n;
    char answer;
    printf("Enter the size of array (0 < size <= %d): ", SIZE);
    scanf("%d", &sizeOfPart);
    if(sizeOfPart > 0 && sizeOfPart <= SIZE)
    {
        printf("Do you want to generate random numbers or write your own numbers? (g/w): ");
        scanf(" %c", &answer);
        switch (answer)
        {
        case 'g':
            generateRandomNumbersInArray(array, sizeOfPart);
            break;
        case 'w':
            inputArray(array, sizeOfPart);
            break;
        default:
            printf("ERROR");
            exit(1);
        }
        printf("Your array: ");
        outputArrray(array, sizeOfPart);

        n = searchLastNegativeInArray(array, sizeOfPart);
        if(n >= 0)
        {
            printf("The last negative number of array is %d. Its index is %d.\n", array[n], n);
        }
        else
        {
            printf("There's no negative numbers in your array.\n");
        }

        n = searchFirstPositiveInArray(array, sizeOfPart);
        if(n >= 0)
        {
            printf("The first positive number of array is %d. Its index is %d.\n", array[n], n);
        }
        else
        {
            printf("There's no positive numbers in your array.\n");
        }
    }
    else
    {
        printf("ERROR!");
        exit(1);
    }
    return 0;
}
