#include "player.h"
#include "posn.h"
using namespace std;

Player::Player(string player_name, int x, int y) {
	this->name = player_name;
	this->exp = 0;
	this->hp = 100;
	this->weapon = NULL;
	this->armor = NULL;
	this->level = 1;
	this->base_damage = 50;
	this->base_armor = 10;
	Posn* p = new Posn(x,y);
	this->location = p;
}

void Player::move(int x, int y) {
	this->location->x = x;
	this->location->y = y;
	if (this->location->x > 10) {
		this->location->x = 10;
	}
	if (this->location->y > 10) {
		this->location->y = 10;
	}
}