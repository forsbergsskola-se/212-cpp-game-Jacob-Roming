#include "SpikeFactory.h"
#include <chrono>

SpikeFactory::SpikeFactory(SDL_Surface* windowSurface){
	window = windowSurface;
	spikes.push_back(std::make_shared<Spike>(windowSurface));
}

void SpikeFactory::Update() {
	auto thisTickTime = std::chrono::steady_clock::now();
	double deltaTime = (double)std::chrono::duration_cast<std::chrono::nanoseconds>(thisTickTime - lastTickTime).count() / (double)1000000000;
	
	for (int i = 0; i < spikes.size(); i++) {
		spikes[i]->Update();

	}

	lastTickTime = thisTickTime;
}