#include "TextEditor.h"

void setWindows(WINDOW **wnd1, WINDOW **wnd2, WINDOW **wnd3, int rows, int cols)
{
    initialiseProgram();
    refresh();
    *wnd1 = newwin(1, cols, 0, 0);
    *wnd2 = newwin(rows - 4, cols, 1, 0);
    *wnd3 = newwin(3, cols, rows - 3, 0);
    wbkgd(*wnd1, A_REVERSE);
    wbkgd(*wnd3, A_REVERSE);
    wattron(*wnd2, A_BOLD);
    wprintw(*wnd1, "Text Editor by Andrew Troyan");
    wprintw(*wnd3, "Operating commands:\n");
    wrefresh(*wnd1);
    wrefresh(*wnd2);
    wrefresh(*wnd3);
}

void deleteWindows(WINDOW **wnd1, WINDOW **wnd2, WINDOW **wnd3)
{
    delwin(*wnd1);
    delwin(*wnd2);
    delwin(*wnd3);
    endwin();
}

bool createLineNode(LineNode **line)
{
    LineNode *temp = (LineNode *)malloc(sizeof(LineNode));
    if(!temp)
        return false;
    temp->pointer = NULL;
    temp->next = NULL;
    temp->previous = NULL;
    temp->amountOfSigns = 0;
    temp->indicator = general;
    *line = temp;
    temp = NULL;
    return true;
}

bool createTextNode(TextNode **text)
{
    TextNode *temp = (TextNode *)malloc(sizeof(TextNode));
    if(!temp)
        return false;
    temp->indicator= general;
    temp->next = NULL;
    temp->previous = NULL;
    temp->sign = '\0';
    *text = temp;
    temp = NULL;
    return true;
}

/*void deleteLineNode(LineNode *lines, LineNode *lineToDelete)
{
    if(lineToDelete != lines)
    {
        lineToDelete->previous->amountOfSigns += lineToDelete->amountOfSigns;
        lineToDelete->previous->indicator = current;
        lineToDelete->previous->next = lineToDelete->next;
        lineToDelete->next->previous = lineToDelete->previous;
        lineToDelete->amountOfSigns = 0;
        lineToDelete->indicator = general;
        lineToDelete->next = NULL;
        lineToDelete->previous = NULL;
        lineToDelete->pointer = NULL;
        free(lineToDelete);
        lineToDelete = NULL;
    }
}

void deleteTextNode(TextNode *text, TextNode *currentNode)
{
    if(currentNode != text)
    {
        TextNode *nodeToDelete = currentNode->previous;
        nodeToDelete->previous->next = nodeToDelete->next;
        nodeToDelete->next->previous = nodeToDelete->previous;
        nodeToDelete->next = NULL;
        nodeToDelete->previous = NULL;
        nodeToDelete->sign = 32;
        free(nodeToDelete);
        nodeToDelete = NULL;
    }
}

bool insertSign(LineNode *lines, int symbol)
{
    LineNode *linesTemp = lines;
    while(linesTemp->indicator != current)
        linesTemp = linesTemp->next;

    TextNode *textTemp = linesTemp->pointer;
    while(textTemp->indicator != current)
        textTemp = textTemp->next;

    TextNode *insertNode = createTextNode();
    if(!insertNode)
        return false;
    insertNode->sign = symbol;
    insertNode->previous = textTemp->previous;
    insertNode->next = textTemp;
    if(linesTemp->pointer == textTemp)
        linesTemp->pointer = insertNode;
    ++(linesTemp->amountOfSigns);
    textTemp = insertNode = NULL;
    linesTemp = NULL;
    return true;
}

void deleteSign(LineNode *lines, TextNode *text)
{
    LineNode *linesTemp = lines;
    while(linesTemp->indicator != current)
        linesTemp = linesTemp->next;

    TextNode *textTemp = linesTemp->pointer;
    while(textTemp->indicator != current)
        textTemp = textTemp->next;

    if(linesTemp->pointer == textTemp && lines != linesTemp)
        deleteLineNode(lines, linesTemp);
    else
        deleteTextNode(text, textTemp);
    linesTemp = NULL;
    textTemp = NULL;
}*/

bool startWork(LineNode **lines, TextNode **text)
{
    if(!createLineNode(lines))
        return false;
    if(!createTextNode(text))
    {
        free(*lines);
        *lines = NULL;
        return false;
    }
    (*text)->indicator = current;
    (*text)->sign = '\0';
    (*lines)->amountOfSigns = 1;
    (*lines)->pointer = *text;
    (*lines)->indicator = current;
    return true;
}

bool insertSign(LineNode **lines, TextNode **text, int symbol)
{
    LineNode *lineTemp = *lines;
    while(lineTemp->indicator != current)
        lineTemp = lineTemp->next;

    TextNode *textTemp = lineTemp->pointer;
    while(textTemp->indicator != current)
        textTemp = textTemp->next;

    TextNode *nodeToInsert = NULL;
    if(!createTextNode(&nodeToInsert))
        return false;

    nodeToInsert->sign = symbol;
    nodeToInsert->next = textTemp;
    nodeToInsert->previous = textTemp->previous;
    if(textTemp->previous)
        textTemp->previous->next = nodeToInsert;
    textTemp->previous = nodeToInsert;

    if(textTemp == *text)
        *text = nodeToInsert;
    if(lineTemp->pointer == textTemp)
        lineTemp->pointer = nodeToInsert;

    ++(lineTemp->amountOfSigns);

    textTemp = nodeToInsert = NULL;
    lineTemp = NULL;
    return true;
}

bool pressEnter(LineNode **lines, TextNode **text)
{
    LineNode *lineTemp = *lines;
    TextNode *textTemp = NULL;

    while(lineTemp->indicator != current)
        lineTemp = lineTemp->next;
    textTemp = lineTemp->pointer;
    while(textTemp->indicator != current)
        textTemp = textTemp->next;

    TextNode *newNode = NULL;
    if(!createTextNode(&newNode))
        return false;
    newNode->sign = '\n';
    newNode->next = textTemp;
    newNode->previous = textTemp->previous;
    if(textTemp->previous)
        textTemp->previous->next = newNode;
    textTemp->previous = newNode;
    ++(lineTemp->amountOfSigns);

    int amount = 0;
    bool indicator = false;
    TextNode *test = lineTemp->pointer;
    for(int i = 0; i < lineTemp->amountOfSigns; ++i, test = test->next)
    {
        if(test->indicator == current)
            indicator = true;
        if(indicator)
            ++amount;
    }

    LineNode *newLine = NULL;
    if(!createLineNode(&newLine))
        return false;
    newLine->pointer = textTemp;
    newLine->amountOfSigns = amount;
    lineTemp->amountOfSigns -= amount;
    newLine->indicator = current;
    lineTemp->indicator = general;
    newLine->previous = lineTemp;
    newLine->next = lineTemp->next;
    if(lineTemp->next)

        lineTemp->next->previous = newLine;
    lineTemp->next = newLine;

    lineTemp = newLine = NULL;
    textTemp = newNode = test = NULL;
    return true;
}

void showTheText(WINDOW *wnd, LineNode *lines, TextNode *text)
{
    LineNode *linesTemp = lines;
    TextNode *textTemp = text;
    wclear(wnd);
    for(int i = 0; linesTemp; ++i, linesTemp = linesTemp->next)
    {
        for(int j = 0; j < linesTemp->amountOfSigns && textTemp; ++j, textTemp = textTemp->next)
        {
            move(i, j);
            if(textTemp->indicator == current)
                wattron(wnd, A_REVERSE);

            if(textTemp->sign == '\n' || textTemp->sign == '\0')
                wprintw(wnd, " ");
            else
                wprintw(wnd, "%c", textTemp->sign);

            if(textTemp->indicator == current)
                wattroff(wnd, A_REVERSE);
        }
    }
    wrefresh(wnd);
}

void clearLines(LineNode **lines)
{
    LineNode *temp = NULL;
    while(*lines)
    {
        temp = *lines;
        *lines = (*lines)->next;
        temp->amountOfSigns = 0;
        temp->pointer = NULL;
        temp->next = NULL;
        temp->previous = NULL;
        free(temp);
        temp = NULL;
    }
}

void clearText(TextNode **text)
{
    TextNode *temp = NULL;
    while(*text)
    {
        temp = *text;
        *text = (*text)->next;
        temp->sign = 0;
        temp->next = NULL;
        temp->previous = NULL;
        free(temp);
        temp = NULL;
    }
}
