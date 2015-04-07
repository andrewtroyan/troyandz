#include "animation.h"

using namespace std;

void pulsar::setParagraphs(int amountOfParagraphs)
{
    if(amountOfParagraphs)
    {
        setParagraphs(--amountOfParagraphs);
        cout << endl;
    }
}

void pulsar::animation(int sizeOfSquare)
{
    appear(true, sizeOfSquare, sizeOfSquare);
}


void pulsar::appear(bool down, int currentSize, const int sizeOfSquare)
{
    system("clear");
    if(currentSize == sizeOfSquare)
    {
        for(int i = 0; i < currentSize; ++i)
            cout << setw(currentSize) << setfill('*') << '*' << endl;
        system("sleep 0.2");
        appear(true, currentSize - 2, sizeOfSquare);
    }
    else if(currentSize <= 0)
    {
        setParagraphs(sizeOfSquare);
        system("sleep 0.2");
        appear(false, currentSize + 2, sizeOfSquare);
    }
    else
    {
        setParagraphs((sizeOfSquare - currentSize) / 2);
        for(int i = 0; i < currentSize; ++i)
        {
            cout << setw((sizeOfSquare - currentSize) / 2) << setfill(' ') << ' ';
            cout << setw(currentSize) << setfill('*') << '*';
            cout << setw((sizeOfSquare - currentSize) / 2) << setfill(' ') << ' ' << endl;
        }
        system("sleep 0.2");
        if(down)
            appear(true, currentSize - 2, sizeOfSquare);
        else
            appear(false, currentSize + 2, sizeOfSquare);
    }
}
