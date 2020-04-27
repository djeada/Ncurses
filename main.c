#include <ncurses.h>
#include <stdlib.h>

int screenSetUp();
void mapSetUp();

typedef struct Player {
	int xPosition;
	int yPosition;
	int health;
}Player;

Player* playerSetUp();

int main(){
	Player *user;

	user = playerSetUp();

	screenSetUp();

	mapSetUp();
	
	getch();
	endwin();

	return 0;
}

int screenSetUp(){
	initscr();
	printw("Hsello world!");
	noecho();

	refresh();
	
	return 0;
}

void mapSetUp(){
	int y = 0;
	int x = 40;
	mvprintw(y, x, "-------");
	mvprintw(y+1, x, "|-----|");
	mvprintw(y+2, x, "-------");
	
}

Player* playerSetUp(){
	Player* newPlayer;
	newPlayer = malloc(sizeof(Player));
	
	newPlayer->xPosition = 20;
	newPlayer->yPosition = 1;
	newPlayer->health = 20;
	mvprintw(newPlayer->yPosition, newPlayer->xPosition, "@");
	
	return newPlayer;
}
