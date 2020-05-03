#ifndef treasure_h
#define treasure_h

#include "map.h"

class Treasure {
	private:
		int x;
		int y;
	
	public:
		Treasure(int _x, int _y);
		void draw();
		
		int getX();
		int getY();
};

std::vector<Treasure> initalizeTreasures(int how_many, Map myMap);

#endif
