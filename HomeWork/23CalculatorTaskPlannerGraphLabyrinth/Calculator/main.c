#include "Calculator.h"

int main(int argc, char **argv)
{
    if(argc > 1)
    {
        if(strstr(argv[1], "--help") || strstr(argv[1], "-h"))
        {
            printf("Information:\n");
            printf("  -h  --help         print this usage and exit\n");
            printf("  -i  --interactive  force interactive mode\n");
        }
        else if(strstr(argv[1], "--interactive") || strstr(argv[1], "-i"))
        {
            char string[MAXSTR];
            fgets(string, MAXSTR, stdin);
        }
    }
    return 0;
}
