#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <iostream>
#include "ability.h"
#include "shield.h"
#include "potion.h"

using namespace std;

class Inventory
{
    private:
    Ability* abilities;
    int numAbilities;
    Shield* shields;
    int numShields;
    Potion* potions;
    int numPotions;
    int balance;
    
    public:
    // Constructors / Destructors
    Inventory();
    ~Inventory();
    Inventory(Ability*, int, Shield*, int, Potion*, int, int);

    // Getters
    Ability* getAbilities();
    int getNumAbilities();
    Shield* getShields();
    int getNumShields();
    Potion* getPotions();
    int getNumPotions();
    int getBalance();

    // Setters
    void setAbilities(Ability*);
    void setNumAbilities(int);
    void setShields(Shield*);
    void setNumShields(int);
    void setPotions(Potion*);
    void setNumPotions(int);
    void setBalance(int);
};

#endif