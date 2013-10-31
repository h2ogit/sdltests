#ifndef _GAME_H
#define _GAME_H

namespace sdltest
{
	class Engine;

	class Game
	{

	public:
		Engine* _Engine;
		int Start();

	private: 
		bool bRun;


	};
};

#endif