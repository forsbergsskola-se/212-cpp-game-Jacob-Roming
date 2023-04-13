#include "InputHandler.h"
#include "Ball.h"
void InputHandler::ParseInput(SDL_Event event, Ball* ball) { //I hate including the ball as an argument like this but Im not smart enough to come up with a better solution :(
	
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			printf("We pressed up\n");
			break;

		case SDLK_DOWN:
			printf("We pressed down\n");
			break;

		case SDLK_LEFT:
			printf("We pressed left\n");
			break;

		case SDLK_RIGHT:
			printf("We pressed right\n");
			break;

		case SDLK_SPACE:
			printf("Jump!\n");
			ball->Jump();
			break;

		default:
			break;
		}
}
