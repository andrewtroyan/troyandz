#include <stdio.h>
#include <stdlib.h>
#include <string.h> //здесь хранятся функции для строк

int main()
{
    /*long long int a = 0xFEFEFEFEFEFEFEFE;
    char str[9] = "mamarama"; //размер 9 для того, чтобы было место для '\0' - признака конца строки
    long long int b = 0xDADADADADADADADA;
    printf("%s\n", str);
    for(char *p = str; *p; ++p)
    {
        printf("%c\t%#X\n", *p, *p);
    }*/

    /*char *str1 = "mama"; //можем объявить, но менять в дальнейшем не можем (раздел памяти Read Only)
    char str2[5] = "mama";
    printf("%s\n%s\n", str1, str2);
    str1[0] = 'r'; //не получится
    printf("%s\n", str1);*/

    /*int strlen(char *) - возвращает длину строки;
    strcpy(destination, source) - string copy (из source в destination)
    strcat(destination, source) - source приклеивает к destination
    strcmp(a, b) - отрицательное число, если а < b, 0 - если равны, положительное число - если a > b

    strchr(haytack, needle) - ищет символ в строке
    strstr(haystack, needles) - ищет символ из строки в строке

    strtok(char *str, const char *delim) - разбивает строку на токены (delim - разделитель); функция с побочным эффектом; после первого раза надо вызывать с NULL;*/

    char str[20];
    fgets(str, 20, stdin); //прочитать строку (включая пробелы, переводы строки и т.д.), stdin - standart input

    return 0;
}
