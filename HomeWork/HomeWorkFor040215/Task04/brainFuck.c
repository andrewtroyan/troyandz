#define SIZE 1000

static int pair[SIZE] = {0};

int fillArrayWithSymbols(char symbols[], int size)
{
    char symbol;
    int stack[SIZE] = {0}, top = -1;
    for(int i = 0; i < size; ++i)
    {
        symbol = getchar();
        if(symbol == '\n')
        {
            symbols[i] = symbol;
            return 0;
        }
        else if(symbol == '[')
        {
            symbols[i] = symbol;
            stack[++top] = i;
        }
        else if(symbol == ']')
        {
            symbols[i] = symbol;
            pair[i] = stack[top];
            pair[stack[top]] = i;
            stack[top--] = 0;
        }
        else
        {
            symbols[i] = symbol;
        }
    }
    return 0;
}

void runTheProgram(char symbols[])
{
    unsigned char string[SIZE] = {0};
    int directionString = 0, directionSymbols = 0;
    while(symbols[directionSymbols] != '\n')
    {
        switch(symbols[directionSymbols])
        {
        case '+':
            ++string[directionString];
            ++directionSymbols;
            break;
        case '-':
            --string[directionString];
            ++directionSymbols;
            break;
        case '>':
            ++directionString;
            ++directionSymbols;
            break;
        case '<':
            --directionString;
            ++directionSymbols;
            break;
        case '.':
            putchar(string[directionString]);
            ++directionSymbols;
            break;
        case ',':
            string[directionString] = getchar();
            ++directionSymbols;
            break;
        case '[':
            if(string[directionString] == 0)
            {
                directionSymbols = pair[directionSymbols] + 1;
            }
            else
            {
                ++directionSymbols;
            }
            break;
        case ']':
            if(string[directionString] == 0)
            {
                ++directionSymbols;
            }
            else
            {
                directionSymbols = pair[directionSymbols] + 1;
            }
            break;
        }
    }

}
