#ifndef board_h
#define board_h

#include "player.h"
#include "weapon.h"
#include "armor.h"
#include "posn.h"
#include <string>
using namespace std;

class Board {
public:
	Player** players;
	Weapon** weapons;
	Armor** armors;
	int numplayers;
	int numweapons;
	int numarmors;
	char board[9][9];
	Board();
	void info_print();
	void create_player(string name);
	void fight(int x, int y);
	void move(string player_name, int x, int y);
};

#endif