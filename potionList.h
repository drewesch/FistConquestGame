#ifndef POTIONLIST_H
#define POTIONLIST_H

#include "potion.h"
#include "potionType.h"
#include <string>

class PotionList
{
    public:
    Potion operator()(int);
};

#endif