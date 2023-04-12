#pragma once
#include "IUpdatable.h"
#include "Image.h"
#include <SDL.h>
#include <chrono>
class Spike : public IUpdatable
{
private:
	Image* sprite;
	double movementSpeed = 20;
	std::chrono::steady_clock::time_point lastTickTime;
	double xPosition;
public:
	void Update();

	Image* getImage();
	Spike(SDL_Surface* windowSurface);


};