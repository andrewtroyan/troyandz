#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void displayXO(int i)
{
    if(i == 0)
    {
        printf(" ");
    }
    else if(i == 1)
    {
        printf("X");
    }
    else
    {
        printf("O");
    }
}


void display(int array[][3], int rows, int cols)
{
    for(int i = 0; i < rows + 2; ++i)
    {
        for(int j = 0; j < cols + 2; ++j)
        {
            if(j % 2 == 0 && i % 2 == 0)
            {
                displayXO(array[i / 2][j / 2]);
            }
            else if(i % 2 == 0)
            {
                printf("|");
            }
            else
            {
                printf("-");
            }
        }
        printf("\n");
    }
}

//Функция хода
//Куда и чем ходим
bool motion(int array[][3], int where, int what)
{
    bool ok = false;
    switch (where)
    {
    case 1:
        if(array[0][0] == 0)
        {
            array[0][0] = what;
            ok = true;
        }
        break;
    case 2:
        if(array[0][1] == 0)
        {
            array[0][1] = what;
            ok = true;
        }
        break;
    case 3:
        if(array[0][2] == 0)
        {
            array[0][2] = what;
            ok = true;
        }
        break;
    case 4:
        if(array[1][0] == 0)
        {
            array[1][0] = what;
            ok = true;
        }
        break;
    case 5:
        if(array[1][1] == 0)
        {
            array[1][1] = what;
            ok = true;
        }
        break;
    case 6:
        if(array[1][2] == 0)
        {
            array[1][2] = what;
            ok = true;
        }
        break;
    case 7:
        if(array[2][0] == 0)
        {
            array[2][0] = what;
            ok = true;
        }
        break;
    case 8:
        if(array[2][1] == 0)
        {
            array[2][1] = what;
            ok = true;
        }
        break;
    case 9:
        if(array[2][2] == 0)
        {
            array[2][2] = what;
            ok = true;
        }
        break;
    }
    return ok;
}


//Человек ходит крестиком
//Человек ходит первым
//Функция отвечает за первый и последующие хода
void man(int array[][3])
{
    int x;
    do
    {
    printf("Enter number: ");
    scanf("%d", &x);
    }while(!motion(array, x, 1));
}

//Ход компьютера
void computer(int array[][3])
{
    int x;
    do
    {
    srand(time(NULL));
    x = rand() % 9 + 1;
    }while(!motion(array, x, 2));
}

//1- игра продолжается
//2 - если ничья
//3 - если победил компьютер
//4 - если победил человек
int check(int array[][3])
{
    static int counter = 0;

    //Проверить строки
    for(int i = 0; i < 3; ++i)
    {
        if(array[i][0] == array[i][1] && array[i][1] == array[i][2])
        {
            if(array[i][0] == 1)
            {
                return 4;
            }
            else if(array[i][0] == 2)
            {
                return 3;
            }
        }
    }

    //Проверить столбцы
    for(int i = 0; i < 3; ++i)
    {
        if(array[0][i] == array[1][i] && array[1][i] == array[2][i])
        {
            if(array[0][i] == 1)
            {
                return 4;
            }
            else if(array[0][i] == 2)
            {
                return 3;
            }
        }
    }

    //Проверить главную диагональ
    if(array[0][0] == array[1][1] && array[1][1] == array[2][2])
    {
        if(array[0][0] == 1)
        {
            return 4;
        }
        else if(array[0][0] == 2)
        {
            return 3;
        }
    }

    //Проверить другую диагональ
    if(array[2][0] == array[1][1] && array[1][1] == array[0][2])
    {
        if(array[2][0] == 1)
        {
            return 4;
        }
        else if(array[2][0] == 2)
        {
            return 3;
        }
    }

    //Проверить ничью
    if(++counter == 9)
    {
        return 2;
    }
    return 1;
}


