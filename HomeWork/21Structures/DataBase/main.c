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

    bool indicator;
    char check[MAXSTR];
    int answer;
    printf("Select an operation:\n1. Download from file\n2. Save to file\n3. Add\n4. Delete\n5. Show\n6. Sort\n7. Exit\n\n");

    scanf("%d", &answer);
    while(answer > 0 && answer < 7)
    {
        system("clear");
        printf("Select an operation:\n1. Download from file\n2. Save to file\n3. Add\n4. Delete\n5. Show\n6. Sort\n7. Exit\n\n");

        switch(answer)
        {
        case 1:
            filepoint = fopen("Towns.bin", "rb");
            if(filepoint == NULL)
            {
                fprintf(stderr, "Cannot open the file.\n");
                exit(1);
            }

            for(int i = 0; i < MAXAMOUNT && !feof(filepoint); ++i)
            {
                fread(&towns[i], sizeof(Town), 1, filepoint);
            }

            fclose(filepoint);
            break;
        case 2:
            filepoint = fopen("Towns.bin", "wb");
            if(filepoint == NULL)
            {
                fprintf(stderr, "Cannot open the file.\n");
                exit(1);
            }
            for(int i = 0; i < MAXAMOUNT; ++i)
            {
                if(strcmp(towns[i].name, "0"))
                {
                    fwrite(&towns[i], sizeof(Town), 1, filepoint);
                }
            }
            fclose(filepoint);
            break;
        case 3:
            indicator = true;
            for(int i = 0; i < MAXAMOUNT && indicator == true; ++i)
            {
                if(strcmp(towns[i].name, "0") == 0)
                {
                    printf("Enter the name of city: ");
                    getchar(); //у меня вводится невидимый символ, поэтому добавил эту функцию
                    gets(&towns[i].name);
                    printf("Enter the country where this city is located: ");
                    gets(&towns[i].country);
                    printf("Enter the language that people speak in this city: ");
                    gets(&towns[i].language);
                    printf("Enter the area of city: ");
                    scanf("%lf", &towns[i].area);
                    printf("Enter the population of city: ");
                    scanf("%ld", &towns[i].population);
                    indicator = false;
                }
            }
            if(indicator == true)
            {
                printf("You filled all free memory.\n");
            }
            break;
        case 4:
            printf("Enter the mame of city that you want to delete: ");
            scanf("%s", &check);
            indicator = true;
            for(int i = 0; i < MAXAMOUNT; ++i)
            {
                if(strcmp(towns[i].name, check) == 0)
                {
                    strcpy(towns[i].name, "0");
                    strcpy(towns[i].country, "0");
                    strcpy(towns[i].language, "0");
                    towns[i].area = 0;
                    towns[i].population = 0;
                    indicator = false;
                }
            }
            if(indicator == true)
            {
                printf("There's no such a city.\n");
            }
            break;
        case 5:
            printf("+--------------------+--------------------+--------------------+------------------------+----------------------+\n");
            printf("|        Name        |      Country       |      Language      |       Area (km^2)      |      Population      |\n");
            printf("+--------------------+--------------------+--------------------+------------------------+----------------------+\n");
            for(int i = 0; i < MAXAMOUNT; ++i)
            {
                if(strstr(towns[i].name, "0") == 0)
                {
                    printf("%s%-20s%s%-20s%s%-20s%s%-24.1f%s%-20ld%s\n", " ", towns[i].name, " ", towns[i].country, " ", towns[i].language, " ", towns[i].area, " ", towns[i].population, " ");
                }
            }
            break;
        }

        printf("\nSelect an operation: ");
        scanf("%d", &answer);
    }

    free(towns);
    towns = NULL;
    return 0;
}
