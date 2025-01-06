#pragma once
#include "Plant.h"
class Guarana : public Plant{
    public:
    Guarana(std::pair<int, int> position, World** world)
        : Plant(position,world){
    }
    void colision(Creature &other) override;
};