#include <iostream>
#include "Game.h"
#include "../Engine/Engine.h"


using namespace sdltest;

int Game::Start()
{
	_Engine = new Engine();
	_Engine->Init();

	for (;;)
	{
		
	}
	return EXIT_SUCCESS;
}