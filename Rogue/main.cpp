#include <ncurses.h>
#include <fstream>
#include <stdlib.h>
#include "game_settings.h"
#include "player.h"

void screenSetUp();
void mapSetUp();
int gameLogic(Player* p);
//int handleInput(char input, Player* p);

int main(){
	//Player* myPlayer = NULL;

	Player myPlayer(1,1);
	screenSetUp();
	
	while(gameLogic(&myPlayer) != 0){
		
		
		//if (handleInput(ch, myPlayer) == 0)
		//	break;
	}
	endwin();
	
	//delete myPlayer;

	return 0;
}

void screenSetUp(){
	initscr();
	noecho();
	refresh();
}

void mapSetUp(){
	int y = 0;
	int x = 0;
	std::ifstream in;    // Create an input file stream.
  	in.open("map_1.txt");  // Use it to read from a file named data.txt.
	std::string str;
	while ( in ) {  
		std::getline(in,str);   // Try to get another line.
		const char* s = str.c_str();
		mvprintw(y, x, s);
		y += 1;
   }
}

int gameLogic(Player* p){
	clear();
	mapSetUp();
	p->draw();
		
	char ch = getch();		

	if(ch == esc)
		return 0;
			
	p->handleInput(ch);
	return 1;
}



