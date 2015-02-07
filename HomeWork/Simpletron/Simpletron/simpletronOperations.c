#define SIZEOFMEMORY 100


int entryMemory(int memory[])
{
    int accumulator, instructionCounter = 0;
    while(instructionCounter < SIZEOFMEMORY)
    {

        printf("%02d? ", instructionCounter);
        scanf("%d", &accumulator);
        if(accumulator == -99999)
        {
            printf("*** Loading the program is done. ***\n"
                   "*** Starting to run the program. ***");
            //universalSleep(2.5);
            universalClear();
            return 0;
        }
        else
        {
            memory[instructionCounter] = accumulator;
        }
        ++instructionCounter;
    }
    printf("*** The memory is full. ***\n");
    exit(1);
}

void runProgram(int memory[])
{
    int accumulator = 0, operationCode = 0, operand = 0, instructionRegister = 0, instructionCounter = 0;
    do
    {
        instructionRegister = memory[instructionCounter];
        operationCode = instructionRegister / 100;
        operand = instructionRegister % 100;
        switch(operationCode)
        {
        case 10:
            scanf("%d", &memory[operand]);
            ++instructionCounter;
            break;
        case 11:
            printf("%+05d\n", memory[operand]);
            ++instructionCounter;
            break;
        case 20:
            accumulator = memory[operand];
            ++instructionCounter;
            break;
        case 21:
            memory[operand] = accumulator;
            ++instructionCounter;
            break;
        case 30:
            accumulator += memory[operand];
            ++instructionCounter;
            break;
        case 31:
            accumulator -= memory[operand];
            ++instructionCounter;
            break;
        case 32:
            accumulator /= memory[operand];
            ++instructionCounter;
            break;
        case 33:
            accumulator *= memory[operand];
            ++instructionCounter;
            break;
        case 40:
            instructionCounter = operand;
            break;
        case 41:
            if(accumulator < 0)
            {
                instructionCounter = operand;
            }
            else
            {
                ++instructionCounter;
            }
            break;
        case 42:
            if(accumulator == 0)
            {
                instructionCounter = operand;
            }
            else
            {
                ++instructionCounter;
            }
            break;
        case 43:
            printf("*** Simpletron is stopped. ***\n");
            break;
        }
    }
    while(operationCode != 43);
}


