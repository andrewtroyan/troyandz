#include "stackpletronOperations.h"

int entryMemory(int memory[])
{
    int accumulator = 0, code = 0, instructionCounter = 0;
    while(instructionCounter < SIZEOFMEMORY)
    {
        printf("%02d? ", instructionCounter);
        do
        {
            scanf("%d", &accumulator);
            code = abs(accumulator / 100);
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
        if(code == 0 || code == 10 || code == 11 || code == 20 || code == 21 || code == 22 ||
           code == 23 || code == 24 || code == 25 || code == 26 || code == 27 ||
           code == 30 || code == 31 || code == 32 || code == 33 || code == 34 ||
           code == 40 || code == 41 || code == 42 || code == 43 || code == 44 || code == 45)
        {
            ++instructionCounter;
        }
    }
    printf("*** The memory is full. ***\n");
    exit(1);
}

static int accumulator = +0000, bias = 0, top = 100, operationCode = 00, operand = 00, instructionRegister = +0000, instructionCounter = 00, literal;

void push(int stack[], int number)
{
    stack[--top] = number;
}

int pop(int stack[])
{
    int result = stack[top];
    stack[top++] = 0;
    return result;
}

void runProgram(int memory[])
{
    do
    {
        instructionRegister = memory[instructionCounter];
        operationCode = abs(instructionRegister / 100);
        operand = bias + (instructionRegister % 100);
        literal = instructionRegister % 100;
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
        case 22:
            accumulator = top;
            ++instructionCounter;
            break;
        case 23:
            top = accumulator;
            ++instructionCounter;
            break;
        case 24:
            accumulator = bias;
            ++instructionCounter;
            break;
        case 25:
            bias = accumulator;
            ++instructionCounter;
            break;
        case 26:
            push(memory, accumulator);
            ++instructionCounter;
            break;
        case 27:
            accumulator = pop(memory);
            ++instructionCounter;
            break;
        case 30:
            if(accumulator + memory[operand] < -9999 || accumulator + memory[operand] > 9999)
            {
                printf("*** Accumulator is overfull! ***\n*** Stackpletron finished work emergency! ***\n");
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
                printf("*** Accumulator is overfull! ***\n*** Stackpletron finished work emergency! ***\n");
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
                printf("*** You tried to divide by zero! ***\n*** Stackpletron finished work emergency! ***\n");
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
                printf("*** Accumulator is overfull! ***\n*** Stackpletron finished work emergency! ***\n");
                exit(1);
            }
            else
            {
                accumulator *= memory[operand];
                ++instructionCounter;
            }
            break;
        case 34:
            accumulator = literal;
            ++instructionCounter;
            break;
        case 40:
            instructionCounter = literal;
            break;
        case 41:
            if(accumulator < 0)
            {
                instructionCounter = literal;
            }
            else
            {
                ++instructionCounter;
            }
            break;
        case 42:
            if(accumulator == 0)
            {
                instructionCounter = literal;
            }
            else
            {
                ++instructionCounter;
            }
            break;
        case 43:
            printf("*** Stackpletron is stopped. ***\n");
            break;
        case 44:
            push(memory, instructionCounter + 1);
            instructionCounter = literal;
            break;
        case 45:
            instructionCounter = pop(memory);
            for(int i = 0; i < literal; ++i)
            {
                accumulator = pop(memory);
            }
        }
    }while(operationCode != 43);
}

void memoryDump(int memory[])
{
    printf("\nRegisters:\n%-19s%+9.4d\n%-19s%+9.4d\n%-19s%+9.4d\n%-19s%9.2d\n%-19s%+9.4d\n%-19s%9.2d\n%-19s%9.2d\n", "accumulator", accumulator,
           "bias", bias, "top", top, "instructionCounter", instructionCounter, "instructionRegister", instructionRegister,
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


