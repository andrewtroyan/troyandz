#include <stdio.h>
#include <stdlib.h>

void diskTransfer(int disks, char from, char to, char helper);

int main()
{
    diskTransfer(8, 'A', 'B', 'C');
    return 0;
}

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
