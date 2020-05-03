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
	switch(tile){
     	case GOBLIN: 
			mvprintw(y, x, GOBLIN_TILE);
			break;
		
		case ORC:
			mvprintw(y, x, ORC_TILE);
			break;
		
		case TROLL:
			mvprintw(y, x, TROLL_TILE);
			break;
		
		case DRAGON:
			mvprintw(y, x, DRAGON_TILE);
			break;
		
		default:
			break;
	}
}

void Monster::moveMonster(Map myMap, int playerX, int playerY){
	if(checkNoColisions(myMap, playerX, playerY)){
		x += vx;
		y += vy;
	}
	randomizeVelocity();
}

bool Monster::checkNoColisions(Map myMap, int playerX, int playerY){
	if(myMap.getChar(x+vx, y+vy) == BORDER ||
		(x+vx == playerX && y+vy == playerY) ||
		x + vx > myMap.screenWidth() - 1)
		return false;
	return true;
}


int Monster::getX(){
	return x;
}

int Monster::getY(){
	return y;
}
	
int Monster::getAttack(){
	return attack;
}	
		
int Monster::getHealth(){
	return health;
}

char Monster::getTile(){
	return tile;
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

void Monster::setHealth(int a){
	health = a;
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

std::vector<Monster> initalizeMonsters(int how_many, Map myMap){
	std::vector<Monster> monsters;
	int pos[2] = {}; 
	
	// 1/2 goblins
	int number_of_goblins = (int)how_many / 2;
	
	for(int i = 0; i < number_of_goblins; i++){
		giveValidPositions(pos, myMap);
		monsters.push_back(Monster(pos[0], pos[1], GOBLIN));
	}
	
	// 1/3 orcs
	int number_of_orcs = (int)how_many / 3;
	
	for(int i = 0; i < number_of_orcs; i++){
		giveValidPositions(pos, myMap);
		monsters.push_back(Monster(pos[0], pos[1], ORC));
	}
	
	// 1/6 trolls
	int number_of_trolls = (int)how_many / 6;
	
	for(int i = 0; i < number_of_trolls; i++){
		giveValidPositions(pos, myMap);
		monsters.push_back(Monster(pos[0], pos[1], TROLL));
	}
	
	//rest dragons
	int number_of_dragons = 0;
	
	while(number_of_goblins + number_of_orcs + number_of_trolls
		+ number_of_dragons < how_many){
		
		giveValidPositions(pos, myMap);
		monsters.push_back(Monster(pos[0], pos[1], DRAGON));
		number_of_dragons++;	
	}
	
	return monsters;
}
