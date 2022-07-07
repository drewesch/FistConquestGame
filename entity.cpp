#include "entity.h"

// Constructors / Destructors
Entity::Entity()
{
}

Entity::~Entity()
{
}

Entity::Entity(string name, Stats stats, Inventory inventory)
{
    this->name = name;
    this->stats = stats;
    this->inventory = inventory;
}

// Getters
string Entity::getName()
{
    return name;
}

Stats Entity::getStats()
{
    return stats;
}

Inventory Entity::getInventory()
{
    return inventory;
}

// Setters
void Entity::setName(string name)
{
    this->name = name;
}

void Entity::setStats(Stats stats)
{
    this->stats = stats;
}

void Entity::setInventory(Inventory inventory)
{
    this->inventory = inventory;
}