#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>
#include "stats.h"
#include "inventory.h"

using namespace std;

class Entity
{
    private:
    string name;
    Stats stats;
    Inventory inventory;
    
    public:
    // Constructors / Destructors
    Entity();
    ~Entity();
    Entity(string, Stats, Inventory);

    // Getters
    string getName();
    Stats getStats();
    Inventory getInventory();

    // Setters
    void setName(string);
    void setStats(Stats);
    void setInventory(Inventory);
};

#endif