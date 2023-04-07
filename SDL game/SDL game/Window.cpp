#include "Window.h"
#include <SDL.h>
#include <stdio.h>

bool Window::init(int width, int height) {


	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}
	
	//Create window
	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (!window)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	//Get window surface
	screenSurface = SDL_GetWindowSurface(window);

	//Fill the surface white
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

	//Update the surface
	SDL_UpdateWindowSurface(window);
		

	
	return true;
}

void Window::drawImage(SDL_Surface* image) {
	SDL_BlitSurface(image, NULL, screenSurface, NULL);
}

void Window::drawImage(SDL_Surface* image, SDL_Rect* proportion) {
	SDL_BlitScaled(image, NULL, screenSurface, proportion);
}

void Window::Update() {
	SDL_UpdateWindowSurface(window);
}

void Window::Destroy() {
	SDL_DestroyWindow(window);
}

SDL_Surface* Window::GetSurfacePointer() {
	return screenSurface;
}

SDL_Window* Window::GetWindowPointer() {
	return window;
}

void Window::ClearScreen() {
	drawImage(screenSurface);
}