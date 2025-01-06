#pragma once
#include "Plant.h"
class Grass : public Plant{
    public:
    Grass(std::pair<int, int> position, World** world)
        : Plant(position,world){
    }
};