#include "Wolf.h"
void Wolf::action(){
    Animal::action();
    std::cout<<"\ndomyslna akcja wilka z pozycji x:"<<getX()<<" ,y:"<<getY()<<std::endl;
}
void Wolf::colision(Creature &other){
    std::cout<<"domyslna kolizja wilka";
}
void Wolf::draw(){
    std::cout<<"W";
}