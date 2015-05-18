#include <stdio.h>
#include <math.h>
#include <unistd.h>

int main()
{
    short int buffer[64];
    for(int i = 0; i < 44100 * 5 / 64; ++i)
    {
        for(int j = 0; j < 64; ++j)
        {
            buffer[j] = 20000 * (sin((i * 64 + j) * 220 * 2 * 3.14159265 / 44100.0));
        }
        write(1, buffer, 64 * sizeof(short int));
    }
    return 0;
}
