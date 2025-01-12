#include <cstdlib>
#include "World.h"
#include "Creature.h"

World::World()
{
    map_ = new Creature** [20]; 
    for(int i =0; i<20; i++){
        map_[i] = new Creature*[20];
        for(int j=0; j<20; j++) {
            map_[i][j] = nullptr;
        }
    }
    turn_=0;
}
World::~World()
{
    for(int i =0; i<20; i++){
        for(int j=0; j<20; j++) {
            delete map_[i][j];  
        }
       delete[] map_[i];
    }
    delete[] map_;
}    
void World::addCreature(Creature *c){
    map_[c->getX()][c->getY()]=c;
}
void World::deleteCreature(int x, int y){
    delete map_[x][y];
    map_[x][y]=nullptr;
}
Creature* World::getCreature(int x, int y){
    return map_[x][y];
}
bool World::compareCreatures(Creature* a, Creature* b) {
        return a->getInitiative() > b->getInitiative(); 
    }
void World::drawWorld(){
    // Sekwencja ANSI: \033[2J - wyczyść ekran, \033[H - przenieś kursor na początek
    system("clear");
    std::cout << "=== Author: Jakub Sobota 200816 ===\n";
    std::cout << "=== WORLD MAP 20x20 tura:"<<turn_++<<"===\n";
    for(int x = 0; x < 20; x++) {
        for(int y = 0; y < 20; y++) {
            Creature* creature = map_[x][y];
            if(creature != nullptr) {
                creature->draw();
            } else {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "=======================\n";
}