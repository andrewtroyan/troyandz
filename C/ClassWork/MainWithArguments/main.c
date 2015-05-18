#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) //argv - массив строк, argc - количество строк
{
    /*if(argv[1] != NULL && strcmp(argv[1], "--help") == 0)
        printf("You need a help.\n");*/

    FILE *file = NULL;

    FILE *fopen(const char *filename, const char *mode); //mode - режим

    if(file == NULL)
    {
        ...
    }

    Режимы:
    r - файл открывается на чтение (файл уже должен сущестовать); надо делать проверку, открыт ли файл (не вернула ли функция NULL)
    w - запись (если файл существует, то перепишется или создается новый)
    a - добавить (если файл существует, то дописывается в конец или создается новый)
    r+, w+, a+ - и читать, и писать (дописывается +)
    rb, wb - открытие в бинарном режиме (дописывается b); существенна для Windows

    fclose(FILE *file); //возвращает 0 если все хорошо, EOF если нет (End of file)

    freopen(); - переоткрыть файл (имя файла, режим, имя файла, который хотим переоткрыть)
    freopen("zuzu.txt", "rb", stdin);

    fprintf(FILE *file, const char *format, ...);
    fscanf(FILE *file, const char *format, ...);

    printf(...)
    {
        fprintf(stdout, format, ...);
    }

    Три стандартных файла:
    1) stdin
    2) stdout
    3) stderr

    Со строками:
    sprintf(char *str...);
    sscanf();

    return 0;
}
