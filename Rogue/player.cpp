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
	
	//mvprintw(1, 1, "@");
	//move(1, 1);
}

Player::Player(int _x, int _y){
	x = _x;
	y = _y;
	
	attack = 1;
	health = 10;
	
	level = 0;
	exp = 0;
	
	//mvprintw(y, x, "@");
	//move(y, x);
}

void Player::draw(){
	mvprintw(y, x, "@");
	move(y, x);
}

void Player::movePlayer(int vx=0, int vy=0){
	x += vx;
	y += vy;
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

