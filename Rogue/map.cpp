#include "map.h"
#include <fstream>
#include <sstream>
#include <ncurses.h>

Map::Map(){
	std::ifstream in;
  	in.open("maps/map_1.txt");
	std::string row;
	while(in) { 
		std::getline(in,row);
		rows.push_back(row);
	}
}

std::string intToStr(int value){
    std::stringstream ss;
    ss << value;
    return ss.str();
}

void displayPlayerInfo(int y, int health, int level, int exp){
	int x = 0;
	
	std::string message = "";
	
	if(health > 0) {
		message = "Health: " + intToStr(health) +
			"/" + intToStr((level + 1)*10) +
			" Level: " + intToStr(level) + 
			" Exp: " + intToStr(exp);
	

	}
	else {
		message = "You died!";
	}
	
	char const *pchar = message.c_str();

	mvprintw(y, x, pchar);
}

void Map::draw(int health, int level, int exp){
	int y = 0;
	int x = 0;
	for(auto &row : rows){
		const char* s = row.c_str();
		mvprintw(y, x, s);
		y += 1;
   }
   displayPlayerInfo(y, health, level, exp);
}

char Map::getChar(int x, int y){
	return rows[y][x];
}

int Map::screenWidth(){
	return rows[0].size();
}

int Map::screenHeight(){
	return rows.size();
}

