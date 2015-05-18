#include "timeOperations.h"

void enterTime(Time *pointer)
{
    pointer->hours = 0, pointer->minutes = 0, pointer->seconds = 0;
    scanf("%ld:%ld:%ld", &pointer->hours, &pointer->minutes, &pointer->seconds);
    convertTime(pointer);
}

void showTime(Time time)
{
    printf("%02ld:%02ld:%02ld\n", time.hours, time.minutes, time.seconds);
}

void convertTime(Time *pointer)
{
    if(pointer->seconds > 59)
    {
        pointer->minutes += pointer->seconds / 60;
        pointer->seconds %= 60;
    }
    if(pointer->minutes > 59)
    {
        pointer->hours += pointer->minutes / 60;
        pointer->minutes %= 60;
    }
    if(pointer->hours > 23)
    {
        pointer->hours %= 24;
    }
}

void addSeconds(Time *pointer, long int seconds)
{
    pointer->seconds += seconds;
    convertTime(pointer);
}

long int decomposeIntoSeconds(Time time)
{
    return time.hours * 3600 + time.minutes * 60 + time.seconds;
}

long int differenceInSeconds(Time time1, Time time2)
{
    long int result1 = decomposeIntoSeconds(time1), result2 = decomposeIntoSeconds(time2);
    if(result1 > result2)
    {
        result2 += 24 * 60 * 60;
    }
    return result2 - result1;
}
