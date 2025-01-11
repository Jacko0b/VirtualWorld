#include "Animal.h"

std::pair<int,int> Animal::newPosition(){
    int x = getX();
    int y = getY();

    std::pair<int,int> directions[8] = {
        std::make_pair(-1, -1),
        std::make_pair(0,  -1),
        std::make_pair(1,  -1),
        std::make_pair(-1,  0),
        std::make_pair(1,   0),
        std::make_pair(-1,  1),
        std::make_pair(0,   1),
        std::make_pair(1,   1)
    };

    int newX =0;
    int newY =0;
    int randomIndex=0;
    do
    {
        randomIndex = std::rand() % 8;
        std::pair<int,int> direction = directions[randomIndex];
        newX = x + direction.first;
        newY = y + direction.second;
    } while (newX < 0 || newX >= 20 || newY < 0 || newY >= 20);

    return std::make_pair(newX, newY);
}
void Animal::action(){
    
    std::pair newPos = newPosition();
    if(world_[newPos.first][newPos.second] == nullptr) {
        world_[getX()][getY()] = nullptr;
        setPosition(newPos);
        world_[newPos.first][newPos.second] = this;
        std::cout<<"mojapozycja:"<<newPos.first<<", "<<newPos.second<<std::endl;
    }
    else{
        colision(*world_[newPos.first][newPos.second]);
    }
}
void Animal::colision(Creature &other){
    std::cout<<"domyslna kolizja zwierzaka";
}