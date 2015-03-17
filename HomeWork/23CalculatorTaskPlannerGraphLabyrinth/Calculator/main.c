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
            Item current = {0, 0, null};
            List postfixNotation;
            Stack stack;

            fgets(string, MAXSTR, stdin);
            char *pointer = string;
            float numberInString;
            initializeList(&postfixNotation);
            initializeStack(&stack);

            while(*pointer)
            {
                numberInString = strtof(string, &pointer);
                setAsNumber(&current, numberInString);
                addToList(current, &postfixNotation);
                if(*pointer == ' ')
                    ++pointer;
                if(strchr("()+-*/^", *pointer))
                    while(onTop(&current, stack) && getPriority(current.sign) >= getPriority(*pointer))
                    {
                        addToList(current, &postfixNotation);
                        pop(&stack);
                    }
                    setAsOperator(&current, *pointer);
                    push(current, &stack);
            }
        }
    }
    return 0;
}
