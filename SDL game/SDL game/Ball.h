#pragma once
#include <SDL.h>
#include "Image.h"
#include "IDrawable.h"
#include <chrono>

class Ball : public IDrawable {
public: 
	Ball(float weight, int size, SDL_Surface* windowSurface);
	void update();
	SDL_Surface* getImageSurfacePointer();
	SDL_Rect* GetProportionPointer();
private:
	double gravity = 4;
	double friction = 0.005;
	std::chrono::steady_clock::time_point lastTickTime;
	double xSpeed;
	double ySpeed;
	double xPosition;
	double yPosition;
	float weight;
	int size;
	SDL_Rect* proportion;
	Image* sprite;
};