#include <iostream>
#include <stdlib.h>
#include "board.h"
#include <string>
using namespace std;

int main () {
	Board* b;
	while (true) {
		string line;
		cin >> line;
		if (line == "s") {
			b = new Board();
		}
		else if (line == "c") {
			string name;
			cin >> name;
			b->create_player(name);
		}
		else if (line == "m") {
			string name;
			int x;
			int y;
			cin >> name;
			cin >> x;
			cin >> y;
			b->move(name, x, y);
		}
		else if (line == "i") {
			b->info_print();
		}
		else if (line == "x") {
			break;
		}
		else {
			cout << "Invalid command" << endl;
		}
	}
}