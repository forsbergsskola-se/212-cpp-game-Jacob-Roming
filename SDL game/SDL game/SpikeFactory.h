#pragma once
#include "Spike.h"
#include<vector>
#include<memory>
class SpikeFactory : public IUpdatable
{
private:
	std::vector<std::shared_ptr<Spike>> spikes;
	SDL_Surface* window;
	std::chrono::steady_clock::time_point lastTickTime;
public:
	void Update();
	SpikeFactory(SDL_Surface* windowSurface);
};

