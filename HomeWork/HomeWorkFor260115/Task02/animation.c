// TODO include <stdio.h>

void paragraphs(int amount)
{
    if(amount > 0)
    {
        paragraphs(amount - 1);
        printf("\n");
    }
}

void animation(int sizeOfSquare)
{
    int numberOfParagraphs = 0, numberOfSpacesLeft = 0, sizeOfSquareDynamic = sizeOfSquare;
    while(1)
    {
        while(sizeOfSquareDynamic > 0)
        {
            universalClear();
            paragraphs(numberOfParagraphs);
            for(int i = 0; i < sizeOfSquareDynamic; ++i)
            {
                printf("%*s", numberOfSpacesLeft, "");
                for(int j = 0; j < sizeOfSquareDynamic; ++j)
                {
                    printf("#");
                }
                printf("\n");
            }
            sizeOfSquareDynamic -= 2;
            numberOfParagraphs += 1;
            numberOfSpacesLeft += 1;
            universalSleep(0.2);
        }
        while(sizeOfSquareDynamic < sizeOfSquare)
        {
            universalClear();
            paragraphs(numberOfParagraphs);
            for(int i = 0; i < sizeOfSquareDynamic; ++i)
            {
                printf("%*s", numberOfSpacesLeft, "");
                for(int j = 0; j < sizeOfSquareDynamic; ++j)
                {
                    printf("#");
                }
                printf("\n");
            }
            sizeOfSquareDynamic += 2;
            numberOfParagraphs -= 1;
            numberOfSpacesLeft -= 1;
            universalSleep(0.2);
        }
    }
}
