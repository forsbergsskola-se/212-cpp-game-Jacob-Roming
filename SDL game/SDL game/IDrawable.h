#pragma once
#include <SDL.h>
class IDrawable
{
	virtual SDL_Surface* getImageSurfacePointer() = 0;
	virtual SDL_Rect* GetProportionPointer() = 0;
};

