#include <random>
#include "utils.h"
#include "game_settings.h"

int randomFromRange(int start, int end){
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_real_distribution<> dist(start,end);
    return dist(gen);
}

int headOrTail(){
    if(randomFromRange(-10001, 10000) >= 1){
        return 1;
    }
    return -1;
}

void giveValidPositions(int (&myArray)[2], Map myMap){
	int x = randomFromRange(0, myMap.screenWidth() - 1);
	int y = randomFromRange(0, myMap.screenHeight() - 1);
	
	while(myMap.getChar(x,y) == BORDER){
		x = randomFromRange(0, myMap.screenWidth() - 1);
		y = randomFromRange(0, myMap.screenHeight() - 1);
	}
	
	myArray[0] = x;
	myArray[1] = y;
}
