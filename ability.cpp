#include "ability.h"

// Constructors / Destructors
Ability::Ability()
{
}

Ability::~Ability()
{
}

Ability::Ability(string name, string description, int price, Element element)
{
    setName(name);
    setDescription(description);
    setPrice(price);
    this->element = element;
}

Ability::Ability(Ability &a2)
{
    setName(a2.getName());
    setDescription(a2.getDescription());
    setPrice(a2.getPrice());
    this->element = a2.element;
}

// Getters
Element Ability::getElement()
{
    return element;
}

// Setters
void Ability::setElement(Element element)
{
    this->element = element;
}

// Overloaded Operators
bool Ability::operator==(Ability &a2)
{
    return (a2.getElement() == element);
}