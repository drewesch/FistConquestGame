#include "player.h"

// Constructors / Destructors
Player::Player()
{
}

Player::~Player()
{
}

Player::Player(string name, Stats stats, Inventory inventory, int saveID, int experiencePoints)
{
    setName(name);
    setStats(stats);
    setInventory(inventory);
    this->saveID = saveID;
    this->experiencePoints = experiencePoints;
}

// Getters
int Player::getSaveID()
{
    return saveID;
}

int Player::getExperiencePoints()
{
    return experiencePoints;
}

// Setters
void Player::setSaveID(int saveID)
{
    this->saveID = saveID;
}

void Player::setExperiencePoints(int experiencePoints)
{
    this->experiencePoints = experiencePoints;
}