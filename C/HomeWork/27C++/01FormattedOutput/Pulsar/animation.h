#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <iomanip>

namespace pulsar
{
void setParagraphs(int amountOfParagraphs);
void appear(bool down, int currentSize, const int sizeOfSquare);
void animation(int sizeOfSquare);
}

#endif // ANIMATION_H_INCLUDED
