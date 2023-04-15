#pragma once
#include "IUpdatable.h"
#include <chrono>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>
class HUD : public IUpdatable
{
private:
	double points = 0;
	int highScore = 0;
	double pointsScoreRate  = 10;
	std::chrono::steady_clock::time_point lastTickTime;

public:
	void Update();
	HUD();
	void KillPlayer();


    
};

