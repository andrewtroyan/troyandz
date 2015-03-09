#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "../../Modules/include/mathx.h"

int main()
{
    //Структура - производныйтип данных, имеющий собственное имя и содержащий именованные поля;

    /*struct AlaArray
    {
        int a0, a1, a2, a3;  //массив в виде структуры;
    };*/

    /*typedef struct Persona_ //Persona -не переменная, а новый тип данных!!!;
    {
        char name[128];
        int age;
        enum Sex{male, female} sex;
        double tall; //рост в метрах;
    } Persona;

    Persona vasya, petya = {"Petya Ivanov", 23, male, 1.79}; //создание переменных типа Persona;

    vasya = petya; //присваивание;

    strcpy(vasya.name, "Vasya Ivanov");
    vasya.tall = 1.81;

    Persona *p; //указатель на тип Persona;
    p = &vasya;
    (*p).tall -= 0.01; //если *p.tall - разименование tall, а не p;
    p-> tall -= 0.01; //то же, что и на предыдущей строке;

    typedef struct Fraction_
    {
        int numerator, denominator; //числитель, знаменатель;
    } Fraction;

    Fraction sum(Fraction a, Fraction b)
    {
        assert(a.denominator && b.denominator);
        Fraction result;
        result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
        result.denominator = a.denominator * b.denominator;
        int div = gcd(result.numerator, result.denominator);
        result.numerator /= div;
        result.denominator /= div;
        return result;
    }*/

    /*int number = 0x525456;
    char *p = (char *)&number;
    /*for(int i = 0; i < sizeof(int); ++i, ++p)
    {
        printf("%c", *p);
    }*/
    //fread(), write() - побитово, надо открывать файл в бинарном виде
    /*size_t fread(void *buf, size_t sizeElem, size_t count, FILE *file);
    size_t fwrite(const void *buf, size_t sizeElem, size_t count, FILE *file);*/

    //Создать структуру персону, сохранить в файл в бинарном виде.

    typedef struct Persona_
    {
        char name[128];
        int age;
        enum Sex{male, female} sex;
        double tall;
    } Persona;

    FILE *filePointer;
    Persona vasya = {"Vasya Ivanov", 23, male, 1.79};

    filePointer = fopen("FileForExample.bin", "wb");
    if(filePointer == NULL)
    {
        fprintf(stderr, "Cannot open the file.\n");
        exit(1);
    }

    fwrite(&vasya, sizeof(Persona), 1, filePointer);

    fclose(filePointer);

    return 0;
}
