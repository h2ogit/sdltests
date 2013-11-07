#ifndef _GAME_H
#define _GAME_H

namespace sdltest
{
	class CGameEngine;

	class Game
	{

	public:
		CGameEngine* _Engine;
		int Start();

	private: 
		bool bRun;


	};
};

#endif