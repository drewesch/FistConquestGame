#include "bossArena.h"

// Constructors / Destructors
BossArena::BossArena()
{
}

BossArena::~BossArena()
{
}

BossArena::BossArena(Player fightingPlayer, Enemy enemy, int turnNumber, string bossName, Enemy* enemies, int numEnemies)
{
    setFightingPlayer(fightingPlayer);
    setEnemy(enemy);
    setTurnNumber(turnNumber);
    this->bossName = bossName;
    this->enemies = enemies;
    this->numEnemies = numEnemies;
}

// Getters
string BossArena::getBossName()
{
    return bossName;
}

Enemy* BossArena::getEnemies()
{
    return enemies;
}

int BossArena::getNumEnemies()
{
    return numEnemies;
}

// Setters
void BossArena::setBossName(string bossName)
{
    this->bossName = bossName;
}

void BossArena::setEnemies(Enemy* enemies)
{
    this->enemies = enemies;
}

void BossArena::setNumEnemies(int numEnemies)
{
    this->numEnemies = numEnemies;
}