#include "Calculator.h"

int main(int argc, char **argv)
{
    if(argc > 1)
    {
        if(strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
        {
            printf("Information:\n");
            printf("  -h  --help         print this usage and exit\n");
            printf("  -i  --interactive  force interactive mode\n");
        }
        else if(strcmp(argv[1], "--interactive") == 0 || strcmp(argv[1], "-i") == 0)
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
