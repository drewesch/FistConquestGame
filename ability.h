#ifndef ABILITY_H
#define ABILITY_H

#include <string>
#include "item.h"
#include "element.h"

using namespace std;

class Ability: public Item
{
    private:
    Element element;

    public:
    // Constructors / Destructors
    Ability();
    ~Ability();
    Ability(string, string, int, Element);
    Ability(Ability &a2);

    // Getters
    Element getElement();

    // Setters
    void setElement(Element);

    // Overloaded Operators
    bool operator==(Ability &a2);
};

#endif