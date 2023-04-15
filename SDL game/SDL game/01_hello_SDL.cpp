
//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <chrono>
#include "Window.h"
#include "Image.h"
#include "InputHandler.h"
#include "Ball.h"
#include "CollisionDetection.h"
#include "SpikeFactory.h"
#include "Spike.h"
#include "HUD.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

enum Keypress {
	KEY_PRESS_DEFAULT,
	KEY_PRESS_UP,
	KEY_PRESS_DOWN,
	KEY_PRESS_LEFT,
	KEY_PRESS_RIGHT,
	KEY_PRESS_TOTAL //I dont remember why this is needed, but I remember marc saying it has something to do with enumeration or something like that
};


int main( int argc, char* args[] )
{
	Window window{ SCREEN_WIDTH, SCREEN_HEIGHT };

	if (!window.WasSuccessfull())
	{
		printf("Failed to initialize, something broke!");
		return -1;
	}
	Image image{ "default.bmp", window.GetSurfacePointer() };
	Image background("black.bmp", window.GetSurfacePointer());
	Image lowerBorder("blue.bmp", window.GetSurfacePointer());
	SDL_Rect* rect = lowerBorder.GetProportionPointer();

	HUD* hud = new HUD();
	SpikeFactory spikeFactory(window.GetSurfacePointer());
	rect->h = 10;
	rect->w = 9000;
	rect->y = 700;
	rect->x = 0;

	bool playerIsAlive = true;

	Ball ball(5,30,window.GetSurfacePointer());

	


	//window.drawImage(image.GetSurfacePointer());

	window.Update();

	
	

	//Hack to get window to stay up
	SDL_Event e; bool quit = false;

	//Game loop pattern
	while (quit == false)
	{
		if (playerIsAlive) {
			while (SDL_PollEvent(&e))
			{
				//Event queue pattern
				if (e.type == SDL_QUIT) quit = true;
				else if (e.type == SDL_KEYDOWN)
				{
					InputHandler::ParseInput(e, &ball);//sending a pointer to the ball like this is bad
					//If we were smarter we would do this some other way, too bad!
				}

			}
			window.drawImage(background.GetSurfacePointer());//This "clears" the screen of the previous frames content
			window.drawImage(lowerBorder.GetSurfacePointer(), lowerBorder.GetProportionPointer()); //The platform at the bottom of the screen

			ball.Update(); //Tell the ball to update its logic
			window.drawImage(ball.getImageSurfacePointer(), ball.GetProportionPointer()); //And then draw it

			spikeFactory.Update(); //Tell the spike factory to update all the spikes positions
			hud->Update();

			std::vector<std::shared_ptr<Spike>> spikes = spikeFactory.getSpikes();  //Get pointers to the spike so we can draw them and colision check them against the player
			//Draw spikes and check their colision
			for (int i = 0; i < spikes.size(); i++) {
				window.drawImage(spikes[i]->getImage()->GetSurfacePointer(), spikes[i]->getImage()->GetProportionPointer());

				if (CollisionDetection::CheckTwoRects(spikes[i]->getImage()->GetProportionPointer(), ball.GetProportionPointer())) {
					hud->KillPlayer();
					playerIsAlive = false;
				}
			}


			if (CollisionDetection::CheckTwoRects(ball.GetProportionPointer(), lowerBorder.GetProportionPointer())) {
				ball.CollidedWithSurface(lowerBorder.GetProportionPointer());
			}


			window.Update();
		}
		else {
			auto startTime = std::chrono::steady_clock::now();
			double TimeDifference = 0;
			do {
				auto currentTime = std::chrono::steady_clock::now();
				TimeDifference = (double)std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();
			} while (TimeDifference < 1);

			playerIsAlive = true;
			spikeFactory = SpikeFactory(window.GetSurfacePointer());
			ball = Ball(5, 30, window.GetSurfacePointer());

		}
	}

	//Destroy window
	window.Destroy();

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}
