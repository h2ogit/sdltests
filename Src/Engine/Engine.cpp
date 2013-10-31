#include <iostream>
#include <SDL.h>
#include "Engine.h"

using namespace sdltest;

int Engine::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != EXIT_SUCCESS)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}