#ifndef POTION_H
#define POTION_H

#include <string>
#include "item.h"
#include "potionType.h"

using namespace std;

class Potion: public Item
{
    private:
    PotionType type;
    double statIncreasePercentage;
    int turnsInEffect;

    public:
    // Constructors / Destructors
    Potion();
    ~Potion();
    Potion(string, string, int, PotionType, double, int);
    Potion(Potion &p);

    // Getters
    PotionType getType();
    double getStatIncreasePercentage();
    int getTurnsInEffect();

    // Setters
    void setType(PotionType);
    void setStatIncreasePercentage(double);
    void setTurnsInEffect(int);

    // Overloaded Operators
    bool operator==(Potion &p2);
};

#endif 