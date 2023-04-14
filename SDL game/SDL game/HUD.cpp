#include "HUD.h"
#include <chrono>
#include <SDL_ttf.h>

HUD::HUD() {
	lastTickTime = std::chrono::steady_clock::now();
}

void HUD::Update() {
	auto thisTickTime = std::chrono::steady_clock::now();
	double deltaTime = (double)std::chrono::duration_cast<std::chrono::nanoseconds>(thisTickTime - lastTickTime).count() / (double)1000000000;
	
	
	points += (pointsScoreRate * deltaTime);
	
		
	lastTickTime = thisTickTime;

}

void HUD::KillPlayer() {
	highScore = points;
	points = 0;

}