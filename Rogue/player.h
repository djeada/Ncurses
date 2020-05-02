#ifndef player_h
#define player_h

#include "monster.h"

class Player {
	private:
		int x;
		int y;
		int attack;
		int health;
		int exp;
		int level;
		
	public:
		Player();
		Player(int _x, int _y);
		void handleInput(char ch);
		void draw();
		void movePlayer(int vx, int vy);
		//void checkColisions();
		//void fight();
		//void levelUp();
		
		int getX();
		int getY();
};

#endif

