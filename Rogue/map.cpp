#include "map.h"
#include <fstream>
#include <ncurses.h>

Map::Map(){
	std::ifstream in;    // Create an input file stream.
  	in.open("maps/map_1.txt");  // Use it to read from a file named data.txt.
	std::string row;
	while( in ) { 
		std::getline(in,row);   // Try to get another line.
		rows.push_back(row);
	}
}

void Map::draw(){
	int y = 0;
	int x = 0;
	for (auto &row : rows){
		const char* s = row.c_str();
		mvprintw(y, x, s);
		y += 1;
   }
}

char Map::getChar(int x, int y){
	return rows[y][x];
}

