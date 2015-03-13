#include "dataBaseOperations.h"

void downloadFromFile(Town *towns)
{
    FILE *filepoint;
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
}

void downloadToFile(Town *towns)
{
    FILE *filepoint;
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
}

bool addData(Town *towns)
{
    for(int i = 0; i < MAXAMOUNT; ++i)
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
            return true;
        }
    }
    return false;
}

bool deleteData(Town *towns)
{
    char check[MAXSTR];
    bool indicator = false;

    printf("Enter the mame of city that you want to delete: ");
    scanf("%s", &check);
    for(int i = 0; i < MAXAMOUNT; ++i)
    {
        if(strcmp(towns[i].name, check) == 0)
        {
            strcpy(towns[i].name, "0");
            strcpy(towns[i].country, "0");
            strcpy(towns[i].language, "0");
            towns[i].area = 0;
            towns[i].population = 0;
            indicator = true;
        }
    }
    if(indicator == true)
        return true;
    else
        return false;
}

void showData(Town *towns)
{
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
}

void quickSorting(Town *array, int indexOfTheStart, int indexOfTheEnd, bool (*function)(Town, Town))
{
    if(indexOfTheStart < indexOfTheEnd)
    {
        int i = indexOfTheStart;
        while(function(array[i], array[indexOfTheEnd]))
        {
            ++i;
        }
        for(int j = i; j < indexOfTheEnd; ++j)
        {
            if(function(array[i], array[indexOfTheEnd]))
            {
                Town temporary = array[j];
                array[j] = array[i];
                array[i] = temporary;
                ++i;
            }
        }
        Town temporary = array[i];
        array[i] = array[indexOfTheEnd];
        array[indexOfTheEnd] = temporary;
        quickSorting(array, indexOfTheStart, i - 1, function);
        quickSorting(array, i + 1, indexOfTheEnd, function);
    }
}

bool sortNameFromLittleToBig(Town structure1, Town structure2)
{
    if(strcmp(structure1.name, structure2.name) < 0)
        return true;
    else
        return false;
}

bool sortNameFromBigToLittle(Town structure1, Town structure2)
{
    if(strcmp(structure1.name, structure2.name) > 0)
        return true;
    else
        return false;
}

bool sortCountryFromLittleToBig(Town structure1, Town structure2)
{
    if(strcmp(structure1.country, structure2.country) < 0)
        return true;
    else
        return false;
}

bool sortCountryFromBigToLittle(Town structure1, Town structure2)
{
    if(strcmp(structure1.country, structure2.country) > 0)
        return true;
    else
        return false;
}

bool sortLanguageFromLittleToBig(Town structure1, Town structure2)
{
    if(strcmp(structure1.language, structure2.language) < 0)
        return true;
    else
        return false;
}

bool sortLanguageFromBigToLittle(Town structure1, Town structure2)
{
    if(strcmp(structure1.language, structure2.language) > 0)
        return true;
    else
        return false;
}

bool sortAreaFromLittleToBig(Town structure1, Town structure2)
{
    return structure1.area < structure2.area;
}

bool sortAreaFromBigToLittle(Town structure1, Town structure2)
{
    return structure1.area > structure2.area;
}

bool sortPopulationFromLittleToBig(Town structure1, Town structure2)
{
    return structure1.population < structure2.population;
}

bool sortPopulationFromBigToLittle(Town structure1, Town structure2)
{
    return structure1.population > structure2.population;
}




