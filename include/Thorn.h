#pragma once
#include "Plant.h"
class Thorn : public Plant{
    public:
    Thorn(std::pair<int, int> position, World** world)
        : Plant(position,world){
        
        strength_=2;
    }
    void action() override;
    
};