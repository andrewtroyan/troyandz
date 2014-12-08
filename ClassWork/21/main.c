#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int humanScore = 0, computerScore = 0;
    do {
        humanScore = rand()%11+1+rand()%11+1;
        computerScore = rand()%11+1+rand()%11+1;
    } while (computerScore > 21 || humanScore > 21);
    //---
    printf("Your score is:\n%d\n", humanScore);
    char answer = 'y';
    if (humanScore < 21) {
        printf("Would you like to take another card? (y/n):\n");
        scanf("%c", &answer);
        if (answer == 'y') {
            humanScore+=rand()%11+1;
        }
    }
    //---
    int computerWillTake=1;
    if (computerScore > 11) {
        computerWillTake = 21 - computerScore > rand()%21;
    }
    if (computerWillTake) {
        computerScore = rand()%11+1;
    }
    //---
    while (answer == 'y' && computerWillTake && humanScore < 21 && computerScore < 21) {
        if (humanScore > 11) {
            printf("Would you like take another card? (y/n):\n");
            answer = 'y';
            scanf("%c", &answer);
            if ('y' == answer) {
                humanScore+=rand()%11+1;
            }
        }
        computerWillTake=1;
        if (computerScore > 11) {
            computerWillTake = 21 - computerScore > rand()%21;
        }
        if (computerWillTake) {
            computerScore += rand()%11+1;
        }
    }
    //---
    while (answer == 'y' && humanScore < 21) {
        answer = 'y';
        if (humanScore < 21) {
            printf("Would you like take another card? (y/n):\n");
            scanf("%c", &answer);
            if ('y' == answer) {
                humanScore+=rand()%11+1;
            }
        }
    }
    //---
    while (computerWillTake && computerScore < 21) {
        computerWillTake=1;
        if (computerScore > 11) {
            computerWillTake = 21 - computerScore > rand()%21;
        }
        if (computerWillTake) {
            computerScore += rand()%11+1;
        }
    }
    //---
    if (humanScore == 21) {
        printf("You win!\nYour score is %d", humanScore);
    }
    else if (humanScore > 21) {
        printf("Game over!\nYour score is %d\nComputer's score is %d", humanScore, computerScore);
    }
    else if (computerScore <= 21 && humanScore < computerScore) {
        printf("Game over!\nYour score is %d\nComputer's score is %d", humanScore, computerScore);
    }
    else if (computerScore == humanScore) {
        printf("Draw!\nYour score is %d", humanScore);
    }
    else {
        printf("You win!\nYour score is %d", humanScore);
    }

}
