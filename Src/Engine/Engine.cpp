#include <iostream>
#include <string>
#include "Engine.h"
#include "SDL.h"

using namespace sdltest;

/** Default constructor. **/
CEngine::CEngine()
{
	LastTick = 0;
	Width = 800;
	Height = 600;
	AppTitle = "SDL TEST";

	AppWindow = 0;
	AppRender = 0;

	FPSTicksCounter = 0;
	FPSCounter = 0;
	FPSCurent = 0;

	FPSRects.h = 10;
	FPSRects.w = 100;
	FPSRects.x = 10;
	FPSRects.y = 10;


	bPaused = false;
}

/** Destructor. **/
CEngine::~CEngine()
{
	SDL_DestroyRenderer(AppRender);
	SDL_DestroyWindow(AppWindow);
	SDL_Quit();
}

/** Initialize SDL, the window and the additional data. **/
void CEngine::Init()
{
	// Initialize SDL's subsystems - in this case, only video.
	if (SDL_Init(SDL_INIT_EVERYTHING) < EXIT_SUCCESS)
	{
		fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	// Attempt to create a window with the specified height and width.
	AppWindow = SDL_CreateWindow(AppTitle, 100, 100, Width, Height, SDL_WINDOW_SHOWN);
	if (AppWindow == nullptr){
		fprintf(stderr, "Unable to Create Window: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	AppRender = SDL_CreateRenderer(AppWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (AppRender == nullptr){
		fprintf(stderr, "Unable to Create Render: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
	SDL_ShowCursor(1);
}

/** The main loop. **/
void CEngine::Start()
{
	LastTick = SDL_GetTicks();
	bRuning = true;

	// Main loop: loop forever.
	while (bRuning)
	{
		long lDeltaTime = SDL_GetTicks() - LastTick;
		LastTick = SDL_GetTicks();
		FPSTicksCounter += lDeltaTime;

		// Handle mouse and keyboard input
		MainInput(lDeltaTime);

		if (bPaused)
		{
			SDL_Delay(100);
		}
		else
		{
			// Do some things
			MainTick(lDeltaTime);

			// Render stuff
			MainRender(lDeltaTime);
		}

		SDL_Delay(100);
		fprintf(stderr, "FPSTicksCounter: %s\n", &FPSTicksCounter);
	}
}

/** Handles all controller inputs.
@remark This function is called once per frame.
**/
void CEngine::MainInput(const int& aDeltaTime)
{
	//Input(aDeltaTime);
}

/** Handles the updating routine. **/
void CEngine::MainTick(const int& aDeltaTime)
{
	Tick(aDeltaTime);
}

/** Handles the rendering and FPS calculations. **/
void CEngine::MainRender(const int& aDeltaTime)
{
	++FPSCounter;
	if (FPSTicksCounter >= 1000)
	{
		FPSCurent = FPSCounter;
		FPSCounter = 0;
		FPSTicksCounter = 0;
	}

	SDL_RenderClear(AppRender);

	//SDL_RenderFillRect(AppRender, &FPSRects);

	
	
	Render(AppRender, aDeltaTime);

	SDL_RenderPresent(AppRender);

}

void CEngine::SetTitle(const char* czTitle)
{
	AppTitle = czTitle;
}

const char* CEngine::GetTitle()
{
	return AppTitle;
}

/** Get the current FPS.
@return The number of drawn frames in the last second.
@remark The FPS is only updated once each second.
**/
int CEngine::GetFPS()
{
	return FPSCurent;
}