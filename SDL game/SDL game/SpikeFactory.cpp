#include "SpikeFactory.h"
#include <chrono>
#include <random>
#include <iostream>
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

	std::random_device rd;


	std::mt19937 e2(rd());

	std::uniform_real_distribution<> dist(0, 10000000);
	double result = std::round(dist(e2));
	if (result  < (double)10000000 * deltaTime) {
		spikes.push_back(std::make_shared<Spike>(window));
	}

	for (int i = 0; i < spikes.size(); i++) {
		if (spikes[i]->DeleteMe()) {
			spikes.erase(spikes.begin() + i);
			std::cout << "We deleted a spike" << std::endl;
		}

	}

	lastTickTime = thisTickTime;
}

std::vector<std::shared_ptr<Spike>> SpikeFactory::getSpikes() {
	return spikes;
}