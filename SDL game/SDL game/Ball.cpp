#pragma once
#include "Ball.h"
#include <chrono>

Ball::Ball(float aWeight, int aSize, SDL_Surface* windowSurface){
	weight = aWeight;
	sprite = new Image("default", windowSurface);
	size = aSize;
	xSpeed = 0;
	ySpeed = 0;
	proportion = sprite->GetProportionPointer();
	proportion->x = 500;
	proportion->y = 500;
	proportion->w = size;
	proportion->h = size;
	lastTickTime = std::chrono::steady_clock::now();
};

void Ball::update() {
	auto thisTickTime = std::chrono::steady_clock::now();
	double deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(thisTickTime - lastTickTime).count() / 1000000000;
	xPosition += (xSpeed * deltaTime);
	yPosition += (ySpeed * deltaTime);
	proportion->x = xPosition;
	proportion->y = yPosition;
	ySpeed -= (gravity * deltaTime);
	
	//TODO: implement drag
}

SDL_Surface* Ball::getImageSurfacePointer() {
	return sprite->GetSurfacePointer();
}

SDL_Rect* Ball::GetProportionPointer() {
	return sprite->GetProportionPointer();
}