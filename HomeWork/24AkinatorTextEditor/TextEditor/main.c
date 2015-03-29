#include "TextEditor.h"

int main(int argc, char **argv)
{
    if(argc > 1)
    {
        if(!strcmp(argv[1], "--help") || !strcmp(argv[1], "-help"))
            printf("It's the text editor where you can work with text files.\nTo open an interactive mode just enter the name of this program.\n");
    }
    else
    {
        struct winsize size;
        ioctl(fileno(stdout), TIOCGWINSZ, (char *) &size);

        WINDOW *wnd1, *wnd2, *wnd3;
        setWindows(&wnd1, &wnd2, &wnd3, size.ws_row, size.ws_col);

        LineNode *lines = NULL;
        TextNode *text = NULL;

        startWork(&lines, &text);
        showTheText(wnd2, lines, text);

        int sign;
        keypad(stdscr, true);
        while(sign != 'q')
        {
            sign = getch();
            if(sign == '\n')
                pressEnter(&lines, &text);
            else if(sign == KEY_BACKSPACE)
                deleteSign(&lines, &text);
            else
                insertSign(&lines, &text, sign);
            showTheText(wnd2, lines, text);
        }

        clearLines(&lines);
        clearText(&text);
        deleteWindows(&wnd1, &wnd2, &wnd3);
    }
    return 0;
}
