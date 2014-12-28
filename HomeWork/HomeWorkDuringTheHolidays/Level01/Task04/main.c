#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, exorcismSpeed, fatigueTime, flyReturnSpeed;
    printf("Enter the amount of flies: ");
    scanf("%d", &N);
    printf("Enter the amount of flies thrown out per minute: ");
    scanf("%d", &exorcismSpeed);
    printf("Enter the time after which Ivan Vasiliyevich gets tired: ");
    scanf("%d", &fatigueTime);
    printf("Enter the amount of flies that return back per minute: ");
    scanf("%d", &flyReturnSpeed);
    system("cls");
    int time = 0;
    for (int k = 1; k <= 5; ++k)
    {
        for (int i = 1; i <= fatigueTime; ++i)
        {
            N -= exorcismSpeed - flyReturnSpeed;
            ++time;
            if (N == 0)
            {
                printf("Ivan Vasilyevich thrown out all the flies in %d minute(s)!", time);
                return 0;
            }
        }
        exorcismSpeed /= 5;
    }
    printf("Ivan Vasilyevich got tired :( It's impossible to throw all the flies out :(");
    return 0;
}
