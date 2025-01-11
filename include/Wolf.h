#pragma once
#include "Animal.h"
class Wolf : public Animal{
    public:
    Wolf(std::pair<int, int> position, Creature*** world)
        : Animal(position,world){
        creatureName_= CreatureName::Wilk;
        strength_=9;
        initiative_=5;
    }

    //boilerplate
    void action() override;
    void colision(Creature &other) override;
    void draw() override;
};
