#include <stdio.h>
#include <stdlib.h>

/*
C:
int fseek( FILE * stream, long int offset, int origin );
Принимает: указатель на структуру файла, смещение и место, откуда нужно произвести это смещение.
Возвращает: 0, если все ок. Другое значение, если есть ошибка.
Макросы для этой функции:
SEEK_SET - начало файла,
SEEK_CUR - текущее положение в файле,
SEEK_END - конец файла (нестандартная переносимость).

long int ftell(FILE *filepointer);
Принимает: указатель на структуру файла.
Возвращает: значение текущего указателя в файле. -1, если произошла ошибка.

void rewind( FILE * stream );
Принимает: указатель на структуру файла.

СИСТЕМНЫЕ ВЫЗОВЫ:
<unistd.h>

off_t lseek(int fd, off_t offset, int against);
Константы для положения в файле:
SEEK_SET
SEEK_CUR
SEEK_END

Возвращает: значение текущего указателя в файле. -1, если произошла ошибка.

Вместо ftell:
lseek(fd, 0, SEEK_CUR);

C++:
Если открыт файл и на чтение, и на запись, С++ разделяет два указателя (на чтение и запись):
seekp
tellp
seekg
tellg
Это методы.

ios_base::deg
ios_base::cur
ios_base::end
*/

int main()
{
    printf("Hello world!\n");
    return 0;
}
