#include<string>
#include<iostream>
#include "texture.h"

cTexture::cTexture():newTexture(NULL), gRend(NULL) {}

cTexture::~cTexture() {
}
void cTexture::setRenderer(SDL_Renderer* _gRend)
{
	gRend = _gRend;
}
SDL_Texture* cTexture::loadTexture(std::string path)
{
	//The final texture
	

	//Load image at specified path
	
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRend, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

SDL_Texture* cTexture::getTexture() {
	return newTexture;
}

void cTexture::close() {
	SDL_DestroyTexture(newTexture);
	newTexture = NULL;

}

