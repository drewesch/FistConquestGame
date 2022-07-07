#ifndef ABILITYLIST_H
#define ABILITYLIST_H

#include "ability.h"
#include "element.h"
#include <string>

class AbilityList
{
    public:
    Ability operator()(int, bool);
};

#endif