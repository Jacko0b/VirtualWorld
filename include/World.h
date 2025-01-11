#pragma once 
#include <iostream>  
#include "Creature.h"
#include "Wolf.h"
#include "Sheep.h"
class World {
    public:
        World();
        ~World();
        void addCreature(Creature *c);
        void deleteCreature(int x, int y);
        Creature *getCreature(int x, int y);
        void makeTurn();
        void drawWorld();
        Creature *** getMap(){
            return map_;
        }
        static bool compareCreatures(Creature* a, Creature* b);
    private:
        int turn_;
        Creature*** map_ = nullptr;
};