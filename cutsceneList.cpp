#include "cutsceneList.h"

// Function Object (Functor)
Cutscene CutsceneList::operator()(int num)
{
    /*
    Identification List:
        - Start Menu: 0
        - Main Menu: 1
        - Character Sheet: 2
        - Armory Menu: 3
        - Arena Menu: 4
        - Player Fight Cutscene: 5
        - Enemy Fight Cutscene: 6
        - Player Use Potion Cutscene: 7
        - Enemy Use Potion Cutscene: 8
        - Victory Cutscene: 9
        - Defeat Cutscene: 10
        - Tutorial Cutscenes: 11-x
        - Final Cutscenes: x+1-y
    */
    
    // Pre-defined Variables
    int totalCutscenes = 13;
    Cutscene* cutscenes = new Cutscene[totalCutscenes];
    string fileName;
    int length = 24;
    int timeInterval;
    int defaultTime = 1;
    timeInterval = defaultTime;

    // Start Menu
    Cutscene startMenu;
    fileName = "./Cutscenes/Menus/startMenu.txt";
    startMenu.create(fileName, length, timeInterval);
    cutscenes[0] = startMenu;

    // Main Menu
    Cutscene mainMenu;
    fileName = "./Cutscenes/Menus/mainMenu.txt";
    mainMenu.create(fileName, length, timeInterval);
    cutscenes[1] = mainMenu;

    // Character Sheet
    Cutscene characterSheet;
    fileName = "./Cutscenes/Menus/characterSheet.txt";
    characterSheet.create(fileName, length, timeInterval);
    cutscenes[2] = characterSheet;

    // Armory Menu
    Cutscene armoryMenu;
    fileName = "./Cutscenes/Menus/armoryMenu.txt";
    armoryMenu.create(fileName, length, timeInterval);
    cutscenes[3] = armoryMenu;

    // Arena Menu
    Cutscene arenaMenu;
    fileName = "./Cutscenes/Menus/arenaMenu.txt";
    arenaMenu.create(fileName, length, timeInterval);
    cutscenes[4] = arenaMenu;

    // Player Fight Cutscene
    Cutscene playerFight;
    timeInterval = 3;
    fileName = "./Cutscenes/Arena/playerFight.txt";
    playerFight.create(fileName, length, timeInterval);
    cutscenes[5] = playerFight;

    // Enemy Fight Cutscene
    Cutscene enemyFight;
    fileName = "./Cutscenes/Arena/enemyFight.txt";
    enemyFight.create(fileName, length, timeInterval);
    cutscenes[6] = enemyFight;

    // Player Use Potion Cutscene
    Cutscene playerUsePotion;
    fileName = "./Cutscenes/Arena/playerUsePotion.txt";
    playerUsePotion.create(fileName, length, timeInterval);
    cutscenes[7] = playerUsePotion;

    // Enemy Use Potion Cutscene
    Cutscene enemyUsePotion;
    fileName = "./Cutscenes/Arena/enemyUsePotion.txt";
    enemyUsePotion.create(fileName, length, timeInterval);
    cutscenes[8] = enemyUsePotion;

    // Victory Cutscene
    Cutscene victory;
    fileName = "./Cutscenes/Arena/victory.txt";
    victory.create(fileName, length, timeInterval);
    cutscenes[9] = victory;

    // Defeat Cutscene
    Cutscene defeat;
    fileName = "./Cutscenes/Arena/defeat.txt";
    defeat.create(fileName, length, timeInterval);
    cutscenes[10] = defeat;

    // Tutorial Scenes
    Cutscene tutorial1;
    timeInterval = 5;
    fileName = "./Cutscenes/Tutorial/scene1.txt";
    tutorial1.create(fileName, length, timeInterval);
    cutscenes[11] = tutorial1;

    // Final Scenes
    Cutscene final1;
    timeInterval = 5;
    fileName = "./Cutscenes/Tutorial/final1.txt";
    final1.create(fileName, length, timeInterval);
    cutscenes[12] = final1;

    return cutscenes[num];
}