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
        }

        printf("\nSelect an operation: ");
        scanf("%d", &answer);
    }

    free(towns);
    towns = NULL;
    return 0;
}
