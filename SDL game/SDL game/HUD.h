#pragma once
#include "IUpdatable.h"
#include <chrono>
#include <SDL_ttf.h>
class HUD : public IUpdatable
{
private:
	double points;
	int highScore;
	double pointsScoreRate;
	std::chrono::steady_clock::time_point lastTickTime;

public:
	void Update();
	HUD();
	void KillPlayer();
};

