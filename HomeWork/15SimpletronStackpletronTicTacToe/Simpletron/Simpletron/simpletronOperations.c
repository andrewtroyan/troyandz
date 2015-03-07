#define SIZEOFMEMORY 100

int entryMemory(int memory[])
{
    int accumulator = 0, code = 0, instructionCounter = 0;
    while(instructionCounter < SIZEOFMEMORY)
    {
        printf("%02d? ", instructionCounter);
        do
        {
            scanf("%d", &accumulator);
            code = accumulator / 100;
            if(accumulator == -99999)
            {
                printf("*** Loading the program is done. ***\n"
                       "*** Starting to run the program. ***");
                universalSleep(2.5);
                universalClear();
                return 0;
            }
            else if(accumulator >= -9999 && accumulator <= 9999)
            {
                memory[instructionCounter] = accumulator;
            }
        }while((accumulator != - 99999 && accumulator < -9999) || accumulator > 9999);
        if(code == 0 || code == 10 || code == 11 || code == 20 || code == 21 || code == 30 || code == 31
           || code == 32 || code == 33 || code == 40 || code == 41 || code == 42 || code == 43)
        {
            ++instructionCounter;
        }
    }
    printf("*** The memory is full. ***\n");
    exit(1);
}

static int accumulator = +0000, operationCode = 00, operand = 00, instructionRegister = +0000, instructionCounter = 00;

void runProgram(int memory[])
{
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
            printf("%+.4d\n", memory[operand]);
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
            if(accumulator + memory[operand] < -9999 || accumulator + memory[operand] > 9999)
            {
                printf("*** Accumulator is overfull! ***\n*** Simpletron finished work emergency! ***\n");
                exit(1);
            }
            else
            {
                accumulator += memory[operand];
                ++instructionCounter;
            }
            break;
        case 31:
            if(accumulator - memory[operand] < -9999 || accumulator - memory[operand] > 9999)
            {
                printf("*** Accumulator is overfull! ***\n*** Simpletron finished work emergency! ***\n");
                exit(1);
            }
            else
            {
                accumulator -= memory[operand];
                ++instructionCounter;
            }
            break;
        case 32:
            if(memory[operand] == 0)
            {
                printf("*** You tried to divide by zero! ***\n*** Simpletron finished work emergency! ***\n");
                exit(1);
            }
            else
            {
                accumulator /= memory[operand];
                ++instructionCounter;
            }
            break;
        case 33:
            if(accumulator * memory[operand] < -9999 || accumulator * memory[operand] > 9999)
            {
                printf("*** Accumulator is overfull! ***\n*** Simpletron finished work emergency! ***\n");
                exit(1);
            }
            else
            {
                accumulator *= memory[operand];
                ++instructionCounter;
            }
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
    }while(operationCode != 43);
}

void memoryDump(int memory[])
{
    printf("\nRegisters:\n%-19s%+9.4d\n%-19s%9.2d\n%-19s%+9.4d\n%-19s%9.2d\n%-19s%9.2d\n", "accumulator", accumulator,
           "instructionCounter", instructionCounter, "instructionRegister", instructionRegister,
           "operationCode", operationCode, "operand", operand);
    printf("\nMemory:\n%8d%6d%6d%6d%6d%6d%6d%6d%6d%6d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
    for(int i = 0; i < 100; i += 10)
    {
        printf("%2d", i);
        for(int j = i; j < i + 10; ++j)
        {
            printf("%+6.4d", memory[j]);
        }
        printf("\n");
    }
}


