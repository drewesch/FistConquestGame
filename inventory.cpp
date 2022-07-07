#include "inventory.h"

// Constructors / Destructors
Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

Inventory::Inventory(Ability* abilities, int numAbilities, Shield* shields, int numShields, Potion* potions, int numPotions, int balance)
{
    this->abilities = abilities;
    this->numAbilities = numAbilities;    
    this->shields = shields;
    this->numShields = numShields;
    this->potions = potions;
    this->numPotions = numPotions;
    this->balance = balance;
}

// Getters
Ability* Inventory::getAbilities()
{
    return abilities;
}

int Inventory::getNumAbilities()
{
    return numAbilities;
}

Shield* Inventory::getShields()
{
    return shields;
}

int Inventory::getNumShields()
{
    return numShields;
}

Potion* Inventory::getPotions()
{
    return potions;
}

int Inventory::getNumPotions()
{
    return numPotions;
}

int Inventory::getBalance()
{
    return balance;
}

// Setters
void Inventory::setAbilities(Ability* abilities)
{
    this->abilities = abilities;
}

void Inventory::setNumAbilities(int numAbilities)
{
    this->numAbilities = numAbilities;
}

void Inventory::setShields(Shield* shields)
{
    this->shields = shields;
}

void Inventory::setNumShields(int numShields)
{
    this->numShields = numShields;
}

void Inventory::setPotions(Potion* potions)
{
    this->potions = potions;
}

void Inventory::setNumPotions(int numPotions)
{
    this->numPotions = numPotions;
}

void Inventory::setBalance(int balance)
{
    this->balance = balance;
}