
#include "texture.h"
#include <string>
class cButton :public cTexture {
public:
	cButton() :w(100), h(40), run(false){};
	void setrun(bool);
	bool getrun();
	void setname(std::string);
	std::string getname();
private:
	bool run;
	int w, h;
	std::string name;
};

