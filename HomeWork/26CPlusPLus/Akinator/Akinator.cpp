#include "Akinator.h"

using namespace std;
using namespace tree;
using namespace game;
using namespace file;
using namespace stack;

void tree::addNewFork(Node *oldAnimal, Node *newAnimal, Node *question, bool answer)
{
    if(answer)
    {
        question->yeslink = newAnimal;
        question->nolink = oldAnimal;
    }
    else
    {
        question->yeslink = oldAnimal;
        question->nolink = newAnimal;
    }
    oldAnimal->parent = question;
    newAnimal->parent = question;
}

void tree::hangFork(Node **root, Node *parent, Node *fork, bool wayToChild)
{
    if(!parent)
        *root = fork;
    else
    {
        if(wayToChild)
            parent->yeslink = fork;
        else
            parent->nolink = fork;
        fork->parent = parent;
    }
}

bool tree::determineWayToChild(Node *node)
{
    if(!node || !node->parent)
        return false;
    else
        return node->parent->yeslink == node;
}

void tree::addNewKnowledge(Node **root, Node *destination, char *question, char *newAnimal, bool rightAnswer)
{
    assert(destination);
    Node *questionNode = nullptr, *newAnimalNode = nullptr;
    createNewNode(&questionNode, question, noanimal);
    createNewNode(&newAnimalNode, newAnimal, animal);
    Node *parent = destination->parent;
    bool wayToChild = determineWayToChild(destination);
    addNewFork(destination, newAnimalNode, questionNode, rightAnswer);
    hangFork(root, parent, questionNode, wayToChild);
}

void tree::createNewNode(Node **node, char *str, Type type)
{
    char *p = nullptr;
    p = new char[strlen(str) + 1];
    Node *q = nullptr;
    q = new Node;
    strcpy(p, str);
    q->data.str = p;
    q->data.sizestr = strlen(p) + 1;
    q->data.type = type;
    q->parent = nullptr;
    q->yeslink = nullptr;
    q->nolink = nullptr;
    *node = q;
    p = nullptr;
    q = nullptr;
}

void tree::addNode(Node **root, Node **node, int way, char *str, Type type)
{
    char *p = nullptr;
    p = new char[strlen(str) + 1];
    Node *q = nullptr;
    q = new Node;
    strcpy(p, str);
    q->data.str = p;
    q->data.sizestr = strlen(p) + 1;
    q->data.type = type;
    q->yeslink = nullptr;
    q->nolink = nullptr;
    q->parent = nullptr;
    if(!*root)
        *root = q;
    else
    {
        if(way)
            (*node)->nolink = q;
        else
            (*node)->yeslink = q;
        q->parent = *node;
        *node = q;
    }
    p = nullptr;
    q = nullptr;
}

void tree::addNewInformation(Node **root, Node *destination)
{
    char question[200], animal[50], answer;
    bool reply;
    cout << "Какое животное вы загадали? ";
    //getchar();
    cin >> animal;
    cout << "Какой вопрос характеризует это животное? ";
    cin >> question;
    cout << "Какой правильный ответ на этот вопрос для этого животного? y/n ";
    cin >> answer;
    if(answer == 'y')
        reply = true;
    else
        reply = false;
    cout << "Спасибо за введенные данные! В следующий раз я точно выиграю!" << endl;
    addNewKnowledge(root, destination, question, animal, reply);
}

void tree::clearTree(Node **root)
{
    if(*root)
    {
        Node *temp1 = (*root)->yeslink, *temp2 = (*root)->nolink;
        (*root)->data.sizestr = 0;
        (*root)->data.str = nullptr;
        (*root)->yeslink = nullptr;
        (*root)->nolink = nullptr;
        (*root)->parent = nullptr;
        delete *root;
        *root = nullptr;
        clearTree(&temp1);
        clearTree(&temp2);
    }
}

// -----

Node * game::playGame(Node *root)
{
    Node *p = root;
    while(p->data.type == noanimal)
    {
        cout << p->data.str << endl;
        cout << "Нажми y/n: ";
        char answer;
        cin >> answer;
        if(answer == 'y')
            p = p->yeslink;
        else
            p = p->nolink;
    }
    return p;
}

// -----

void stack::pushToStack(Node *pointer, Stack *stack)
{
    NodeForStack *temp = nullptr;
    temp = new NodeForStack;
    temp->node = pointer;
    temp->link = *stack;

    *stack = temp;
    temp = nullptr;
}

void stack::popFromStack(Stack *stack)
{
    if(*stack)
    {
        NodeForStack *temp = *stack;
        *stack = (*stack)->link;
        temp->node = nullptr;
        temp->link = nullptr;
        delete temp;
        temp = nullptr;
    }
}

bool stack::isStackEmpty(Stack stack)
{
    return !stack;
}

bool stack::onTopOfStack(Node **pointer, Stack stack)
{
    if(!isStackEmpty(stack))
    {
        *pointer = stack->node;
        return true;
    }
    return false;
}

void stack::clearStack(Stack *stack)
{
    while(!isStackEmpty(*stack))
        popFromStack(stack);
}

// -----

bool file::readFromFile(FILE *filepointer, Node **root)
{
    Node *tempPointer = nullptr;
    char *str;
    int way, temp, lengthOfStr;
    Type type;
    fscanf(filepointer, "%d ", &lengthOfStr);
    str = new char[lengthOfStr];
    fgets(str, lengthOfStr, filepointer);
    fscanf(filepointer, "%d\n", &temp);
    if(temp)
        type = noanimal;
    else
        type = animal;
    addNode(root, root, 0, str, type);
    delete [] str;
    str = nullptr;

    tempPointer = *root;

    Stack pointers = nullptr;

    while(!feof(filepointer))
    {
        fscanf(filepointer, "%d %d ", &way, &lengthOfStr);
        str = new char[lengthOfStr];
        fgets(str, lengthOfStr, filepointer);
        fscanf(filepointer, "%d\n", &temp);
        if(temp)
            type = noanimal;
        else
            type = animal;

        if(way)
            pushToStack(tempPointer, &pointers);
        else
        {
            onTopOfStack(&tempPointer, pointers);
            popFromStack(&pointers);
        }
        addNode(root, &tempPointer, way, str, type);
        delete [] str;
        str = nullptr;
    }

    clearStack(&pointers);

    return true;
}

void file::writeToFile(FILE *filepointer, Node *root)
{
    Node *tempPointer = root;
    Stack pointers = nullptr;
    pushToStack(tempPointer, &pointers);
    int way;
    while(!isStackEmpty(pointers))
    {
        onTopOfStack(&tempPointer, pointers);
        popFromStack(&pointers);
        if(tempPointer == root)
            fprintf(filepointer, "%d %s %d\n", tempPointer->data.sizestr, tempPointer->data.str, tempPointer->data.type);
        else
        {
            if(tempPointer->parent->yeslink == tempPointer)
                way = 0;
            else
                way = 1;
            fprintf(filepointer, "%d %d %s %d\n", way, tempPointer->data.sizestr, tempPointer->data.str, tempPointer->data.type);
        }

        if(tempPointer->yeslink && tempPointer->nolink)
        {
            pushToStack(tempPointer->yeslink, &pointers);
            pushToStack(tempPointer->nolink, &pointers);
        }
    }
}

