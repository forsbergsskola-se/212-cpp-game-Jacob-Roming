#include "HUD.h"
#include <chrono>
#include <SDL_ttf.h>
#include <iostream>


//I wanted this to display the score in text on the screen, but it was much more complicated than I thought so it just outputs to the terminal :(

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
	std::cout << "You died! Your score: " << (int)points << std::endl;
	
	if (points > highScore) {
		highScore = points;
	}
	std::cout << "Current highscore: " << highScore << std::endl;
	points = 0;

}