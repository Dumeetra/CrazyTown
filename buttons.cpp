
#include "buttons.h"
#include <iostream>


void cButton::setrun() {
	if (!crash) {
		run = true;
	}
}

bool cButton::getrun() {
	return run;
}
void cButton::setname(std::string _name) {
	name = _name;
}
std::string cButton::getname() {
	return name;
}
void cButton::stop() {
	run = false;
	crash = true;
}

