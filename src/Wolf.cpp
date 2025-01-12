#include "Wolf.h"
void Wolf::action(){
    Animal::action();
}
void Wolf::colision(Creature &other){
    std::cout<<"domyslna kolizja wilka";
}
void Wolf::draw(){
    std::cout<<"W";
}