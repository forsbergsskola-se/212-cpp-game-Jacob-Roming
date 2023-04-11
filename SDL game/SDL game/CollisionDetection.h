#pragma once
#include <SDL.h>
#include "Ball.h"
class CollisionDetection
{
public:
	static bool CheckTwoRects(SDL_Rect* a, SDL_Rect* b);
	bool CheckBallAndRect(Ball* a, SDL_Rect* b);
};

