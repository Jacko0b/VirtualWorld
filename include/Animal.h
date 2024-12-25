#pragma once
#include "Creature.h"
class Animal : public Creature{

    virtual bool isOlder(Creature &other) const=0;
};
