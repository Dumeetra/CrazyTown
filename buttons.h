
#include "texture.h"
#include <string>
class cButton :public cTexture {
public:
	cButton() {
		w = 100;
		h = 40;
		run = false;
		crash = false;
	}
	void setrun();
	bool getrun();
	void setname(std::string);
	std::string getname();
	void stop();
private:
	bool run;
	bool crash;
	int w, h;
	std::string name;
};

