
//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "Window.h"
#include "Image.h"
#include "InputHandler.h"
#include "Ball.h"
#include "CollisionDetection.h"
#include "SpikeFactory.h"
#include "Spike.h"

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
	Image lowerBorder("pink.bmp", window.GetSurfacePointer());
	SDL_Rect* rect = lowerBorder.GetProportionPointer();

	SpikeFactory spikeFactory(window.GetSurfacePointer());
	rect->h = 10;
	rect->w = 9000;
	rect->y = 700;
	rect->x = 0;

	Ball ball(5,30,window.GetSurfacePointer());

	


	//window.drawImage(image.GetSurfacePointer());

	window.Update();

	
	

	//Hack to get window to stay up
	SDL_Event e; bool quit = false;

	//Game loop pattern
	while (quit == false)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT) quit = true;
			else if (e.type == SDL_KEYDOWN)
			{
				InputHandler::ParseInput(e);
				
			}
			
		}
		//window.drawImage(image.GetSurfacePointer(), image.GetProportionPointer());
		window.drawImage(background.GetSurfacePointer());
		//window.ClearScreen();
		window.drawImage(lowerBorder.GetSurfacePointer(), lowerBorder.GetProportionPointer());
		ball.Update();
		window.drawImage(ball.getImageSurfacePointer(), ball.GetProportionPointer());


		if (CollisionDetection::CheckTwoRects(ball.GetProportionPointer(), lowerBorder.GetProportionPointer())) {
			ball.CollidedWithSurface(lowerBorder.GetProportionPointer());
		}
		

		window.Update();
	}

	//Destroy window
	window.Destroy();

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}
