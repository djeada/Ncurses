#include "game_settings.h"

class Monster {
		int x;
		int y;
		int vx;
		int vy;
		int health;
		int level;
		
	public:
		//tutaj dac enuma typy potworow
		Monster();
		void move();
		void checkColisions();
		
		void setVx(int a);
		void setVy(int a);
		int getX();
		int getY();
};
