#include <random>

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
