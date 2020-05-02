#ifndef monster_h
#define monster_h

#include <ncurses.h>
#include "game_settings.h"
#include "utils.h"
#include "map.h"

class Monster {
	private:
		int x;
		int y;
		int vx;
		int vy;
		int attack;
		int health;
		char tile;
	
	public:
		Monster(int _x, int _y, char t);
		void draw();
		void moveMonster(Map myMap, int playerX, int playerY);
		bool checkNoColisions(Map myMap, int playerX, int playerY);
		void randomizeVelocity();
		void setVx(int a);
		void setVy(int a);
		int getX();
		int getY();
		char getTile();
};

std::vector<Monster> initalizeMonsters(int how_many, Map myMap);

#endif
