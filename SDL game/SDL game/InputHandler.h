#pragma once
#include <SDL.h>
#include <stdio.h>
#include "Ball.h"
class InputHandler
{
public:
	static void ParseInput(SDL_Event event, Ball* ball);
};

