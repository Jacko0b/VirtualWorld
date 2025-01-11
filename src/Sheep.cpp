#include "Sheep.h"
void Sheep::action(){
    Animal::action();
    std::cout<<"domyslna akcja owcy";
}
void Sheep::colision(Creature &other){
    std::cout<<"domyslna kolizja owcy";
}
void Sheep::draw(){
    std::cout<<"S";
}