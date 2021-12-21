#ifndef STREETS_H
#define STREETS_H
#include "texture.h"

class cStreet:public cTexture {
public:
	cStreet():w(792),h(463),x(0),y(0) {}
	void setname(std::string);
	std::string getname();

private:
	int x, y, w, h;
	std::string name;
	};
#endif