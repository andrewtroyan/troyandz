#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../modules/include/mathx.h"

#define SIZE 1000

int main()
{
    FILE *filePointer;
    char strTemp[SIZE];
    int amountOfLetters = 0, amountOfSymbols = 0, counter, character;
    fpos_t position;

    filePointer = fopen("../TextToChange.txt", "r+");
    if(filePointer == NULL)
    {
        fprintf(stderr, "Cannot open the file.\n");
        exit(1);
    }

    do
    {
        fgetpos(filePointer, &position);
        character = fgetc(filePointer);
        if((character >= 65 && character <= 90) || (character >= 97 && character <= 122))
        {
            do
            {
                if((character >= 65 && character <= 90) || (character >= 97 && character <= 122))
                {
                    ++amountOfLetters;
                }
                ++amountOfSymbols;
                character = fgetc(filePointer);
            }while((character >= 65 && character <= 90) || (character >= 97 && character <= 122) || (char)character == '\'');
        }

        if(strchr(" .,-;!?\"\n\0", (char)character))
        {
            if(checkForPrimality(amountOfLetters) == 1)
            {
                for(counter = 0; counter < amountOfSymbols; ++counter)
                {
                    strTemp[counter] = '*';
                }
                strTemp[counter] = '\0';
                fsetpos(filePointer, &position);
                fputs(strTemp, filePointer);
            }
            amountOfLetters = 0;
            amountOfSymbols = 0;
        }

    }while(character != EOF);

    rewind(filePointer);

    while(fgets(strTemp, sizeof(strTemp), filePointer))
    {
        puts(strTemp);
    }

    fclose(filePointer);
    return 0;
}
