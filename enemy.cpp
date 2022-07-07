#include "enemy.h"

// Constructors / Destructors
Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

Enemy::Enemy(string name, Stats stats, Inventory inventory, int experienceReward)
{
    setName(name);
    setStats(stats);
    setInventory(inventory);
    this->experienceReward = experienceReward;
}

// Getters
int Enemy::getExperienceReward()
{
    return experienceReward;
}

// Setters
void Enemy::setExperienceReward(int experienceReward)
{
    this->experienceReward = experienceReward;
}