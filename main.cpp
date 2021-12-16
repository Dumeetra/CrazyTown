/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include<cstdlib>
#include<ctime> 
#include <chrono>
#include <thread>
#include "house.h"
#include "car.h"
#include "streets.h"
#include "buttons.h"
#include "random.h"
#include "game.h"
#include <iostream>
//Screen dimension constants
int main(int argc, char* args[])
{
	int m = 0;
	std::cout << "Enter level: ";
	std::cin >> m; //level and present size of arrays
	const int level = 10; //maximum size of arrays
	
	cCar car[level];
	cStreet streets;
	cHouse house[level];
	cGames game;
	cButton button1;
	crandoms rd;
	
	//Start up SDL and create window
	if( !game.init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		std::string name;
	name = "streets.png";
		streets.setname(name);
		streets.setRenderer(game.getrend());
		streets.loadTexture(name);
		

		rd.randomize();
		
		for (int i = 0; i <m; i++) {
			house[i].setname(i);
			house[i].setRenderer(game.getrend());
			house[i].setx(rd.get1(i));
			house[i].sety(rd.get1(i));
			house[i].loadTexture(house[i].getname());
		}

		for (int i = 0; i < m; i++) {
			int k = i + 1;
			car[i] = cCar(rd.get2(i));
			car[i].setname(k);
			car[i].setw();
			car[i].seth();
			car[i].setRenderer(game.getrend());
			car[i].loadTexture(car[i].getname());
		}
		button1.setname("play.png");
		button1.setRenderer(game.getrend());
		
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while( !quit )
			{
				int x, y;
				SDL_GetMouseState(&x, &y);
				
				if (x >255 && x<355 && y > 215 && y<255) {
					if (e.type == SDL_MOUSEBUTTONDOWN)
					{
					button1.setrun();
					}
				}
						
				if (button1.getrun()) {

					for (int i = 0; i < m; i++) {
						std::this_thread::sleep_for(std::chrono::milliseconds(11-level));//delay that decreases with increasing levels

						car[i].setx();
						car[i].sety();
	//...................................................................					
						for (int j = 0; j < m; j++) {
							if (i != j) {
								if (abs(car[i].getx() - car[j].getx()) == 0 && abs(car[i].gety() - car[j].gety()) == 25) {
									button1.stop();//crash!!!-stop program
								}
								if (abs(car[i].getx() - car[j].getx()) == 25 && abs(car[i].gety() - car[j].gety()) == 0) {
									button1.stop();//crash!!!-stop program
								}
							}
						}
	//.....................................................
						if (car[i].get_turn()) {
							car[i].find_intersection();
						}
					
					}
				}

						//Handle events on queue
					while (SDL_PollEvent(&e) != 0)
					{
						//User requests quit
						if (e.type == SDL_QUIT)
						{
							quit = true;
						}
						if (e.type == SDL_MOUSEBUTTONDOWN) {
							if (e.button.button == SDL_BUTTON_LEFT) {
								for (int i = 0; i < level; i++) {
									if (x > car[i].getx() && x< car[i].getx() + car[i].getw() && y>car[i].gety() && y < car[i].gety() + car[i].getw()) {//left button clicked on car
										car[i].set_turn(0);

									}
								}

							}
							if (e.button.button == SDL_BUTTON_RIGHT) {
							
								for (int i = 0; i < level; i++) {
									if (x > car[i].getx() && x< car[i].getx() + car[i].getw() && y>car[i].gety() && y < car[i].gety() + car[i].getw()) {//right button clicked on car
										car[i].set_turn(1);

									}
								}

							}
							
						}
					}
				

					//Clear screen
					SDL_SetRenderDrawColor(game.getrend(), 80, 80, 80, 0xFF);
					SDL_RenderClear(game.getrend());
					SDL_Rect topLeftViewport;
					topLeftViewport.x = 0;
					topLeftViewport.y = 0;
					topLeftViewport.w = game.gamewidth();
					topLeftViewport.h = game.gameheight();

					SDL_RenderSetViewport(game.getrend(), &topLeftViewport);
					SDL_RenderCopy(game.getrend(), streets.getTexture(), NULL, NULL);

					SDL_Rect topLeftViewportc[level];
					for (int i = 0; i < m; i++) {
						if (car[i].changeTexture()) {
							int k = i + 1;
							car[i].changename();
							car[i].changew();
							car[i].changeh();
							car[i].loadTexture(car[i].getname());
							car[i].noTexture();
						}
						topLeftViewportc[i].x = car[i].getx();
						topLeftViewportc[i].y = car[i].gety();
						topLeftViewportc[i].w = car[i].getw();
						topLeftViewportc[i].h = car[i].geth();
						SDL_RenderSetViewport(game.getrend(), &topLeftViewportc[i]);
						SDL_RenderCopy(game.getrend(), car[i].getTexture(), NULL, NULL);
					}
					SDL_Rect topLeftViewporth[level];
					for (int i = 0; i < m; i++) {
						//.............................................................................
								if (abs(car[i].getx() - house[i].findx_garage()) < 20 && abs(car[i].gety() - house[i].findy_garage()) < 20) {//car matches house

									house[i].setgarage(i);
									std::string name = house[i].getgarage();
									car[i].hidecar(); 
									house[i].setpark(true);
								}
							//...............................................................................
							topLeftViewporth[i].x = house[i].getx();
							topLeftViewporth[i].y = house[i].gety();
							topLeftViewporth[i].w = house[i].getw();
							topLeftViewporth[i].h = house[i].geth();
							SDL_RenderSetViewport(game.getrend(), &topLeftViewporth[i]);
							if (house[i].getpark() == false) {
								SDL_RenderCopy(game.getrend(), house[i].getTexture(), NULL, NULL);
							}
							else {
								SDL_RenderCopy(game.getrend(), house[i].loadTexture(house[i].getgarage()), NULL, NULL);
							}
							
						
					}
					SDL_Rect topLeftViewportb1;

					topLeftViewportb1.x = 255;
					topLeftViewportb1.y = 215;
					topLeftViewportb1.w = 100;
					topLeftViewportb1.h = 40;
					SDL_RenderSetViewport(game.getrend(), &topLeftViewportb1);
					SDL_RenderCopy(game.getrend(), button1.loadTexture(button1.getname()), NULL, NULL);
					
					//Update screen
					SDL_RenderPresent(game.getrend());

				}
	}

	//Free resources and close SDL
	for (int i = 0; i < m; i++) {
    	car[i].close();
		house[i].close();
	}
	streets.close();
	game.~cGames();

	return 0;
}