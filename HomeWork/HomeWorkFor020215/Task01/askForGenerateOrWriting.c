#include <assert.h>
#include "../../../modules/include/array.h"

void askForGenerateOrWriting(int array[], int sizeOfPart)
{
    assert(sizeOfPart > 0 && sizeOfPart <= SIZE);
    char answer;
    printf("Do you want to generate random numbers or write your own numbers? (g/w): ");
    scanf(" %c", &answer);
    assert(answer == 'g' || answer == 'w');
    switch (answer)
    {
    case 'g':
        generateRandomNumbersInArray(array, sizeOfPart);
        break;
    case 'w':
        inputArray(array, sizeOfPart);
        break;
    }
}
