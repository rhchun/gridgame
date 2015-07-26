#ifndef posn_h
#define posn_h


class Posn {
public:
	int x;
	int y;
	Posn(int x, int y) {
		this->x = x;
		this->y = y;
	}
	Posn(){
		x = -1;
		y = -1;
	}
};


#endif