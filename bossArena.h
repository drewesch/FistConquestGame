#ifndef BOSSARENA_H
#define BOSSARENA_H

#include <string>
#include <iostream>
#include "arena.h"

using namespace std;

class BossArena: public Arena
{
    private:
    string bossName;
    Enemy* enemies;
    int numEnemies;
    
    public:
    // Constructors / Destructors
    BossArena();
    ~BossArena();
    BossArena(Player, Enemy, int, string, Enemy*, int);

    // Getters
    string getBossName();
    Enemy* getEnemies();
    int getNumEnemies();

    // Setters
    void setBossName(string);
    void setEnemies(Enemy*);
    void setNumEnemies(int);
};

#endif