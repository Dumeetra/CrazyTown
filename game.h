#pragma once
#include <SDL.h>
#include <SDL_image.h>

class cGames {
public:
	cGames();
	//Frees media and shuts down SDL
	~cGames();
	//Starts up SDL and creates window
	bool init();
	SDL_Renderer* getrend();
	int gamewidth();
	int gameheight();
private:
	//The window we'll be rendering to
	SDL_Window* gWindow;
	//The window renderer
	SDL_Renderer* gRenderer;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
};