#include <iostream>
#include "Game.h"

using namespace sdltest;

Game* _Game = 0;

int main(int argc, char **argv)
{
	_Game = new Game();
	return _Game->Start();
}

// http://content.gpwiki.org/index.php/SDL:Tutorials