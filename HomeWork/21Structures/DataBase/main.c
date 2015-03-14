#include "dataBaseOperations.h"

int main()
{
    FILE *filepoint;
    Town *towns = NULL;
    towns = (Town *)malloc(MAXAMOUNT * sizeof(Town));
    if(towns == NULL)
    {
        fprintf(stderr, "No free memory.\n");
        exit(1);
    }

    for(int i = 0; i < MAXAMOUNT; ++i)
    {
        strcpy(towns[i].name, "0");
        strcpy(towns[i].country, "0");
        strcpy(towns[i].language, "0");
        towns[i].area = 0;
        towns[i].population = 0;
    }

    int answer, *pointer;
    char charAnswer;

    printf("INSTRUCTIONS:\nDownload data from file before you change it if you don't want to lose information.\n"
           "If a word contains spaces, replace them with \"-\".\n\n"
           "1. Download from binary file\n2. Save to file (binary mode)\n3. Add\n4. Delete\n5. Show\n6. Sort\n7. Exit\n\nSelect an operation: ");

    scanf("%d", &answer);
    while(answer > 0 && answer < 7)
    {
        system("clear");
        printf("INSTRUCTIONS:\nDownload data from file before you change it if you don't want to lose information.\n"
               "If a word contains spaces, replace them with \"-\".\n\n"
               "1. Download from binary file\n2. Save to file (binary mode)\n3. Add\n4. Delete\n5. Show\n6. Sort\n7. Exit\n\n");
        switch(answer)
        {
        case 1:
            downloadFromFile(towns);
            break;
        case 2:
            downloadToFile(towns);
            break;
        case 3:
            if(!addData(towns))
                printf("You filled all free memory.\n");
            break;
        case 4:
            if(!deleteData(towns))
                printf("There's no such a city.\n");
            break;
        case 5:
            showData(towns);
            break;
        case 6:
            printf("Sort for:\n1. Name\n2. Country\n3. Language\n4. Area\n5. Population\n\nSelect: ");
            scanf("%d", &answer);
            switch(answer)
            {
            case 1:
                printf("Order d/u (down/up)... Select: ");
                scanf(" %c", &charAnswer);
                if(charAnswer == 'd')
                    pointer = sortNameFromBigToLittle;
                else
                    pointer = sortNameFromLittleToBig;
                break;
            case 2:
                printf("Order d/u (down/up)... Select: ");
                scanf(" %c", &charAnswer);
                if(charAnswer == 'd')
                    pointer = sortCountryFromBigToLittle;
                else
                    pointer = sortCountryFromLittleToBig;
                break;
            case 3:
                printf("Order d/u (down/up)... Select: ");
                scanf(" %c", &charAnswer);
                if(charAnswer == 'd')
                    pointer = sortLanguageFromBigToLittle;
                else
                    pointer = sortLanguageFromLittleToBig;
                break;
            case 4:
                printf("Order d/u (down/up)... Select: ");
                scanf(" %c", &charAnswer);
                if(charAnswer == 'd')
                    pointer = sortAreaFromBigToLittle;
                else
                    pointer = sortAreaFromLittleToBig;
                break;
            case 5:
                printf("Order d/u (down/up)... Select: ");
                scanf(" %c", &charAnswer);
                if(charAnswer == 'd')
                    pointer = sortPopulationFromBigToLittle;
                else
                    pointer = sortPopulationFromLittleToBig;
                break;
            }
            quickSorting(towns, 0, MAXAMOUNT - 1, pointer);
            break;
        }

        printf("\nSelect an operation: ");
        scanf("%d", &answer);
    }

    free(towns);
    towns = NULL;
    return 0;
}
