#pragma once
#include <cstdlib>
#include "Creature.h"
class Animal : public Creature{
    public:
    Animal(std::pair<int, int> position, Creature*** world)
        : Creature(position,world){
    }

    void action() override;
    void colision(Creature &other) override;
    
    virtual bool isOlder(Creature &other){
        return this->instanceNumber_<other.getInstanceNumber();
    }

    private:
    std::pair<int,int> newPosition();
};
