#include "Spike.h"
#include <SDL.h>
#include <iostream>

void Spike::Update() {

	auto thisTickTime = std::chrono::steady_clock::now();
	double deltaTime = (double)std::chrono::duration_cast<std::chrono::nanoseconds>(thisTickTime - lastTickTime).count() / (double)1000000000;
	std::cout <<"xPosition: " << xPosition << " Movement Speed: "<< movementSpeed << " Delta time: "<< deltaTime << std::endl;
	xPosition = xPosition - (movementSpeed * deltaTime);
	std::cout << xPosition << std::endl;
	SDL_Rect* proportion = sprite->GetProportionPointer();
	proportion->x = xPosition;


	lastTickTime = thisTickTime;

}

Spike::Spike(SDL_Surface* windowSurface){
	sprite = new Image("pink.bmp", windowSurface);
	SDL_Rect* proportion = sprite->GetProportionPointer();

	proportion->y = 670; //I like magic numbers, theyre comfy and easy to write
	proportion->x = 150;
	proportion->h = 30;
	proportion->w = 20;
	xPosition = 150;

	lastTickTime = std::chrono::steady_clock::now();



}

Image* Spike::getImage(){
	return sprite;
}