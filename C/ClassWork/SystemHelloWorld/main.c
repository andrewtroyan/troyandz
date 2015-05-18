#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//0 - ввод stdin
//1 - вывод stdout
//2 - ошибки stderr

int main(int argc, char **argv)
{
    write(1, "Hello world!\n", 13); //не считаем нулевой символ
    return 0;
}
