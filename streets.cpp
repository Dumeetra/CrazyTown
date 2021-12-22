#include "streets.h"
#include <string>

void cStreet::setname(std::string _name) {
	name = _name;
}
std::string cStreet::getname() {
	name = "streets.png";
	return name;
}