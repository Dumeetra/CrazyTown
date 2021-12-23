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

//template<class T>
//void prep_paint(T a) {
//	a.loadTexture(a.getname());
//}

inline void collisions(cCar x, cCar y, cButton z){
if (abs(x.getx() - y.getx()) == 0 && abs(x.gety() - y.gety()) == 25) {
	std::cout << "You lose\n";
	getchar();
	}
	if (abs(x.getx() - y.getx()) == 25 && abs(x.gety() - y.gety()) == 0) {
		std::cout << "You lose\n";
		getchar();
	}
}
int main(int argc, char* args[])
{
	int crtnr = 0;
	int level = 0;
	std::cout << "Enter level: ";
	std::cin >> level; //level and present size of arrays
	const int max = 10; //maximum size of arrays
	
	cCar car[max];
	cStreet streets;
	cHouse house[max];
	cGames game;
	cButton button1;
	crandoms rd;//randomizes the house and the cars

	//Start up SDL and create window
	if( !game.init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		std::string name;
		streets.setname(name);
		streets.setRenderer(game.getrend());
		streets.loadTexture(streets.getname());
		rd.randomize();
		
		for (int i = 0; i <level; i++) {
			house[i].setname(i);
			house[i].setRenderer(game.getrend());
			house[i].loadTexture(house[i].getname());
			house[i].setx(rd.get1(i));
			house[i].sety(rd.get1(i));
			
		}

		for (int i = 0; i < level; i++) {
			int k = i + 1;
			car[i] = cCar(rd.get2(i));
			car[i].setname(k);
			car[i].setRenderer(game.getrend());
			car[i].loadTexture(car[i].getname());
			car[i].setw();
			car[i].seth();
			
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
					button1.setrun(true);
					}
				}
				if (button1.getrun()) {

					for (int i = 0; i < level; i++) {
						std::this_thread::sleep_for(std::chrono::milliseconds(21-2*level));//delay that decreases with increasing levels
						//set positions of cars
						car[i].setx();
						car[i].sety();
	//...................................................................					
						for (int j = 0; j < level; j++) {
							if (i != j) {
								collisions(car[i],car[j],button1);

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
									if (x > car[i].getx() && x< car[i].getx() + car[i].getw() && y>car[i].gety() && y < car[i].gety() + car[i].getw()) {//left button clicked over car
										car[i].set_turn(0);

									}
								}

							}
							if (e.button.button == SDL_BUTTON_RIGHT) {
							
								for (int i = 0; i < level; i++) {
									if (x > car[i].getx() && x< car[i].getx() + car[i].getw() && y>car[i].gety() && y < car[i].gety() + car[i].getw()) {//right button clicked over car
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

					SDL_Rect topLeftViewportc[max];
					for (int i = 0; i < level; i++) {
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
					SDL_Rect topLeftViewporth[max];
					for (int i = 0; i < level; i++) {
						//.............................................................................
								if (abs(car[i].getx() - house[i].findx_garage()) < 20 && abs(car[i].gety() - house[i].findy_garage()) < 20) {//car matches house

									house[i].setgarage(i);
									std::string name = house[i].getgarage();
									car[i].hidecar(); 
									house[i].setpark(true);
									crtnr++;
									if (crtnr == level)
									{
										std::cout << "You win!!!";
										button1.setrun(false);//-stop program
									}
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
	for (int i = 0; i < level; i++) {
    	car[i].close();
		house[i].close();
	}
	streets.close();
	game.~cGames();

	return 0;
}
