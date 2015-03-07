#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *filepoint;
    int character, vowels = 0, consonants = 0, counter = 1;

    filepoint = fopen("../ExampleOfText.txt", "r");
    if(filepoint == NULL)
    {
        fprintf(stderr, "Cannot open the file.\n");
        exit(1);
    }

    do
    {
        character = fgetc(filepoint);
        if(character == 33 || character == 46 || character == 63)
        {
            if(vowels || consonants)
            {
                if(vowels > consonants)
                    printf("In %d sentence there are more vowels than consonants (%d).\n", counter, vowels);
                else if(vowels < consonants)
                    printf("In %d sentence there are more consonants than vowels (%d).\n", counter, consonants);
                else
                    printf("In %d sentence amounts of vowels and consonants are equal (%d).\n", counter, vowels);
                ++counter;
                vowels = 0;
                consonants = 0;
            }
        }
        else if(character == 65 || character == 69 || character == 73 || character == 79 || character == 85 || character == 89 ||
        character == 97 || character == 101 || character == 105 || character == 111 || character == 117 || character == 121)
        {
            ++vowels;
        }
        else if((character > 65 && character < 91) || (character > 97 && character < 123))
        {
            ++consonants;
        }
    }while(character != EOF);

    fclose(filepoint);
    return 0;
}
