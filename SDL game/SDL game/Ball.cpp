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

Ball::~Ball() {
	//delete sprite; This causes a crash! So instead we have a memory leak. 
}

void Ball::Update() {
	auto thisTickTime = std::chrono::steady_clock::now();
	double deltaTime = (double)std::chrono::duration_cast<std::chrono::nanoseconds>(thisTickTime - lastTickTime).count() / (double)1000000000;
	xPosition -= (xSpeed * deltaTime);
	yPosition -= (ySpeed * deltaTime);
	proportion->x = xPosition;
	proportion->y = yPosition;
	ySpeed -= (gravity * deltaTime);

	ySpeed -= (friction * ySpeed);

	lastTickTime = thisTickTime;
}

void Ball::Jump() {
	if ((int)yPosition == 671) { //We could do some complicated collision check to see if we are on the ground, instead we get this magic number
		yPosition -= 1;
		ySpeed = 600;
	}
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