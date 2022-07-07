#ifndef CUTSCENELIST_H
#define CUTSCENELIST_H

#include "cutscene.h"
#include <string>

class CutsceneList
{
    public:
    Cutscene operator()(int);
};

#endif