#define _XOPEN_SOURCE_EXTENDED //отвечают за
#define _POSIX_C_SOURCE 199309L //работу с юникодом

#include <sys/ioctl.h> //отвечает за получение размеров консоли
#include <signal.h> //отвечает за взаимодействие с ОС в виде реагирования каких-либо сигналов
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <locale.h> //нужна, чтобы всё грамотно работало с юникодом

void treatSigWinch(int signo);
void initialiseProgram();
enum Colors{normal, green, red};

int main()
{
    initialiseProgram();

    attron(COLOR_PAIR(normal)); //attribute on, активируем цветовую пару
    printw("Hello world!");
    attroff(COLOR_PAIR(normal));
    refresh();
    getch();
    attron(A_BLINK|A_BOLD);
    move(0, 0);
    attron(COLOR_PAIR(red));
    printw("Hello");
    attroff(COLOR_PAIR(red));
    attroff(A_BLINK|A_BOLD);
    attron(A_BLINK|A_BOLD);
    move(0, 6);
    attron(COLOR_PAIR(green));
    printw("world!");
    attroff(COLOR_PAIR(green));
    attroff(A_BLINK|A_BOLD);
    refresh();
    getch();
    endwin();
    return 0;
}

void initialiseProgram()
{
    setlocale(LC_ALL, "");
    initscr(); //начать экран
    signal(SIGWINCH, treatSigWinch); //назначаем сигналу sigwinch обработчик
    if(has_colors() == FALSE)
    {
        endwin();
        fprintf(stderr, "no colors\n");
        exit(1);
    }
    cbreak();
    noecho();
    curs_set(0);
    start_color(); //"начинаем" цвета
    //init_pair(1, COLOR_GREEN, COLOR_BLACK); //зеленый шрифт, черный фон
    init_pair(normal, COLOR_WHITE, COLOR_BLACK);
    init_pair(green, COLOR_GREEN, COLOR_BLACK);
    init_pair(red, COLOR_RED, COLOR_BLACK);
}

void treatSigWinch(int signo)
{
    struct winsize size;
    ioctl(fileno(stdout), TIOCGWINSZ, (char *) &size);
    resizeterm(size.ws_row, size.ws_col);
}
