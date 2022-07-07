#ifndef ARENA_H
#define ARENA_H

#include <string>
#include <iostream>
#include "player.h"
#include "enemy.h"
#include "abilityList.h"
#include "shieldList.h"
#include "potionList.h"
#include "cutsceneList.h"

using namespace std;

class Arena
{
    private:
    Player fightingPlayer;
    Enemy enemy;
    int turnNumber;

    // Private Functions
    Ability* decideAbilities(int);
    Shield* decideShields(int);
    double isEffective(Ability, Shield);
    
    public:
    // Constructors / Destructors
    Arena();
    ~Arena();
    Arena(Player, Enemy, int);

    // Getters
    Player getFightingPlayer();
    Enemy getEnemy();
    int getTurnNumber();

    // Setters
    void setFightingPlayer(Player);
    void setEnemy(Enemy);
    void setTurnNumber(int);

    // Custom Functions
    void generateEnemy();
    Enemy generateEnemy(string, int);
    bool iterateTurns();
    bool endBattleResults();
    Player leaveArena();
};

#endif