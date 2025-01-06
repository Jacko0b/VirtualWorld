#pragma once
#include "Creature.h"
class Animal : public Creature{
    Animal(std::pair<int, int> position, World** world)
        : Creature(position,world){
    }

    void action() override;
    void colision(Creature &other) override;
    void draw() override;
    
    virtual bool isOlder(Creature &other){
        return this->instanceNumber_<other.getInstanceNumber();
    }

};
