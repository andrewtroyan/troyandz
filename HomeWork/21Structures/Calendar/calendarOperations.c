#include "calendarOperations.h"

int enterDate(Date *pointer)
{
    pointer->year = 0, pointer->month = 0, pointer->day = 0;
    scanf("%d.%d.%d", &pointer->year, &pointer->month, &pointer->day);
    if(checkDate(*pointer) == false)
    {
        return 1;
    }
    return 0;
}

void showDate(Date date)
{
    printf("%04d.%02d.%02d\n", date.year, date.month, date.day);
}

bool isLeapYear(int year)
{
    if(year % 400 == 0)
        return true;
    else if(year % 100 == 0)
        return false;
    else if(year % 4 == 0)
        return true;
    else
        return false;
}

bool checkDate(Date data)
{
    if(data.year <= 0 || data.month <= 0 || data.year <= 0 || data.month > 12)
        return false;

    if(data.month == 2)
    {
        if(isLeapYear(data.year) == true && data.day > 29)
            return false;
        else if(isLeapYear(data.year) == false && data.day > 28)
            return false;
    }

    if((data.month == 1 || data.month == 3 || data.month == 5 || data.month == 7 || data.month == 8 || data.month == 10 || data.month == 12) && data.day > 31)
        return false;

    if((data.month == 4 || data.month == 6 || data.month == 9 || data.month == 11) && data.day > 30)
        return false;

    return true;
}

long int amountOfDays(Date date)
{
    long int amount = 0;

    for(int i = 1; i < date.year; ++i)
    {
        if(isLeapYear(i) == true)
            amount += 366;
        else
            amount += 365;
    }

    for(int i = 1; i < date.month; ++i)
    {
        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10)
            amount += 31;
        else if(i == 2)
        {
            if(isLeapYear(date.year) == true)
                amount += 29;
            else
                amount += 28;
        }
        else
            amount += 30;
    }

    amount += date.day;

    return amount;
}

void addDays(Date *date, long int days)
{
    for(long int i = days; i > 0; --i)
    {
        if((date->month == 1 || date->month == 3 || date->month == 5 || date->month == 7 || date->month == 8 || date->month == 10) && date->day == 31)
        {
            ++date->month;
            date->day = 1;
        }
        else if(date->month == 2 && date->day == 28)
        {
            if(isLeapYear(date->year) == true)
            {
                ++date->day;
            }
            else
            {
                ++date->month;
                date->day = 1;
            }
        }
        else if(date->month == 2 && date->day == 29)
        {
            ++date->month;
            date->day = 1;
        }
        else if((date->month == 4 || date->month == 6 || date->month == 9 || date->month == 11) && date->day == 30)
        {
            ++date->month;
            date->day = 1;
        }
        else if(date->month == 12 && date->day == 31)
        {
            ++date->year;
            date->month = 1;
            date-> day = 1;
        }
        else
        {
            ++date->day;
        }
    }
}

int differenceInDays(Date date1, Date date2)
{
    long int result1 = amountOfDays(date1), result2 = amountOfDays(date2);
    return abs(result1 - result2);
}

