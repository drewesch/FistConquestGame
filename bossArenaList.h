#ifndef BOSSARENALIST_H
#define BOSSARENALIST_H

#include "bossArena.h"
#include <string>

class BossArenaList
{
    public:
    BossArena operator()(int);
};

#endif