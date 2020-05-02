#include <ncurses.h>
#include "game_settings.h"
#include "player.h"
#include "map.h"

void screenSetUp();
int gameLogic(Player* p);

int main(){
	Player myPlayer(1,1);
	screenSetUp();
	
	while(gameLogic(&myPlayer) != 0){
	}
	
	endwin();

	return 0;
}

void screenSetUp(){
	initscr();
	noecho();
	refresh();
}

int gameLogic(Player* p){
	clear();
	p->getMap().draw();
	p->draw();
		
	char ch = getch();		

	if(ch == esc)
		return 0;
			
	p->handleInput(ch);
	
	return 1;
}



