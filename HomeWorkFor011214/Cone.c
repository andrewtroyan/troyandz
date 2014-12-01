#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r, h;
    printf("Enter the radius: ");
    scanf("%d", &r);
    printf("Enter the height: ");
    scanf("%d", &h);
    printf("V=%.2f\n", 3.14*r*r*h/3);
    printf("S=%.2f\n", 3.14*r*r+sqrt(r*r+h*h));
    return 0;
}
