#pragma once
#include <SDL.h>
#include "Image.h"
#include <chrono>

class Ball {
public: 
	Ball(float weight, int size, SDL_Surface* windowSurface);

    void update();
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