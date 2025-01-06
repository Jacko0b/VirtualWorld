#include "Animal.h"

void Animal::action(){
    std::cout<<"domyslna akcja zwierzaka";
}
void Animal::colision(Creature &other){
    std::cout<<"domyslna kolizja zwierzaka";
}
void Animal::draw(){
    std::cout<<"domyslne wypisanie zwierzaka";
}