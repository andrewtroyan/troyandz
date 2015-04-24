#include "myio.h"

int main()
{
    int tmpDec = 13, tmpHex = 0xBEAF;
    char *tmpStr = "DEAD";

    myprintf("%s %x\n%d", tmpStr, tmpHex, tmpDec);
    return 0;
}
