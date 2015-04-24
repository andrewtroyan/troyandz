#include "myio.h"
#include "../../../Modules/include/integer.h"

int myprintf(char *string, ...)
{
    va_list list;
    va_start(list, string);

    for(int i = 0; string[i]; ++i)
    {
        if(string[i] == '%')
        {
            if(string[i + 1] == 'd')
            {
                int decTemp = va_arg(list, int);
                char *decStr = NULL;
                itos(&decStr, decTemp, 10);
                write(1, decStr, strlen(decStr));
                ++i;
            }
            else if(string[i + 1] == 'x')
            {
                int hexTemp = va_arg(list, int);
                char *hexStr = NULL;
                itos(&hexStr, hexTemp, 16);
                write(1, hexStr, strlen(hexStr));
                ++i;
            }
            else if(string[i + 1] == 's')
            {
                char *temp = va_arg(list, char *);
                write(1, temp, strlen(temp));
                ++i;
            }
            else
                write(1, (const void *)&string[i], 1);
        }
        else
            write(1, (const void *)&string[i], 1);
    }

    va_end(list);

    return 0;
}
