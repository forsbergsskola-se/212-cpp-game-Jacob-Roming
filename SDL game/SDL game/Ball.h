#pragma once
#include <SDL.h>
#include "Image.h"
#include "IDrawable.h"
#include "IUpdatable.h"
#include <chrono>

class Ball : public IDrawable, public IUpdatable {
public: 
	Ball(float weight, int size, SDL_Surface* windowSurface);
	void Jump();
	void Update();
	void CollidedWithSurface(SDL_Rect* other);
	SDL_Surface* getImageSurfacePointer();
	SDL_Rect* GetProportionPointer();
private:
	double elasticity = 0.7; //This is a bad name but I cant come up with a better one
	double gravity = 1000;
	double friction = 0.0002;
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