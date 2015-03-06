#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, d;
    printf("Enter four numbers with a space between them: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("%*d\n%*d\n%*d\n%*d", 2, 2*a, 3, 2*b, 4, 2*c, 5, 2*d);
    return 0;
}

