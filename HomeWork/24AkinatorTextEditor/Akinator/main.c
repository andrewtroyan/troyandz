#include "Akinator.h"

int main()
{
    /*Node *root = NULL;
    createNewNode(&root, "кот", animal);
    addNewKnowledge(&root, root, "Оно живёт в воде?", "кит", true);
    Node *p = playGame(root);
    printf("Это %s. Я угадала?\n", p->data.str);
    char answer;
    scanf(" %c", &answer);
    if(answer == 'y')
        printf("Я победила!\n");
    else
        printf("Я проиграла!\n");*/
// -----
    FILE *filepointer = NULL;
    filepointer = fopen("Example.txt", "r");
    if(!filepointer)
    {
        fprintf(stderr, "Cannot open the file.\n");
        exit(1);
    }
// -----
    Node *root = NULL;
    char *str;
    int way, temp, lengthOfStr;
    Type type;
    fscanf(filepointer, "%d ", &lengthOfStr);
    str = (char *)malloc(lengthOfStr * sizeof(char));
    if(!str)
    {
        fclose(filepointer);
        fprintf(stderr, "No free memory.\n");
        exit(1);
    }
    fgets(str, lengthOfStr, filepointer);
    fscanf(filepointer, "%d\n", &temp);
    if(temp)
        type = noanimal;
    else
        type = animal;
    AddNode2(&root, &root, 0, str, type);
    free(str);
    str = NULL;

    Node *tempPointer = root;
    /*fscanf(filepointer, "%d %d ", &way, &lengthOfStr);
    str = (char *)malloc(lengthOfStr * sizeof(char));
    if(!str)
    {
        fclose(filepointer);
        fprintf(stderr, "No free memory.\n");
        exit(1);
    }
    fgets(str, lengthOfStr, filepointer);
    fscanf(filepointer, "%d\n", &temp);
    if(temp)
        type = noanimal;
    else
        type = animal;
    AddNode2(&root, &tempPointer, way, str, type);
    free(str);
    str = NULL;
    printf("%d %d %s %d", way, tempPointer->data.sizestr, tempPointer->data.str, tempPointer->data.type);*/
// -----
    while(!feof(filepointer))
    {
        fscanf(filepointer, "%d %d ", &way, &lengthOfStr);
        str = (char *)malloc(lengthOfStr * sizeof(char));
        if(!str)
        {
            fclose(filepointer);
            fprintf(stderr, "No free memory.\n");
            exit(1);
        }
        fgets(str, lengthOfStr, filepointer);
        fscanf(filepointer, "%d\n", &temp);
        if(temp)
            type = noanimal;
        else
            type = animal;
        AddNode2(&root, &tempPointer, way, str, type);
        free(str);
        str = NULL;
    }
// -----
    Node *p = playGame(root);
    printf("Это %s. Я угадала?\n", p->data.str);
    char answer;
    scanf(" %c", &answer);
    if(answer == 'y')
        printf("Я победила!\n");
    else
        printf("Я проиграла!\n");
// -----
    fclose(filepointer);
    return 0;
}


