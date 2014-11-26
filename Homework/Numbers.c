#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    printf("%d+%d = %d\n", a, b, a+b);
    printf("%d-%d = %d\n", a, b, a-b);
    printf("%d*%d = %d\n", a, b, a*b);
    printf("%d/%d = %d\n", a, b, a/b);
    printf("%d%%d = %d\n", a, b, a%b); //надо исправить
    return 0;
}
