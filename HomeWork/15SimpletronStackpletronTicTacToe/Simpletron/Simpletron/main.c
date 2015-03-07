#include <stdio.h>
#include <stdlib.h>
#include "../../../../modules/include/compatibility.h"
#include "simpletronOperations.h"

int main()
{
    printf("*** Simpletron welcomes you! ***\n"
           "*** Please enter your program with one instruction (or data word) at ***\n"
           "*** a time. I will display as a tip current address and question mark ***\n"
           "*** (?). The keywords will be posted to the specified address. To stop ***\n"
           "*** the program entry, enter the number -99999. ***");
    universalSleep(5.0);
    universalClear();
    int memory[SIZEOFMEMORY] = {0};
    entryMemory(memory);
    runProgram(memory);
    memoryDump(memory);
    return 0;
}
