#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "entity.h"
#include "stats.h"
#include "inventory.h"

using namespace std;

class Player: public Entity
{
    private:
    int saveID;
    int experiencePoints;

    public:
    // Constructors / Destructors
    Player();
    ~Player();
    Player(string, Stats, Inventory, int, int);

    // Getters
    int getSaveID();
    int getExperiencePoints();

    // Setters
    void setSaveID(int);
    void setExperiencePoints(int);
};

#endif 