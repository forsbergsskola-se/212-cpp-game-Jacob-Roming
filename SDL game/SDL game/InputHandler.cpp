#include "InputHandler.h"
void InputHandler::ParseInput(SDL_Event event) {
	
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

		default:
			break;
		}
}
