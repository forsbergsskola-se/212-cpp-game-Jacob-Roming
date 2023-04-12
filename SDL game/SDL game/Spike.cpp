#include "Spike.h"
#include <SDL.h>

void Spike::Update() {

	auto thisTickTime = std::chrono::steady_clock::now();
	double deltaTime = (double)std::chrono::duration_cast<std::chrono::nanoseconds>(thisTickTime - lastTickTime).count() / (double)1000000000;
	xPosition -= movementSpeed * deltaTime;
	SDL_Rect* proportion = sprite->GetProportionPointer();
	proportion->x = xPosition;


	lastTickTime = thisTickTime;

}

Spike::Spike(SDL_Surface* windowSurface){
	sprite = new Image("pink.bmp", windowSurface);
	SDL_Rect* proportion = sprite->GetProportionPointer();

	proportion->y = 670; //I like magic numbers, theyre comfy and easy to write
	proportion->x = 400;
	proportion->h = 30;
	proportion->w = 20;
	xPosition = proportion->x;


}