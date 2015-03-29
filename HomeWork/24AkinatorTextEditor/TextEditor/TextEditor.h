#ifndef TEXTEDITOR_H_INCLUDED
#define TEXTEDITOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../../Modules/include/ncursesDetails.h"

typedef enum State_ {general, current} State;

typedef struct TextNode_
{
    char sign;
    State indicator;
    struct TextNode_ *next, *previous;
} TextNode;

typedef struct LineNode_
{
    TextNode *pointer;
    State indicator;
    int amountOfSigns;
    struct LineNode_ *next, *previous;
} LineNode;

void setWindows(WINDOW **wnd1, WINDOW **wnd2, WINDOW **wnd3, int rows, int cols);
void deleteWindows(WINDOW **wnd1, WINDOW **wnd2, WINDOW **wnd3);
void showTheText(WINDOW *wnd, LineNode *lines, TextNode *text);
bool createLineNode(LineNode **line);
bool createTextNode(TextNode **text);
bool startWork(LineNode **lines, TextNode **text);
void clearLines(LineNode **lines);
void clearText(TextNode **text);
bool insertSign(LineNode **lines, TextNode **text, int symbol);
bool pressEnter(LineNode **lines, TextNode **text);

#endif // TEXTEDITOR_H_INCLUDED
