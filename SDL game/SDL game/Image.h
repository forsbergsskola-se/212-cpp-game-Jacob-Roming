#pragma once
#include <SDL.h>
#include <string>
class Image
{
public:
	bool success = false;
	SDL_Surface* GetSurfacePointer();
	Image(std::string imageFileName, SDL_Surface* windowSurface);
	~Image();
private:
	SDL_Surface* image = NULL;
	SDL_Surface* optimisedImage = NULL;
};

