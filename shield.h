#ifndef SHIELD_H
#define SHIELD_H

#include <string>
#include "item.h"
#include "element.h"

using namespace std;

class Shield: public Item
{
    private:
    Element element;
    double parryPercentage;
    double reducePercentage;
    double reduceAmount;
    int durability;
    bool usability;

    public:
    // Constructors / Destructors
    Shield();
    ~Shield();
    Shield(string, string, int, Element, double, double, double, int, bool);
    Shield(Shield &s2);

    // Getters
    Element getElement();
    double getParryPercentage();
    double getReducePercentage();
    double getReduceAmount();
    int getDurability();
    bool getUsability();
    
    // Setters
    void setElement(Element);
    void setParryPercentage(double);
    void setReducePercentage(double);
    void setReduceAmount(double);
    void setDurability(int);
    void setUsability(bool);

    // Overloaded Operators
    bool operator==(Shield &s2);
};

#endif 