#include "shield.h"

// Constructors / Destructors
Shield::Shield()
{
}

Shield::~Shield()
{
}

Shield::Shield(string name, string description, int price, Element element, double parryPercentage, double reducePercentage, double reduceAmount, int durability, bool usability)
{
    setName(name);
    setDescription(description);
    setPrice(price);
    this->element = element;
    this->parryPercentage = parryPercentage;
    this->reducePercentage = reducePercentage;
    this->reduceAmount = reduceAmount;
    this->durability = durability;
    this->usability = usability;
}

Shield::Shield(Shield &s2)
{
    setName(s2.getName());
    setDescription(s2.getDescription());
    setPrice(s2.getPrice());
    element = s2.element;
    parryPercentage = s2.parryPercentage;
    reducePercentage = s2.reducePercentage;
    reduceAmount = s2.reduceAmount;
    durability = s2.durability;
    usability = s2.usability;
}

// Getters
Element Shield::getElement()
{
    return element;
}

double Shield::getParryPercentage()
{
    return parryPercentage;
}

double Shield::getReducePercentage()
{
    return reducePercentage;
}

double Shield::getReduceAmount()
{
    return reduceAmount;
}

int Shield::getDurability()
{
    return durability;
}

bool Shield::getUsability()
{
    return usability;
}

// Setters
void Shield::setElement(Element element)
{
    this->element = element;
}

void Shield::setParryPercentage(double parryPercentage)
{
    this->parryPercentage = parryPercentage;
}

void Shield::setReducePercentage(double reducePercentage)
{ 
    this->reducePercentage = reducePercentage;
}

void Shield::setReduceAmount(double reduceAmount)
{
    this->reduceAmount = reduceAmount;
}

void Shield::setDurability(int durability)
{
    this->durability = durability;
}

void Shield::setUsability(bool usability)
{
    this->usability = usability;
}

// Overloaded Operators
bool Shield::operator==(Shield &s2)
{
    // Update this if needed
    return (s2.getElement() == element);
}