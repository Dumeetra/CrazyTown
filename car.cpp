#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<cmath>
#include "car.h"


cCar::cCar(){};
cCar::cCar(int i) :w(25), h(15), turn(Direction::none) {
	x = x_car[i];
	y = y_car[i];
	curr_dir = dir[i];
}
void cCar::setx() {
	switch (curr_dir) {
	case Direction::up:
		break;
	case Direction::down:
		break;
	case Direction::left:
		if (x > 0) {
			x--;
		}
		break;
	case Direction::right:
		if (x < 747) {
			x++;
		}
		else {
			std::cout << "You are blocked!\n";
		}
		break;
	}

}
void cCar::sety() {
	switch (curr_dir) {
	case Direction::up:
		if (y > 0) {
			y--;

		}
		break;
	case Direction::down:
		if (y < 438) {
			y++;
		}
		break;
	case Direction::left:
		break;
	case Direction::right:
		break;
	}

}
int cCar::getx() {
	return x;
}
int cCar::gety() {
	return y;
}
int cCar::getw() {
	return w;
}
int cCar::geth() {
	return h;
}
void cCar::setw() {
	if (y == 0 || y == 438) {
		w = 15;
	}
	else {
		w = 25;
	}
}
void cCar::seth() {
	if (y == 0 || y == 438) {
		h = 25;
	}
	else {
		h = 15;
	}
}
int cCar::changew() {
	if (w == 25) {
		w = 15;
	}
	else if (w == 15) {
		w = 25;
	}
	return w;
}
int cCar::changeh() {
	if (h == 25) {
		h = 15;
	}
	else if (h == 15) {
		h = 25;
	}

	return h;
}

void cCar::setname(int kIn) {
	if (y == 0 || y == 438) {
		name = "car" + std::to_string(kIn) + "v.png";
		nextname = "car" + std::to_string(kIn) + ".png";
	}
	else {
		name = "car" + std::to_string(kIn) + ".png";
		nextname = "car" + std::to_string(kIn) + "v.png";
	}
}

void cCar::changename() {
	if (y != 0 && y != 438) {
		std::string str;
		str = name;
		name = nextname;
		nextname = str;
	}
}
std::string cCar::getname() {
	return name;
}
bool cCar::changeTexture() {
	return txtr;

}

bool cCar::noTexture()
{
	turn = Direction::none;
	txtr = false;
	return txtr;
}

void cCar::hidecar() {
	x = -35;
	y = -35;
}

void cCar::set_turn(bool bttn) {
	//if (turn == Direction::none) {
	switch (curr_dir) {
	case Direction::up:
		if (!bttn) {
			turn = Direction::left;
		}
		else {
			turn = Direction::right;
		}
		break;
	case Direction::down:
		if (!bttn) {
			turn = Direction::left;
		}
		else {
			turn = Direction::right;
		}
		break;
	case Direction::right:
		if (!bttn) {
			turn = Direction::up;
		}
		else {
			turn = Direction::down;
		}
		break;
	case Direction::left:
		if (!bttn) {
			turn = Direction::up;
		}
		else {
			turn = Direction::down;
			break;
		}
	}
	//}
}
bool cCar::get_turn() {
	if (turn != Direction::none) {
		return true;
	}
	else {
		return false;
	}

}
void cCar::find_intersection()
{

	if (turn != Direction::none)
	{

		txtr = false;
		for (const int& value : x_street)
		{

			for (const int& value2 : y_street)
			{

				if (x == value && y == value2) {
					curr_dir = turn;
					changename();
					txtr = true;
				}


			}
		}
	}

}
