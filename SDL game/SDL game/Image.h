#pragma once
#include <SDL.h>
#include <string>

class Image
{
public:
	bool success = false;
	SDL_Surface* GetSurfacePointer();
	SDL_Rect* GetProportionPointer();
	Image(std::string imageFileName, SDL_Surface* windowSurface);
	~Image();
private:
	SDL_Surface* image = NULL;
	SDL_Rect proportion; //Is this a good name? Im not sure...
};

