#include <SDL.h>
#include <SDL_image.h>
#include<cmath>
#include<vector>
#include<string>
#include <stdlib.h>
#include<cstdlib>
#include "texture.h"

class cHouse : public cTexture {
	
public:
	cHouse();
	~cHouse();
	void setx(int);
	void sety(int);
	int findx_garage();
	int findy_garage();
	void setname(int);
	std::string getname();
	void setgarage(int);
	std::string getgarage();
	int getx();
	int gety();
	int getw();
	int geth();
	void setpark(bool);
	bool getpark();
private:
	int x, y, w, h;
	std::string name;
	std::string garage_name;
	bool parked;
};
