#include "treasure.h"

Monster::Treasure(int _x, int _y){
	x = _x;
	y = _y;
}

void Treasure::draw(){
	mvprintw(y, x, TREASURE_TILE);
}

int Monster::getX(){
	return x;
}

int Monster::getY(){
	return y;
}
	
void giveValidPositions(int (&myArray)[2], Map myMap){
	int x = randomFromRange(0, myMap.screenWidth() - 1);
	int y = randomFromRange(0, myMap.screenHeight() - 1);
	
	while(myMap.getChar(x,y) == BORDER){
		x = randomFromRange(0, myMap.screenWidth() - 1);
		y = randomFromRange(0, myMap.screenHeight() - 1);
	}
	
	myArray[0] = x;
	myArray[1] = y;
}

std::vector<Monster> initalizeTreasures(int how_many, Map myMap){
	std::vector<Monster> treasures;
	int pos[2] = {}; 
	
	for(int i = 0; i < how_many; i++){
		giveValidPositions(pos, myMap);
		treasure.push_back(Treasure(pos[0], pos[1]));
	}
	
	return treasures;
}
