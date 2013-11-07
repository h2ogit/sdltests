#include <string>
#include <iostream>
#include "Game.h"
#include "../Engine/GameEngine.h"

using namespace sdltest;

namespace sdltest
{
	static void log(const std::string &msg)
	{
		std::cout << msg << std::endl;
	}
}


int Game::Start()
{
	_Engine = new CGameEngine();
	
	log("Init");
	_Engine->Init();

	log("Starting");
	_Engine->Start();

	return EXIT_SUCCESS;
}

void CGameEngine::Input(const int& aDeltaTime)
{

}

void CGameEngine::Tick(const int& aDeltaTime)
{

}

void CGameEngine::Render(SDL_Renderer* Ren, const int& aDeltaTime)
{
	
}
