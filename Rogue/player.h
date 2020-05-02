#ifndef player_h
#define player_h

#include "monster.h"
#include "map.h"
#include <memory> 

class Player {
	private:
		int x;
		int y;
		int attack;
		int health;
		int exp;
		int level;
		Map myMap;
	public:
		Player();
		Player(int _x, int _y);
		void handleInput(char ch);
		void draw();
		void movePlayer(int dx, int dy);
		bool checkNoColisions(int dx, int dy);
		//void fight();
		//void levelUp();
		
		int getX();
		int getY();
		Map getMap();
};

#endif

