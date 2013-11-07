#ifndef _ENGINE_H
#define _ENGINE_H

#include "SDL.h"

namespace sdltest
{
	/** The base engine class. **/
	class CEngine
	{
	private:
		/** Last iteration's tick value **/
		long LastTick;

		/** Window width **/
		int Width;
		/** Window height **/
		int Height;

		bool bRuning;

		/** The title of the window **/
		const char* AppTitle;

		/** Screen **/
		SDL_Window* AppWindow;
		SDL_Renderer* AppRender;

		bool bPaused;

		/** Variables to calculate the frame rate **/
		/** Tick counter. **/
		int FPSTicksCounter;

		/** Frame rate counter. **/
		int FPSCounter;

		/** Stores the last calculated frame rate. **/
		int FPSCurent;

		SDL_Rect FPSRects;

	protected:
		void MainInput(const int& aDeltaTime);
		void MainTick(const int& aDeltaTime);
		void MainRender(const int& aDeltaTime);

	public:
		CEngine();
		virtual ~CEngine();
		
		void Elog(const std::string &msg);

		void Init();
		void Start();

		void SetTitle(const char* czTitle);
		const char* GetTitle();

		SDL_Renderer* GetRender();

		int GetFPS();

		virtual void Input(const int& aDeltaTime) {}
		virtual void Tick(const int& aDeltaTime) {}
		virtual void Render(SDL_Renderer* Ren, const int& aDeltaTime) {}
	};
}

#endif // ENGINE_H