#include "Image.h"
#include <SDL.h>
#include <string>
Image::Image(std::string imageFileName, SDL_Surface* windowSurface) {

	SDL_Surface* optimisedImage = NULL;
	success = false; //Not needed? Since we initialise it to this in the header file. Feels good to do it again though...
	std::string filePath = "resources/images/";
	filePath += imageFileName;
	image = SDL_LoadBMP(filePath.c_str());
	if (image == NULL) {
		printf("Unable to load image %s! SDL Error: %s\n", filePath, SDL_GetError());
		return;
	}
	success = true;

	optimisedImage = SDL_ConvertSurface(image, windowSurface->format, 0);

	if (optimisedImage == NULL) {
		printf("Failed to create an optimised version of the image!\n");
		return;
	}

	SDL_FreeSurface(image);
	image = optimisedImage;
	
	//SDL_BlitScaled(image, NULL, windowSurface, &proportion);
}

SDL_Rect* Image::GetProportionPointer() {
	return &proportion;
}

Image::~Image() {
	SDL_FreeSurface(image); //Dealocate the image if we are getting destroyed anyway
	image = nullptr;
}

SDL_Surface* Image::GetSurfacePointer() {
	return image;
}