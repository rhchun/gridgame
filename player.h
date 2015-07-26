#ifndef player_h
#define player_h

#include "weapon.h"
#include "armor.h"
#include "posn.h"
#include <string>
using namespace std;

class Player {
public:
	string name;
	int exp;
	int hp;
	Weapon* weapon;
	Armor* armor;
	Posn* location;
	int level;
	int base_damage;
	int base_armor;
	void move(int x, int y);
	Player(string name, int x, int y);
};

#endif