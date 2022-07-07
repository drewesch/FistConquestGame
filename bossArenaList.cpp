#include "bossArenaList.h"

// Function Object (Functor)
BossArena BossArenaList::operator()(int num)
{
    BossArena* bossArenas = new BossArena[3];
    int numEnemies = 5;
    if (num == 0) {
        // Mallard's Tower
        BossArena Mallard;
        Mallard.setBossName("Mallard's Tower");
        Enemy* enemies = new Enemy[numEnemies];
        
        // Level Minimum
        int level = 4;

        // First four enemies will be pre-generated
        for (int i = 0; i < 4; i++) {
            string name = "Watcher #" + to_string(rand()%(10));
            Enemy newEnemy = Mallard.generateEnemy(name, level);
            enemies[i] = newEnemy;
        }

        // The last enemy is the boss, which has a higher level than the other
        // The boss also has every shield and ability except for one
        // Boss Weakness: Air
        level = 10;
        string name = "Mallard";
        Enemy boss = Mallard.generateEnemy(name, level);
        boss.setExperienceReward(50);
        boss.getInventory().setBalance(1000);

        // Set new abilities and shields
        int weakness = 1;
        Ability* newAbilities = new Ability[4];
        Shield* newShields = new Shield[4];
        AbilityList abilityList;
        ShieldList shieldList;

        for (int i = 0; i < 5; i++) {
            Ability ability;
            Shield shield;
            if (i == weakness) {
            } else {
                ability = abilityList(i, false);
                shield = shieldList(i, false);
            }
        }

        boss.getInventory().setAbilities(newAbilities);
        boss.getInventory().setShields(newShields);

        return Mallard;
    } else if (num == 1) {
        // Honchman's Stronghold
        BossArena Honchman;
        Honchman.setBossName("Honchman's Stronghold");
        Enemy* enemies = new Enemy[numEnemies];

        // Level Minimum
        int level = 7;

        // First four enemies will be pre-generated
        for (int i = 0; i < 4; i++) {
            string name = "Keeper #" + to_string(rand()%(10));
            Enemy newEnemy = Honchman.generateEnemy(name, level);
            enemies[i] = newEnemy;
        }

        // The last enemy is the boss, which has a higher level than the other
        // The boss also has every shield and ability except for one
        // Boss Weakness: Earth
        level = 12;
        string name = "Honchman";
        Enemy boss = Honchman.generateEnemy(name, level);
        boss.setExperienceReward(50);
        boss.getInventory().setBalance(1000);

        // Set new abilities and shields
        int weakness = 3;
        Ability* newAbilities = new Ability[4];
        Shield* newShields = new Shield[4];
        AbilityList abilityList;
        ShieldList shieldList;

        for (int i = 0; i < 5; i++) {
            Ability ability;
            Shield shield;
            if (i == weakness) {
            } else {
                ability = abilityList(i, false);
                shield = shieldList(i, false);
            }
        }

        boss.getInventory().setAbilities(newAbilities);
        boss.getInventory().setShields(newShields);

        return Honchman;
    } else if (num == 2) {
        // King's Throne Room
        BossArena King;
        King.setBossName("King's Throne Room");
        Enemy* enemies = new Enemy[numEnemies];

        // Level Minimum
        int level = 10;
        
        // The last enemy is the boss, which is customized
        for (int i = 0; i < 4; i++) {
            string name = "Guardian #" + to_string(rand()%(10));
            Enemy newEnemy = King.generateEnemy(name, level);
            enemies[i] = newEnemy;
        }

        // The last enemy is the boss, which has a higher level than the other
        // The boss also has every shield and ability except for one
        // Boss Weakness: Normal
        level = 15;
        string name = "King";
        Enemy boss = King.generateEnemy(name, level);

        // Set new abilities and shields
        int weakness = 0;
        Ability* newAbilities = new Ability[4];
        Shield* newShields = new Shield[4];
        AbilityList abilityList;
        ShieldList shieldList;

        for (int i = 0; i < 5; i++) {
            Ability ability;
            Shield shield;
            if (i == weakness) {
            } else {
                ability = abilityList(i, false);
                shield = shieldList(i, false);
            }
        }

        boss.getInventory().setAbilities(newAbilities);
        boss.getInventory().setShields(newShields);

        return King;
    }
}