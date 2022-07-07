#ifndef ARMORY_H
#define ARMORY_H

#include <string>
#include <iostream>
#include <array>
#include "ability.h"
#include "shield.h"
#include "potion.h"
#include "player.h"
#include "abilityList.h"
#include "shieldList.h"
#include "potionList.h"
#include "cutsceneList.h"

using namespace std;

class Armory
{
    private:
    Ability* abilities;
    int numAbilities;
    Shield* shields;
    int numShields;
    Potion* potions;
    int numPotions;
    int repairPrice;
    
    public:
    // Constructors / Destructors
    Armory();
    ~Armory();
    Armory(Ability*, int, Shield*, int, Potion*, int, int);

    // Getters
    Ability* getAbilities();
    int getNumAbilities();
    Shield* getShields();
    int getNumShields();
    Potion* getPotions();
    int getNumPotions();
    int getRepairPrice();

    // Setters
    void setAbilities(Ability*);
    void setNumAbilities(int);
    void setNumShields(int);
    void setShields(Shield*);
    void setPotions(Potion*);
    void setNumPotions(int);
    void setRepairPrice(int);

    // Custom Functions
    void generateArmory(Player);
    Ability buyAbility();
    Shield buyShield();
    Potion buyPotion(int);
    Shield* repairShields(Player);
};

#endif