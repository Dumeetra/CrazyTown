#ifndef CAR_H
#define CAR_H
#include <vector>
#include "texture.h"

class cCar :public cTexture {
public:
	cCar();
	cCar(int);
	void setx();
	void sety();
	int getx();
	int gety();

	void setw();
	void seth();
	int getw();
	int geth();
	int changew();
	int changeh();
	void hidecar();

	void setname(int);
	std::string getname();
	void changename();
	bool changeTexture();
	bool noTexture();
	void set_turn(bool);
	bool get_turn();
	void find_intersection();

private:
	int x, y, w, h;
	bool txtr=false;
	std::string name;
	std::string nextname;
	std::vector<int>x_car = { 196,389,582,0,747,0,747,196,389,582 };
	std::vector<int>y_car = { 0,0,0,159,159,300,300,438,438,438 };
	std::vector<int>x_street = { 0,196,389,582,782,0,196,389,582,782,0,196,389,582,782,0,196,389,582,782 };
	std::vector<int>y_street = { 0,0,0,0,0,159,159,159,159,159,300,300,300,300,300,438,438,438,438,438 };

	enum class Direction { up, down, left, right, none };
	std::vector<Direction> dir = { Direction::down,Direction::down,Direction::down,Direction::right,Direction::left,Direction::right,Direction::left,Direction::up,Direction::up,Direction::up };

	Direction curr_dir;
	Direction turn;	
};
#endif