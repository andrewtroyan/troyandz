#include "sdlwrapper.h"
#include <exception>

using namespace std;

SDLWrapper::SDLWrapper()
{
    if(SDL_Init(SDL_INIT_VIDEO))
        throw exception();
}

SDLWrapper::~SDLWrapper()
{
     SDL_Quit();
}
