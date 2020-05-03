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
		void increaseExp(char tile);
		
	public:
		Player();
		Player(int _x, int _y);
		void draw();
		void handleInput(char ch);
		void movePlayer(int dx, int dy);
		bool checkNoColisions(int dx, int dy);
		void fight(std::vector<Monster>& monsters);
		bool levelUp();
		
		int getX();
		int getY();
		int getHealth();
		int getExp();
		int getLevel();
		
		Map getMap();
};

#endif

