#pragma once
#include "Creature.h"
class Plant : public Creature{
    Plant(std::pair<int, int> position, World** world)
        : Creature(position,world){
        initiative_ = 0; 
        strength_ = 0;
    }
    virtual bool isOlder(Creature &other) const=0;
};
