#include <stdio.h>
#include <stdlib.h>

int main()
{
    char answer;
    printf("Let's play. Answer writing the number that exists on the list that I will show you. Ok? (y/n)\n");
    scanf("%c", &answer);
    switch (answer)
    {
    case 'y':
        system("cls");
        printf("Imagine that you are followed by criminals. How do you run?\n1. Fast.\n2. Slowly.\n");
        scanf(" %c", &answer);
        switch (answer)
        {
        case '1':
            system("cls");
            printf("Okay, you run and you see the big stone in front of you. What are you going to do?\n1. Jump it over.\n2. Run the same way.\n");
            scanf(" %c", &answer);
            switch (answer)
            {
            case '1':
                system("cls");
                printf("Okay, you jumped it over. You run... And suddenly you see the big fence! What will you do?\n1. Climb over.\n2. Run left.\n3. Run right.\n");
                scanf(" %c", &answer);
                switch (answer)
                {
                case '1':
                    system("cls");
                    printf("You ran away from the criminals! Congratulations!");
                    break;
                case '2':
                    system("cls");
                    printf("Suddenly one of the criminals appeared from the corner! You are caught!");
                    break;
                case '3':
                    system("cls");
                    printf("You ran away from the criminals! Congratulations!");
                    break;
                default:
                    system("cls");
                    printf("Next time read the rules correctly! Bye!");
                }
                break;
            case '2':
                system("cls");
                printf("Oh, you tripped and fell on the ground! Criminals caught you! You lose!");
                break;
            default:
                printf("Next time read the rules correctly! Bye!");
            }
            break;
        case '2':
            system("cls");
            printf("Criminals caught you! You lose!");
            break;
        default:
            system("cls");
            printf("Next time read the rules correctly! Bye!");
        }
        break;
    default:
        system("cls");
        printf("This game is not for you! Bye!");
    }
    return 0;
}
