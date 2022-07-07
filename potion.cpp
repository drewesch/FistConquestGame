#include "potion.h"

// Constructors / Destructors
Potion::Potion()
{
}

Potion::~Potion()
{
}

Potion::Potion(string name, string description, int price, PotionType type, double statIncreasePercentage, int turnsInEffect)
{
    setName(name);
    setDescription(description);
    setPrice(price);
    this->type = type;
    this->statIncreasePercentage = statIncreasePercentage;
    this->turnsInEffect = turnsInEffect;
}

Potion::Potion (Potion &p2)
{
    setName(p2.getName());
    setDescription(p2.getDescription());
    setPrice(p2.getPrice());
    type = p2.type;
    statIncreasePercentage = p2.statIncreasePercentage;
    turnsInEffect = p2.turnsInEffect;
}

// Getters
PotionType Potion::getType()
{
    return type;
}

double Potion::getStatIncreasePercentage()
{
    return statIncreasePercentage;
}

int Potion::getTurnsInEffect()
{
    return turnsInEffect;
}

// Setters
void Potion::setType(PotionType type)
{
    this->type = type;
}

void Potion::setStatIncreasePercentage(double statIncreasePercentage)
{
    this->statIncreasePercentage = statIncreasePercentage;
}

void Potion::setTurnsInEffect(int turnsInEffect)
{
    this->turnsInEffect = turnsInEffect;
}

// Overloaded Operators
bool Potion::operator==(Potion &p2)
{
    return (p2.getType() == type);
}