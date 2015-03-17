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

            // -----

            while(*pointer != '\n' && *pointer != '\0')
            {
                if(*pointer == '(')
                {
                    setAsOperator(&current, *pointer);
                    push(current, &stack);
                    ++pointer;
                }
                else if(*pointer == ')')
                {
                    while(onTop(&current, stack) && getPriority(current.sign) > getPriority(*pointer))
                    {
                        addToList(current, &postfixNotation);
                        pop(&stack);
                    }
                    pop(&stack);
                    ++pointer;
                }
                else if(*pointer == ' ')
                {
                    ++pointer;
                }
                else if(strchr("-+*/^", *pointer))
                {
                    while(onTop(&current, stack) && getPriority(current.sign) >= getPriority(*pointer))
                    {
                        addToList(current, &postfixNotation);
                        pop(&stack);
                    }
                    setAsOperator(&current, *pointer);
                    push(current, &stack);
                    ++pointer;
                }
                else if(*pointer == ' ')
                {
                    ++pointer;
                }
                else
                {
                    numberInString = strtof(pointer, &pointer);
                    setAsNumber(&current, numberInString);
                    addToList(current, &postfixNotation);
                }
            }

            while(onTop(&current, stack))
            {
                addToList(current, &postfixNotation);
                pop(&stack);
            }

            clearStack(&stack);

            // на данном этапе мы "прошлись" по введенной строке и занесли обратную польскую запись поэлементно в односвязный список
            // -----

            // -----
            initializeStack(&stack);
            workOnNodes(postfixNotation, &stack, workOnEveryNode);
            // на данном этапе мы пробегаемся по нашему списку и работаем со стеком

            Item result;
            onTop(&result, stack); // наш результат хранится на вершине стека
            clearStack(&stack);
            clearTheList(&postfixNotation);
            printf("%.f\n", result.number);
        }
    }
    return 0;
}
