
//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "Window.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{
	Window window{ SCREEN_WIDTH, SCREEN_HEIGHT };

	if (!window.WasSuccessfull())
	{
		printf("Failed to initialize, something broke!");
		return -1;
	}



	

	//Hack to get window to stay up
	SDL_Event e; bool quit = false;
	while (quit == false)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT) quit = true;
		}
	}

	//Destroy window
	window.Destroy();

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}
