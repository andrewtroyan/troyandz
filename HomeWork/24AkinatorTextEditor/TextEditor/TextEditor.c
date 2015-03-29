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

void showTheText(WINDOW *wnd, LineNode *lines, TextNode *text)
{
    wclear(wnd);
    LineNode *linesTemp = lines;
    TextNode *textTemp = text;
    for(int i = 0; linesTemp; ++i, linesTemp = linesTemp->next)
    {
        for(int j = 0; j < linesTemp->amountOfSigns && textTemp; ++j, textTemp = textTemp->next)
        {
            wmove(wnd, i, j);
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
    if(!insertSign(lines, text, '\n'))
        return false;

    LineNode *lineTemp = *lines;
    while(lineTemp->indicator != current)
        lineTemp = lineTemp->next;

    TextNode *textTemp = lineTemp->pointer;
    while(textTemp->indicator != current)
        textTemp = textTemp->next;

    int amount = 0;
    bool state = false;
    TextNode *test = lineTemp->pointer;
    for(int i = 0; i < lineTemp->amountOfSigns; ++i, test = test->next)
    {
        if(test->indicator == current)
            state = true;
        if(state)
            ++amount;
    }

    LineNode *newLine = NULL;
    if(!createLineNode(&newLine))
        return false;

    lineTemp->amountOfSigns -= amount;
    lineTemp->indicator = general;
    newLine->pointer = textTemp;
    newLine->amountOfSigns = amount;
    newLine->indicator = current;
    newLine->previous = lineTemp;
    newLine->next = lineTemp->next;
    if(lineTemp->next)
        lineTemp->next->previous = newLine;
    lineTemp->next = newLine;

    lineTemp = newLine = NULL;
    textTemp = test = NULL;
    return true;
}

bool deleteSign(LineNode **lines, TextNode **text)
{
    LineNode *linesTemp = *lines;
    while(linesTemp->indicator != current)
        linesTemp = linesTemp->next;

    TextNode *textTemp = linesTemp->pointer;
    while(textTemp->indicator != current)
        textTemp = textTemp->next;

    if((*lines)->pointer != textTemp)
    {
        if(linesTemp->pointer == textTemp)
        {
            if(!deleteLineNode(lines, text))
            {
                linesTemp = NULL;
                textTemp = NULL;
                return false;
            }
        }
        else
        {
            if(!deleteTextNode(lines, text))
            {
                linesTemp = NULL;
                textTemp = NULL;
                return false;
            }
        }
        linesTemp = NULL;
        textTemp = NULL;
        return true;
    }
    linesTemp = NULL;
    textTemp = NULL;
    return false;
}

bool deleteTextNode(LineNode **lines, TextNode **text)
{
    LineNode *linesTemp = *lines;
    while(linesTemp->indicator != current)
        linesTemp = linesTemp->next;

    TextNode *textTemp = linesTemp->pointer;
    while(textTemp->indicator != current)
        textTemp = textTemp->next;

    if(linesTemp->pointer != textTemp)
    {
        TextNode *nodeToDelete = textTemp->previous;
        textTemp->previous = nodeToDelete->previous;
        if(*text == nodeToDelete)
        {
            *text = textTemp;
            linesTemp->pointer = textTemp;
        }
        else
            nodeToDelete->previous->next = textTemp;
        if(linesTemp->pointer == nodeToDelete)
            linesTemp->pointer = textTemp;
        --(linesTemp->amountOfSigns);
        nodeToDelete->sign = 0;
        nodeToDelete->next = NULL;
        nodeToDelete->previous = NULL;
        free(nodeToDelete);
        nodeToDelete = NULL;
        linesTemp = NULL;
        textTemp = NULL;
        return true;
    }

    linesTemp = NULL;
    textTemp = NULL;
    return false;
}

bool deleteLineNode(LineNode **lines, TextNode **text)
{
    LineNode *linesTemp = *lines;
    while(linesTemp->indicator != current)
        linesTemp = linesTemp->next;

    TextNode *textTemp = linesTemp->pointer;
    while(textTemp->indicator != current)
        textTemp = textTemp->next;

    if(linesTemp->pointer == textTemp)
    {
        TextNode *nodeToDelete = textTemp->previous;
        textTemp->previous = nodeToDelete->previous;
        if(*text == nodeToDelete)
        {
            LineNode *lineToDelete = linesTemp->previous;
            linesTemp->previous = lineToDelete->previous;
            *text = textTemp;
            *lines = linesTemp;
            lineToDelete->pointer = NULL;
            lineToDelete->next = NULL;
            lineToDelete->previous = NULL;
            lineToDelete->amountOfSigns= 0;
            free(lineToDelete);
            lineToDelete = NULL;
        }
        else
        {
            nodeToDelete->previous->next = textTemp;

            LineNode *lineToComplete = linesTemp->previous;
            lineToComplete->amountOfSigns += linesTemp->amountOfSigns - 1;
            lineToComplete->indicator = current;
            lineToComplete->next = linesTemp->next;
            if(linesTemp->next)
                linesTemp->next->previous = lineToComplete;
            linesTemp->amountOfSigns = 0;
            linesTemp->indicator = general;
            linesTemp->next = NULL;
            linesTemp->previous = NULL;
            linesTemp->pointer = NULL;
            free(linesTemp);
            linesTemp = NULL;

            if(lineToComplete->pointer == nodeToDelete)
                lineToComplete->pointer = textTemp;

            lineToComplete = NULL;
        }
        nodeToDelete->sign = 0;
        nodeToDelete->next = NULL;
        nodeToDelete->previous = NULL;
        free(nodeToDelete);
        nodeToDelete = NULL;
        linesTemp = NULL;
        textTemp = NULL;
        return true;
    }

    linesTemp = NULL;
    textTemp = NULL;
    return false;
}


