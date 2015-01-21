#include <stdio.h>

void diskTransfer(int disks, char from, char to, char helper)
{
    if(disks == 1)
    {
        printf("%c -> %c\n", from, to);
    }
    else
    {
        diskTransfer(disks - 1, from, helper, to);
        printf("%c -> %c\n", from, to);
        diskTransfer(disks - 1, helper, to, from);
    }
}
