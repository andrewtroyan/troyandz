#include "Queue.h"

// Та же программа с городами, только с использованием очереди

void showData(Data city)
{
    printf("City: %s, area: %.1f km^2.\n", city.name, city.area);
}

int main()
{
    Queue towns;
    Data *city = (Data *)malloc(sizeof(Data));
    if(!city)
    {
        fprintf(stderr, "No free memory.\n");
        exit(1);
    }

    initializeQueue(&towns);

    printf("Enter the name of the city or \"exit\" for finish: ");
    gets(city->name);
    while(isFull(towns) == false && strcmp(city->name, "exit"))
    {
        printf("Enter the area of this city: ");
        scanf("%lf", &city->area);
        addToQueue(*city, &towns);
        system("clear");
        printf("Enter the name of the city or \"exit\" for finish: ");
        getchar();
        gets(city->name);
    }

    removeFromQueue(&towns); // проверяем удаление узла

    system("clear");

    if(isEmpty(towns))
        printf("You haven't filled any cities.\n");
    else
    {
        printf("You filled:\n");
        workOnNodes(towns, showData);
        printf("You entered %d city(ies).\n", amountOfNodesInQueue(towns));
    }

    clearQueue(&towns);
    free(city);
    city = NULL;

    return 0;
}
