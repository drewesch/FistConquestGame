#include "item.h"

// Constructors / Destructors
Item::Item()
{
}

Item::~Item()
{
}

Item::Item(string name, string description, int price)
{
    this->name = name;
    this->description = description;
    this->price = price;
}

// Getters
string Item::getName()
{
    return name;
}

string Item::getDescription()
{
    return description;
}

int Item::getPrice()
{
    return price;
}

// Setters
void Item::setName(string name)
{
    this->name = name;
}

void Item::setDescription(string description)
{
    this->description = description;
}

void Item::setPrice(int price)
{
    this->price = price;
}

// Overloaded Operators
bool Item::operator==(Item &i2)
{
    return ((i2.getName() == name) && (i2.getDescription() == description) && (i2.getPrice() == price));
}