#include "stats.h"

// Constructors / Destructors
Stats::Stats()
{
}

Stats::~Stats()
{
}

Stats::Stats(int level, double damage, double defense, double healthpoints)
{
    this->level = level;
    this->damage = damage;
    this->defense = defense;
    this->healthpoints = healthpoints;
}

// Getters
int Stats::getLevel()
{
    return level;
}

double Stats::getDamage()
{
    return damage;
}

double Stats::getDefense()
{
    return defense;
}

double Stats::getHealthpoints()
{
    return healthpoints;
}

// Setters
void Stats::setLevel(int level)
{
    this->level = level;
}

void Stats::setDamage(double damage)
{
    this->damage = damage;
}

void Stats::setDefense(double defense)
{
    this->defense = defense;
}

void Stats::setHealthpoints(double healthpoints)
{
    this->healthpoints = healthpoints;
}