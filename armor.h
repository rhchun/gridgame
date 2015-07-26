#ifndef armor_h
#define armor_h

#include "posn.h"
#include <string>
using namespace std;

class Armor {
public:
	string type;
	int damage_block;
	int durability;
	Posn* location;
	Armor(string type, int x, int y) {
		this->type = type;
		if (this->type == "shield") {
			this->damage_block = 20;
			this->durability = 10;
		}
		else {
			this->damage_block = 10;
			this->durability = 20;
		}
		this->location = new Posn(x, y);
	}
};

#endif