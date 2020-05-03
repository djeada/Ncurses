#include <ncurses.h>
#include "player.h"
#include "monster.h"

void screenSetUp();
bool gameLogic(Player* p, std::vector<Monster>& monsters);

int main(){
	Player myPlayer(1,1);
	std::vector<Monster> myMonsters = initalizeMonsters(10, myPlayer.getMap());
	
	screenSetUp();
	
	while(gameLogic(&myPlayer, myMonsters)){
	}

	endwin();

	return 0;
}

void screenSetUp(){
	initscr();
	noecho();
	refresh();
}

bool gameLogic(Player* p, std::vector<Monster>& monsters){
	clear();
	p->getMap().draw(p->getHealth(), p->getLevel(), p->getExp());
	
	for(auto &m : monsters){
		m.draw();
   	}
	
	p->draw();
		
	char ch = getch();		

	if(ch == esc)
		return false;
			
	p->handleInput(ch);
	p->fight(monsters);
	
	for(auto &m : monsters){
		m.moveMonster(p->getMap(), p->getX(), p->getY());
   	}
	
	return true;
}




