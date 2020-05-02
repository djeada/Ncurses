#include <ncurses.h>
#include <stdio.h>
#include "player.h"

Player::Player(){
	x = 1;
	y = 1;
	
	attack = 1;
	health = 10;
	
	level = 0;
	exp = 0;
}

Player::Player(int _x, int _y){
	x = _x;
	y = _y;
	
	attack = 1;
	health = 10;
	
	level = 0;
	exp = 0;
}

void Player::draw(){
	mvprintw(y, x, PLAYER_TILE);
	move(y, x);
}

void Player::movePlayer(int dx, int dy){
	if(checkNoColisions(dx, dy)){
		x += dx;
		y += dy;
	}
}

bool Player::checkNoColisions(int dx, int dy){
	if(myMap.getChar(x+dx, y+dy) == BORDER_TILE)
		return false;
	return true;
}

void Player::handleInput(char input){
	printf("Input: %c \n", input);
	switch(input){
     	case 'w': case 'W':
			movePlayer(0, -1);
			break;
		
		case 'a': case 'A':
			movePlayer(-1, 0);
			break;
		
		case 's': case 'S':
			movePlayer(0, 1);
			break;
		
		case 'd': case 'D':
			movePlayer(1, 0);
			break;
		
		default:
			printf("Default \n");
			break;
	}
}

int Player::getX(){
	return x;
}

int Player::getY(){
	return y;
}

Map Player::getMap(){
	return myMap;
}




