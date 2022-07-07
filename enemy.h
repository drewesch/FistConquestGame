#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "entity.h"
#include "potion.h"
#include "stats.h"
#include "inventory.h"

using namespace std;

class Enemy: public Entity
{
    private:
    int experienceReward;

    public:
    // Constructors / Destructors
    Enemy();
    ~Enemy();
    Enemy(string, Stats, Inventory, int);

    // Getters
    int getExperienceReward();

    // Setters
    void setExperienceReward(int);
};

#endif 