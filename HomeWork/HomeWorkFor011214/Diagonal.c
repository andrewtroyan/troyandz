# include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, d;
    printf("Enter four numbers with a space between them: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("%d\n", 2*a);
    printf(" %d\n", 2*b);
    printf("  %d\n", 2*c);
    printf("   %d\n", 2*d);
    return 0;
}
