#include "utils.h"
#include "monster.h"

Monster::Monster(int _x, int _y, char t){
	x = _x;
	y = _y;
	
	randomizeVelocity();
	
	tile = t;
	
	switch(tile){
     	case GOBLIN: 
			attack = 1;
			health = 1;
			break;
		
		case ORC:
			attack = 3;
			health = 8;
			break;
		
		case TROLL:
			attack = 20;
			health = 30;
			break;
		
		case DRAGON:
			attack = 100;
			health = 1000;
			break;
		
		default:
			attack = 0;
			health = 0;
			break;
	}
}

void Monster::draw(){
	const char *c = &tile;
	mvprintw(y, x, c);
}

void Monster::moveMonster(Map myMap, int playerX, int playerY){
	if(checkNoColisions(myMap, playerX, playerY)){
		x += vx;
		y += vy;
	}
	randomizeVelocity();
}

void Monster::randomizeVelocity(){
	if (headOrTail() > 0){
		vx = 0;
		vy = headOrTail();
	}
	else {
		vx = headOrTail();
		vy = 0;
	}	
}

bool Monster::checkNoColisions(Map myMap, int playerX, int playerY){
	if(myMap.getChar(x+vx, y+vy) == BORDER_TILE ||
	(x+vx == playerX && y+vy == playerY))
		return false;
	return true;
}


char Monster::getTile(){
	return tile;
}

void returnValidPositions(int (&myArray)[2], Map myMap){
	int x = randomFromRange(0, myMap.screenWidth());
	int y = randomFromRange(0, myMap.screenHeight());
	
	while(myMap.getChar(x,y) != BORDER_TILE){
		x = randomFromRange(0, myMap.screenWidth());
		y = randomFromRange(0, myMap.screenHeight());
	}
	
	myArray[0] = x;
	myArray[1] = y;
}

std::vector<Monster> initalizeMonsters(int how_many, Map myMap){
	std::vector<Monster> monsters;
	int pos[2] = {}; 
	
	// 1/2 goblins
	int number_of_goblins = (int)how_many / 2;
	
	for(int i = 0; i < number_of_goblins; i++){
		returnValidPositions(pos, myMap);
		monsters.push_back(Monster(3, 3, GOBLIN));
	}
	
	// 1/3 orcs
	int number_of_orcs = (int)how_many / 3;
	
	for(int i = 0; i < number_of_orcs; i++){
		returnValidPositions(pos, myMap);
		monsters.push_back(Monster(3, 8, ORC));
	}
	
	// 1/6 trolls
	int number_of_trolls = (int)how_many / 6;
	
	for(int i = 0; i < number_of_trolls; i++){
		returnValidPositions(pos, myMap);
		monsters.push_back(Monster(7, 7, TROLL));
	}
	
	return monsters;
}
