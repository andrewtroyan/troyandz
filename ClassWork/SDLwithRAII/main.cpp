#include <iostream>
#include <exception>
#include "sdlwrapper.h"

using namespace std;

int main()
{
    try
    {

    }
    catch(exception &e)
    {
        cerr << "ERROR: " << e.what() << endl;
    }
    catch(...)
    {
        cerr << "ERROR: something happened" << endl;
    }
    return 0;
}
