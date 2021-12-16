
#include "house.h"
std::vector<int>x_coord = { 48,241,434,627,48,627,48,241,434,627 };
std::vector<int>y_coord = { 76,76,76,76,216,216,367,367,367,367 };

cHouse::cHouse() {
	x = 0;
	y = 0;
	w = 120;
	h = 80;
	parked = false;
}
cHouse::~cHouse() {

}
void cHouse::setx(int i) {
	x = x_coord[i];
}
void cHouse::sety(int i) {
	y = y_coord[i];
}
int cHouse::getx() {
	return x;
}
int cHouse::gety() {
	return y;
}
int cHouse::getw() {
	return w;
}
int cHouse::geth() {
	return h;
}
int cHouse::findx_garage() {
	return x + w / 2;
}
int cHouse::findy_garage() {
	return y + h;
}
void cHouse::setname(int i) {
	int j = i + 1;
	name = "house" + std::to_string(j) + ".png";
}
std::string cHouse::getname() {
	return name;
}
void cHouse::setgarage(int i) {
	int j = i + 1;
	garage_name = "housec" + std::to_string(j) + ".png";
}
std::string cHouse::getgarage() {
	return garage_name;
}
void cHouse::setpark(bool _parked) {
	parked = _parked;
}
bool cHouse::getpark() {
	return parked;
}