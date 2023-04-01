#pragma once
#include <SDL.h>
#include <string>
class Image
{
public:
	bool success = false;
	SDL_Surface* GetSurfacePointer();
	Image(std::string imageFileName);
	~Image();
private:
	SDL_Surface* image = NULL;

};

