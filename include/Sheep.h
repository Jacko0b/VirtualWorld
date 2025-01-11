#pragma once
#include "Animal.h"
class Sheep : public Animal{
    public:
    Sheep(std::pair<int, int> position, Creature*** world)
        : Animal(position,world){
        creatureName_= CreatureName::Owca;
        strength_=4;
        initiative_=4;
    }

    //boilerplate
    void action() override;
    void colision(Creature &other) override;
    void draw() override;

};
