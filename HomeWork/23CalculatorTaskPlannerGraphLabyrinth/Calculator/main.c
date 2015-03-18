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
            Item result;
            List postfixNotation;
            Stack stack;

            fgets(string, MAXSTR, stdin);
            initializeList(&postfixNotation);
            initializeStack(&stack);

            // -----

            turnToPostfix(&postfixNotation, &stack, string); // на данном этапе мы "прошлись" по введенной строке и занесли обратную польскую запись поэлементно в односвязный список

            clearStack(&stack);

            // -----

            initializeStack(&stack);

            workOnNodes(postfixNotation, &stack, workOnEveryNode); // на данном этапе мы пробегаемся по нашему списку и работаем со стеком

            // -----

            onTop(&result, stack); // наш результат хранится на вершине стека
            clearStack(&stack);
            clearTheList(&postfixNotation);
            printf("%.f\n", result.number);
        }
    }
    return 0;
}
