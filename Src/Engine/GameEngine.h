#ifndef _GAMEENGINE_H
#define _GAMEENGINE_H

#include "Engine.h"

namespace sdltest
{
	class CGameEngine : public CEngine
	{
	public:
		void Input(const int& aDeltaTime);
		void Tick(const int& aDeltaTime);
		void Render(SDL_Renderer* Ren, const int& aDeltaTime);
	};
}

#endif