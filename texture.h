#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "game.h"

class cTexture{
public:
	cTexture();
	~cTexture();
	SDL_Texture* loadTexture(std::string);
	void setRenderer(SDL_Renderer*);
	SDL_Texture* getTexture();
	void close();

private:
	SDL_Texture* newTexture;
	SDL_Renderer* gRend;
};