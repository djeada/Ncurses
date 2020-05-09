#ifndef treasure_h
#define treasure_h

#include "map.h"

class Treasure {
	private:
		int x;
		int y;
		int bonus_attack;
		int bonus_exp;
		int bonus_health;
	
	public:
		Treasure(int _x, int _y);
		void draw();
		
		int getX();
		int getY();
		int getBonusAttack();
		int getBonusExp();
		int getBonusHealth();
};

std::vector<Treasure> initalizeTreasures(int how_many, Map myMap);

#endif
