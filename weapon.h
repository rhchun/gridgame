#ifndef weapon_h
#define weapon_h

#include "posn.h"
#include <string>
using namespace std;

class Weapon {
public:
	string type;
	int damage;
	int durability;
	Posn* location;
	Weapon(string type, int x, int y) {
		this->type = type;
		if (this->type == "sword") {
			this->damage = 20;
			this->durability = 10;
		}
		else if (this->type == "axe") {
			this->damage = 15;
			this->durability = 15;
		}
		else if (this->type == "dagger") {
			this->damage = 10;
			this->durability = 5;
		}
		else {
			this->damage = 100;
			this->durability = 2;
		}
		this->location = new Posn(x, y);
	}
};

#endif