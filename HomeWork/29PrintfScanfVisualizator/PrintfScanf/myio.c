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

int myscanf(char *string, ...)
{
    va_list list;
    va_start(list, string);

    for(int i = 0; string[i]; ++i)
    {
        if(string[i] == '%')
        {
            if(string[i + 1] == 'd')
            {
                int *tmpHex = va_arg(list, int *);
                *tmpHex = 0;

                char tmpChar;
                do
                {
                    read(0, &tmpChar, 1);
                    if(tmpChar >= 48 && tmpChar <= 57)
                        *tmpHex = *tmpHex * 10 + (int)tmpChar - 48;
                } while (tmpChar != '\n' && tmpChar != 32);

                ++i;
            }
            else if(string[i + 1] == 'x')
            {
                int *tmpHex = va_arg(list, int *);
                *tmpHex = 0;

                char tmpChar;
                do
                {
                    read(0, &tmpChar, 1);
                    if(tmpChar >= 48 && tmpChar <= 57)
                        *tmpHex = *tmpHex * 16 + (int)tmpChar - 48;
                    else if(tmpChar >= 65 && tmpChar <= 70)
                        *tmpHex = *tmpHex * 16 + (int)tmpChar - 55;
                    else if(tmpChar >= 97 && tmpChar <= 102)
                        *tmpHex = *tmpHex * 16 + (int)tmpChar - 87;
                } while (tmpChar != '\n' && tmpChar != 32);

                ++i;
            }
            else if(string[i + 1] == 's')
            {
                char *temp = va_arg(list, char *), tmpChar;
                int j = 0;
                while(read(0, &tmpChar, 1) && tmpChar != '\n')
                {
                    temp[j] = tmpChar;
                    ++j;
                }
                temp[j] = '\0';
                ++i;
            }
        }
    }

    va_end(list);

    return 0;
}
