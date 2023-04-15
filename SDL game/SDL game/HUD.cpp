#include "HUD.h"
#include <chrono>
#include <SDL_ttf.h>
#include <iostream>

HUD::HUD() {
	lastTickTime = std::chrono::steady_clock::now();
}

void HUD::Update() {
	auto thisTickTime = std::chrono::steady_clock::now();
	double deltaTime = (double)std::chrono::duration_cast<std::chrono::nanoseconds>(thisTickTime - lastTickTime).count() / (double)1000000000;
	
	
	points += (pointsScoreRate * deltaTime);
	std::cout << "Current score: " << points << std::endl;
	
		
	lastTickTime = thisTickTime;

}

void HUD::KillPlayer() {
	std::cout << "You died! Your score: " << points << std::endl;
	
	if (points > highScore) {
		highScore = points;
	}
	std::cout << "Current highscore: " << highScore << std::endl;
	points = 0;

}