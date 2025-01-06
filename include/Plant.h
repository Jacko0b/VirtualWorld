#pragma once
#include "Creature.h"
class Plant : public Creature{
    public:
    Plant(std::pair<int, int> position, World** world)
        : Creature(position,world){
        initiative_ = 0; 
        strength_ = 0;
    }
    void action() override;
    void colision(Creature &other) override;
    void draw() override;
};
