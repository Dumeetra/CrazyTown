
#include "buttons.h"
#include <iostream>


void cButton::setrun(bool _run) {

		run = _run;
		//std::cout << "run";
}

bool cButton::getrun() {//determines if the cars should keep moving or not
	return run;
}
void cButton::setname(std::string _name) {
	name = _name;
}
std::string cButton::getname() {
	return name;
}
