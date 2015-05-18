#include "List.h"

//Программа для ввода названий городов, их площади и вывода данных на экран

void showData(Data city)
{
    printf("City: %s, area: %.1f km^2.\n", city.name, city.area);
}

int main()
{
    List towns;
    initializeList(&towns);
    Data *data = (Data *)malloc(sizeof(Data));
    if(!data)
    {
        fprintf(stderr, "No free memory.\n");
        exit(1);
    }

    printf("Enter the name of the city or \"exit\" for finish: ");
    gets(data->name);
    while(isFull(towns) == false && strcmp(data->name, "exit"))
    {
        printf("Enter the area of this city: ");
        scanf("%lf", &data->area);
        addToList(*data, &towns);
        system("clear");
        printf("Enter the name of the city or \"exit\" for finish: ");
        getchar();
        gets(data->name);
    }

    system("clear");

    if(isEmpty(towns))
        printf("You haven't filled any cities.\n");
    else
    {
        printf("You filled:\n");
        workOnNodes(towns, showData);
        printf("You entered %d city(ies).", amountOfNodes(towns));
    }

    clearTheList(&towns);
    free(data);
    data = NULL;

    return 0;
}
