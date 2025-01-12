#include "Sheep.h"
void Sheep::action(){
    Animal::action();
}
void Sheep::colision(Creature &other){
    std::cout<<"domyslna kolizja owcy";
}
void Sheep::draw(){
    std::cout<<"S";
}