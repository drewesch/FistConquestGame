#ifndef GAME_H
#define GAME_H

#include <string>
#include <cstring>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <chrono>
#include <thread>
#include "player.h"
#include "armory.h"
#include "arena.h"
#include "bossArena.h"
#include "bossArenaList.h"
#include "cutscene.h"
#include "abilityList.h"
#include "shieldList.h"
#include "potionList.h"
#include "cutsceneList.h"
#include "bossArenaList.h"

using namespace std;

class Game
{
    private:
    Player player;
    Armory armory;
    BossArena* bossArenas;
    int numBossArenas;
    
    public:
    // Constructors / Destructors
    Game();
    ~Game();
    Game(Player, Armory, BossArena*, int);

    // Getters
    Player getPlayer();
    Armory getArmory();
    BossArena* getBossArenas();
    int getNumBossArenas();

    // Setters
    void setPlayer(Player);
    void setArmory(Armory);
    void setBossArenas(BossArena*);
    void setNumBossArenas(int);

    // Custom Functions
    void startGame();
    void generateGame();
    void generateBossArenas();
    void loadGame(int);
    void save();
    void exitGame();
    void displayCharacterSheet();
    void displayMainMenu();
    void startArmory();
    void startArenaBattle();
    void startBossArenaBattle();
};

#endif