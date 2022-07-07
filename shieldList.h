#ifndef SHIELDLIST_H
#define SHIELDLIST_H

#include "shield.h"
#include "element.h"
#include <string>

class ShieldList
{
    public:
    Shield operator()(int, bool);
};

#endif