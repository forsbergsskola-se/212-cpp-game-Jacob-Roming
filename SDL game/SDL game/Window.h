#pragma once
#include <SDL.h>
class Window
{

private:
	bool success;
	//The window we'll be rendering to
	SDL_Window* window;

	//The surface contained by the window
	SDL_Surface* screenSurface;
	
public:
	bool init(int width, int height);
	Window(int width, int height) {
		success = init(width, height);
	}

	void Update();

	void Destroy();
	
	void drawImage(SDL_Surface* image);

	bool WasSuccessfull() { return success; };
	SDL_Surface* GetSurfacePointer();

	SDL_Window* GetWindowPointer();
};

