#include "board.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

Board::Board () {
	srand(time(NULL));
	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 10; i++) {
			board[i][j] = 'N';
		}
	}
	players = new Player*[15];
	weapons = new Weapon*[15];
	armors = new Armor*[15];
	

	int x = rand()%10;
	int y = rand()%10;
	int i = 0;
	while ( i < 5 ){
		while (board[x][y]!='N') {
			x = rand()%10;
			y = rand()%10;
		}
		Weapon* weapon;
		if ( i == 0 ){
			weapon= new Weapon("gun", x, y);
		}
		else if ( i == 1 || i == 2 ){
			weapon= new Weapon("dagger", x, y);
		}
		else if ( i == 3 ){
			weapon= new Weapon("axe", x, y);
		}
		else if ( i == 4 ){
			weapon= new Weapon("sword", x, y);
		}
		board[x][y] = 'W';
		weapons[numweapons] = weapon;
		numweapons++;
		i++;
	}
	i = 0;
	while ( i < 5 ){
		while (board[x][y]!='N') {
			x = rand()%10;
			y = rand()%10;
		}
		Armor* armor;
		if ( i == 1 || i == 2 || i == 3){
			armor= new Armor("helmet", x, y);
		}
		else {
			armor= new Armor("shield", x, y);
		}
		board[x][y] = 'A';
		armors[numarmors] = armor;
		numarmors++;
		i++;
	}
	cout << "Game has started" << endl;
}

void Board::info_print() {
	for (int i = 0; i < numplayers; i++) {
		if (players[i]->name != ""){
			cout << players[i]->name << " " << players[i]->location->x << " " << players[i]->location->y << endl;
			cout << "level: " << players[i]->level << endl;
		}
	}
	cout << "------------------------------------------" << endl;
	for (int i = 0; i < numweapons; i++) {
		cout << weapons[i]->type << " " << weapons[i]->location->x << " " << weapons[i]->location->y << endl;
	}
	cout << "------------------------------------------" << endl;
	for (int i = 0; i < numarmors; i++) {
		cout << armors[i]->type << " " << armors[i]->location->x << " " << armors[i]->location->y << endl;
	}
}

void Board::create_player(string name) {
	int x = rand()%10;
	int y = rand()%10;
	while (board[x][y]!='N') {
		x = rand()%10;
		y = rand()%10;
	}
	board[x][y] = 'P';
	players[numplayers] = new Player(name, x, y);
	numplayers++;
}

void Board::fight(int x, int y) {
	int p1 = -1;
	int p2 = -1;
	for(int i = 0; i < numplayers; i++) {
		if (players[i]->location->x == x && players[i]->location->y == y) {
			if(p1 == -1) {
				p1 = i;
			}
			else {
				p2 = i;
			}
		}
	}
	cout << players[p1]->name << " is fighting " << players[p2]->name << endl;
	while (players[p1]->hp > 0 && players[p2]->hp > 0) {
		int p1_damage = players[p1]->base_damage;
		if (players[p1]->weapon != NULL && players[p1]->weapon->durability > 0) {
			p1_damage += players[p1]->weapon->damage;
			players[p1]->weapon->durability -= 1;
		}
		if (players[p2]->armor != NULL && players[p2]->armor->durability > 0) {
			p1_damage -= players[p2]->armor->damage_block;
			players[p2]->armor->durability -= 1;
		}
		int p2_damage = players[p2]->base_damage;
		if (players[p2]->weapon != NULL && players[p2]->weapon->durability > 0) {
			p2_damage += players[p2]->weapon->damage;
			players[p2]->weapon->durability -= 1;
		}
		if (players[p1]->armor != NULL && players[p1]->armor->durability > 0) {
			p2_damage -= players[p1]->armor->damage_block;
			players[p1]->armor->durability -= 1;
		}
		players[p1]->hp -= p2_damage;
		players[p2]->hp -= p1_damage;
		cout << players[p1]->name << " does " << p1_damage << " damage!" << endl;
		cout << players[p2]->name << " does " << p2_damage << " damage!" << endl;
		if (players[p1]->hp > 0) {
			cout << players[p1]->name << " has " << players[p1]->hp << " hp remaining" << endl;
		}
		else {
			cout << players[p1]->name << " has 0 hp remaining" << endl;
		}
		if (players[p2]->hp > 0) {
			cout << players[p2]->name << " has " << players[p2]->hp << " hp remaining" << endl;
		}
		else {
			cout << players[p2]->name << " has 0 hp remaining" << endl;
		}
	}
	if (players[p1]->hp <= 0 && players[p2]->hp <= 0) {
		players[p1]->name = "";
		players[p2]->name = "";
		board[x][y] = 'N';
		cout << "Both players died!" << endl;
	}
	else if (players[p1]->hp < 0) {
		players[p1]->name = "";
		players[p2]->exp += 15*players[p1]->level;
		players[p2]->hp = 100;
		if (players[p2]->exp >= 15) {
			players[p2]->level += 1;
			players[p2]->exp = 0;
			players[p2]->base_damage += 10;
			players[p2]->base_armor+= 10;
			players[p2]->hp += (players[p2]->level)*10;
		}
		cout << players[p2]->name << " is victorious" << endl;
	}
	else {
		players[p2]->name = "";
		players[p1]->exp += 15*players[p2]->level;
		players[p1]->hp = 100;
		if (players[p1]->exp >= 15) {
			players[p1]->level += 1;
			players[p1]->exp = 0;
			players[p1]->base_damage += 10;
			players[p1]->base_armor+= 10;
			players[p1]->hp += (players[p1]->level)*10;
		}
		cout << players[p1]->name << " is victorious" << endl;
	}
}

void Board::move (string player_name, int x, int y) {
	for(int i = 0; i < numplayers; i++) {
		if (player_name == players[i]->name) {
			board[players[i]->location->x][(players[i]->location)->y] = 'N';
			players[i]->move(x, y);
			if (board[x][y] == 'W') {
				for (int j = 0; j < numweapons; j++) {
					if (weapons[j]->location->x == x && weapons[j]->location->y == y) {
						players[i]->weapon= weapons[j];
						weapons[j]->location= new Posn(-1,-1);
						cout << players[i]->name << " picked up " << weapons[j]->type << endl;
						cout << players[i]->name << " has moved to " << players[i]->location->x << "," << players[i]->location->y << endl;
						return;
					}
				} 
				board[(players[i]->location)->x][(players[i]->location)->y] = 'P';
			}
			else if (board[x][y] == 'A') {
				for (int j = 0; j < numarmors; j++) {
					if (armors[j]->location->x == x && armors[j]->location->y == y) {
						players[i]->armor= armors[j];
						armors[j]->location= new Posn(-1,-1);
						cout << players[i]->name << " picked up " << armors[j]->type << endl;
						cout << players[i]->name << " has moved to " << players[i]->location->x << "," << players[i]->location->y << endl;
						return;
					}
				}
				board[(players[i]->location)->x][(players[i]->location)->y] = 'P';
			}
			else if (board[x][y] == 'N') {
				cout << players[i]->name << " has moved to " << players[i]->location->x << "," << players[i]->location->y << endl;
				return;
			}
			else {
				fight(x, y);
				return;
			}
		}
	}
	cout << "player not found" << endl;
}
