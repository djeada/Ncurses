#include "game_settings.h"
#include "map.h"

class Monster {
	private:
		int x;
		int y;
		int vx;
		int vy;
		int attack;
		int health;
		int level;
		char tile;
		Map myMap;
	
	public:
		Monster();
		void move();
		void checkColisions();
		
		void setVx(int a);
		void setVy(int a);
		int getX();
		int getY();
};
