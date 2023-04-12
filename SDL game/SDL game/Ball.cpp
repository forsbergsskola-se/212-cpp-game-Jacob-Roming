#pragma once
#include "Ball.h"
#include <chrono>
#include <string>
#include <stdio.h>
#include <iostream>
#include "CollisionDetection.h"
#include "IUpdatable.h"

Ball::Ball(float aWeight, int aSize, SDL_Surface* windowSurface){
	weight = aWeight;
	std::string spriteName = "default.bmp";
	sprite = new Image(spriteName, windowSurface);
	size = aSize;
	xSpeed = 0;
	ySpeed = 0;
	proportion = sprite->GetProportionPointer();
	proportion->x = 20;
	proportion->y = 20;
	proportion->w = size;
	proportion->h = size;

	lastTickTime = std::chrono::steady_clock::now();
};

void Ball::Update() {
	auto thisTickTime = std::chrono::steady_clock::now();
	double deltaTime = (double)std::chrono::duration_cast<std::chrono::nanoseconds>(thisTickTime - lastTickTime).count() / (double)1000000000;
	xPosition -= (xSpeed * deltaTime);
	yPosition -= (ySpeed * deltaTime);
	proportion->x = xPosition;
	proportion->y = yPosition;
	ySpeed -= (gravity * deltaTime);

	ySpeed -= (friction * ySpeed);
	xSpeed -= (friction * xSpeed);

	lastTickTime = thisTickTime;
}

void Ball::CollidedWithSurface(SDL_Rect* other) {
	if (other->y > yPosition) {

		if (ySpeed > (double)1) {
			yPosition -= 1;
			ySpeed = ySpeed * (double)-1;
			ySpeed *= elasticity;
		}
		else {
			ySpeed = 0;
		}
	}
	else {
		xSpeed *= -1; 
		xSpeed *= elasticity;
	}
}

SDL_Surface* Ball::getImageSurfacePointer() {
	return sprite->GetSurfacePointer();
}

SDL_Rect* Ball::GetProportionPointer() {
	return sprite->GetProportionPointer();
}