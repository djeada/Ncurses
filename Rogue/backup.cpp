#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include "game_settings.h"
#include "player.h"

using namespace std;

void screenSetUp();
void mapSetUp();

typedef struct Player {
	int xPosition;
	int yPosition;
	int health;
}Player;

int handleInput(char input, Player* user);
void playerMove(int x, int y, Player* user);

Player* playerSetUp();

int main(){
	Player *user;
	char ch;
	screenSetUp();

	mapSetUp();
	user = playerSetUp();
	
	while(1){
		ch = getch();
		
		if (handleInput(ch, user) == 0)
			break;
	}
	endwin();

	return 0;
}

void screenSetUp(){
	initscr();
	/*
	printw("Hsello world!");
	*/
	noecho();
	refresh();
}

void mapSetUp(){
	int y = 0;
	int x = 0;
	ifstream in;    // Create an input file stream.
  	in.open("map_1.txt");  // Use it to read from a file named data.txt.
	string str;
	printf("hej");
	while ( in ) {  
		getline(in,str);   // Try to get another line.
		const char* s = str.c_str();
		mvprintw(y, x, s);
		y += 1;
   }
}

Player* playerSetUp(){
	Player* newPlayer;
	newPlayer = (Player *)malloc(sizeof(Player));
	newPlayer->xPosition = 42;
	newPlayer->yPosition = 1;
	newPlayer->health = 20;
	playerMove(42, 1, newPlayer);
	
	return newPlayer;
}

int handleInput(char input, Player *user){
	switch(input){
		case esc:
			endwin();
			return 0;

     	case 'w': case 'W':
			playerMove(user->xPosition, user->yPosition - 1, user);
			break;
		case 'a': case 'A':
			playerMove(user->xPosition - 1, user->yPosition, user);
			break;
		case 's': case 'S':
			playerMove(user->xPosition, user->yPosition + 1, user);
			break;
		case 'd': case 'D':
			playerMove(user->xPosition + 1, user->yPosition, user);
			break;
		default:
			break;
	}
	return 1;
}

void playerMove(int x, int y, Player* user){
	mvprintw(user->yPosition, user->xPosition, ".");
	
	user->yPosition = y;
	user->xPosition = x;
	
	mvprintw(user->yPosition, user->xPosition, "@");
	move(user->yPosition, user->xPosition);
}

