#include <stdio.h>

void diskTransfer(int disks, char from, char to, char helper)
{
    if(disks > 0)
    {
        diskTransfer(disks - 1, from, helper, to);
        printf("%c -> %c\n", from, to);
        diskTransfer(disks - 1, helper, to, from);
    }
}
