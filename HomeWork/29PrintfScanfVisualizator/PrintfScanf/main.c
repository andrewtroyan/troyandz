#include "myio.h"
#include <stdlib.h>

int main()
{
    int tmpDec = 13, tmpHex = 0xBEAF;
    char *tmpStr = "dead";

    myprintf("%s %x\n%d\n", tmpStr, tmpHex, tmpDec);

    int checkDec, checkHex;
    char *checkStr = (char *)malloc(256);

    myscanf("%d%x%s", &checkDec, &checkHex, checkStr);
    myprintf("%d\n%x\n%s\n", checkDec, checkHex, checkStr);

    free(checkStr);
    return 0;
}
