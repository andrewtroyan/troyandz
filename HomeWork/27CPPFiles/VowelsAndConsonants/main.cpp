#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <cstdbool>

using namespace std;

int main()
{
    int vowels = 0, consonants = 0, counter = 1;
    char character;

    ifstream fin("../ExampleOfText.txt");

    if(fin)
    {
        do
        {
            fin >> character;
            if(character == 33 || character == 46 || character == 63)
            {
                if(vowels || consonants)
                {
                    if(vowels > consonants)
                        cout << "In " << counter << " sentence there are more vowels than consonants (" << vowels << ")." << endl;
                    else if(vowels < consonants)
                        cout << "In " << counter << " sentence there are more consonants than vowels (" << consonants << ")." << endl;
                    else
                        cout << "In " << counter << " sentence amounts of vowels and consonants are equal (" << vowels << ")." << endl;
                    ++counter;
                    vowels = 0;
                    consonants = 0;
                }
            }
            else if(strchr("AEIOUYaeiouy", character))
            {
                ++vowels;
            }
            else if((character > 65 && character < 91) || (character > 97 && character < 123))
            {
                ++consonants;
            }
        }
        while(!fin.eof());
    }
    else
    {
        cerr << "Cannot open the file." << endl;
    }

    fin.close();
    return 0;
}
