#ifndef map_h
#define map_h

#include <vector>
#include <string>

class Map {
	private:
		std::vector<std::string> rows;
	
	public:
		Map();
		void draw();
		char getChar(int x, int y);
};


#endif
