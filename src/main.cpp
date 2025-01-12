#include "World.h"
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
int main() {    
    std::srand(std::time(nullptr));
    World* world = new World();
    world->addCreature(new Sheep(std::make_pair(19,19),world->getMap())); 
    world->addCreature(new Wolf(std::make_pair(1,1),world->getMap())); 
    world->drawWorld();
    std::vector<Creature*> creatures;
    for(int i=0;i<50;i++){
        for (int x = 0; x < 20; x++) {
            for (int y = 0; y < 20; y++) {
                Creature* c = world->getMap()[x][y];
                if (c != nullptr) {
                    creatures.push_back(c);
                }
            }
        }

        std::sort(creatures.begin(), creatures.end(), World::compareCreatures);

        for (Creature* c : creatures) {
            c->action();
        }
        creatures.clear();
        world->drawWorld();
        sleep(1);
    }
    delete world;
    return 0;
}