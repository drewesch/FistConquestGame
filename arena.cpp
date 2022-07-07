#include "arena.h"

// Constructors / Destructors
Arena::Arena()
{
}

Arena::~Arena()
{
}

Arena::Arena(Player fightingPlayer, Enemy enemy, int turnNumber)
{
    this->fightingPlayer = fightingPlayer;
    this->enemy = enemy;
    this->turnNumber = turnNumber;
}

// Getters
Player Arena::getFightingPlayer()
{
    return fightingPlayer;
}

Enemy Arena::getEnemy()
{
    return enemy;
}

int Arena::getTurnNumber()
{
    return turnNumber;
}

// Setters
void Arena::setFightingPlayer(Player fightingPlayer)
{
    this->fightingPlayer = fightingPlayer;
}
    
void Arena::setEnemy(Enemy enemy)
{
    this->enemy = enemy;
}

void Arena::setTurnNumber(int turnNumber)
{
    this->turnNumber = turnNumber;
}

// Private Functions
double Arena::isEffective(Ability attack, Shield defense)
{
    /*
    This function returns a multiplier for the damage.

    Element Effectiveness Chart
        Air (Attack) (2) -> +100% to Water (Defense)
        Water (3) -> +100% to Earth (Defense)
        Earth (4) -> +100% to Fire (Defense)
        Fire (5) -> +100% to Air (Defense)
        Note: Normal is not effective against anything
    
    Ineffective: When the attack is the same element as the defense element, reduce damage by 50%

    */
    double multiplier;
    if (attack.getElement() == defense.getElement()) {
        cout << "It was not very effective..." << endl;
        multiplier = 0.5;
    } else if (attack.getElement() != 0 || defense.getElement() != 0) {
        if ((defense.getElement() % 5) == (attack.getElement() + 1) % 5) {
            cout << "It was very effective..." << endl;
            multiplier = 2.0;
        }
    } else {
        multiplier = 1.0;
    }

    int chance = rand()%(100);

    // Decide if a shield parries or reduces damage
    if (chance < defense.getParryPercentage()) {
        cout << "The shield parried!" << endl;
        multiplier = 0;
    } else if (chance < defense.getReducePercentage() && chance >= defense.getParryPercentage()) {
        cout << "The shield withstood some damage" << endl;
        multiplier = (multiplier*defense.getReduceAmount())/100;
    }
}

// Private Enemy Generator Functions

Ability* Arena::decideAbilities(int numAbilities)
{
    Ability* returnAbilities;
    AbilityList abilityList;

    // If the enemy can have 5 abilities, it means they can use all abilities (return all abilities)
    // Otherwise, return a random sequence of abilities based on the number they're allowed to have

    if (numAbilities >= 5) {
        // Return all abilities
        returnAbilities = new Ability[5];
        for (int i = 0; i < 5; i++) {
            returnAbilities[i] = abilityList(i, false);
        }
    } else {
        returnAbilities = new Ability[numAbilities];
        
        // Randomly decide which abilities the enemy should have
        // There should be no duplicate abilities
        int* abilityNums = new int[numAbilities];
        int iterate;
        for (int i = 0; i < numAbilities; i++) {
            iterate = 1;
            int numAbility = rand()%(numAbilities+1);
            for (int j = 0; j < iterate; j++) {
                while (abilityNums[j] == numAbility) {
                    numAbility = rand()%(numAbilities+1);
                }
            }
            iterate++;
            abilityNums[i] = numAbility;
        }

        // Return generated abilities
        for (int i = 0; i < numAbilities; i++) {
            returnAbilities[i] = abilityList(abilityNums[i], false);
        }
    }
}

Shield* Arena::decideShields(int numShields)
{
    Shield* returnShields;
    ShieldList shieldList;

    // If the enemy can have 5 shields, it means they can use all shields (return all shields)
    // Otherwise, return a random sequence of shields based on the number they're allowed to have

    if (numShields >= 5) {
        // Return all shields
        returnShields = new Shield[5];
        for (int i = 0; i < 5; i++) {
            returnShields[i] = shieldList(i, false);
        }
    } else {
        returnShields = new Shield[numShields];
        
        // Randomly decide which shields the enemy should have
        // There should be no duplicate shields
        int* shieldNums = new int[numShields];
        int iterate;
        for (int i = 0; i < numShields; i++) {
            iterate = 1;
            int numShield = rand()%(numShields+1);
            for (int j = 0; j < iterate; j++) {
                while (shieldNums[j] == numShield) {
                    numShield = rand()%(numShields+1);
                }
            }
            iterate++;
            shieldNums[i] = numShield;
        }

        // Return generated abilities
        for (int i = 0; i < numShields; i++) {
            returnShields[i] = shieldList(shieldNums[i], false);
        }
    }
}

// Custom Functions
void Arena::generateEnemy()
{   
    // Decide enemy level
    // Enemy level cannot be higher than player level
    int maxLevel = fightingPlayer.getStats().getLevel();
    int enemyLevel = rand()%(maxLevel)+1;

    // Randomy decide enemy stats with given rules
    double enemyHitpoints = rand()%(50)+(10.0*enemyLevel);
    double enemyDamage = rand()%(10)+(2.0*enemyLevel);
    double enemyDefense = rand()%(5)+(1.0*enemyLevel);

    // Decide 1-3 random abilities and shields for the enemy
    int numAbilities = rand()%(3)+1;
    Ability* enemyAbilities = decideAbilities(numAbilities);
    int numShields = rand()%(3)+1;
    Shield* enemyShields = decideShields(numShields);
    
    // All enemies should have 1 potion of each type
    int numPotions = 3;
    Potion* enemyPotions = new Potion[numPotions];
    PotionList potionList;
    for (int i = 0; i < numPotions; i++) {
        enemyPotions[i] = potionList(i);
    }

    // Decide victory rewards
    int enemyBalance = rand()%(50)+(5*enemyLevel);
    int experienceReward = rand()%(10)+5;

    // Create the enemy
    int guardNum = rand()%(1000)+1;
    string enemyName = "Guard" + to_string(guardNum);
    Stats enemyStats(enemyLevel, enemyHitpoints, enemyDamage, enemyDefense);
    Inventory enemyInventory(enemyAbilities, numAbilities, enemyShields, numShields, enemyPotions, numPotions, enemyBalance);

    enemy = Enemy(enemyName, enemyStats, enemyInventory, experienceReward);
}

Enemy Arena::generateEnemy(string name, int level)
{   
    // Decide enemy level
    // Enemy level cannot be higher than player level
    int enemyLevel = rand()%(level)+1;

    // Randomy decide enemy stats with given rules
    int enemyHitpoints = rand()%(50)+(10.0*enemyLevel);
    int enemyDamage = rand()%(10)+(2.0*enemyLevel);
    int enemyDefense = rand()%(5)+(1.0*enemyLevel);

    // Decide 1-3 random abilities and shields for the enemy
    int numAbilities = rand()%(3)+1;
    Ability* enemyAbilities = decideAbilities(numAbilities);
    int numShields = rand()%(3)+1;
    Shield* enemyShields = decideShields(numShields);
    
    // All enemies should have 1 potion of each type
    int numPotions = 3;
    Potion* enemyPotions = new Potion[numPotions];
    PotionList potionList;
    for (int i = 0; i < numPotions; i++) {
        enemyPotions[i] = potionList(i);
    }

    // Decide victory rewards
    int enemyBalance = rand()%(50)+(5*enemyLevel);
    int experienceReward = rand()%(10)+5;

    // Create the enemy
    Stats enemyStats(enemyLevel, enemyHitpoints, enemyDamage, enemyDefense);
    Inventory enemyInventory(enemyAbilities, numAbilities, enemyShields, numShields, enemyPotions, numPotions, enemyBalance);

    return Enemy(name, enemyStats, enemyInventory, experienceReward);
}

bool Arena::iterateTurns()
{
	bool isOutcome = false;
	Ability chosenPlayerAbility;
    Ability chosenEnemyAbility;
	Shield chosenPlayerShield;
    Shield chosenEnemyShield = enemy.getInventory().getShields()[0];
    Potion chosenPlayerPotion;
    Potion chosenEnemyPotion;

	while (isOutcome == false) {
		// The player will always have the first turn in a given round
		bool isPlayerTurn = true;
		if (isPlayerTurn == true) {
			cout << "Turn #" << to_string(getTurnNumber()) << ": " << fightingPlayer.getName() << "\' turn!" << endl;
			
			// Display Player Turn Cutscene
			// cutscenes[x].display();
			
			cout << "What would you like to do?"<< endl;
			cout << "Options: Fight (F), Potions (P), View Character Sheet (C), Flee (F)" << endl;
			
			string input;
			cin >> input;

            // Convert input to lowercase
            for (int i = 0; i < input.length(); i++) {
                input[i] = tolower(input[i]);
            }

            bool endTurn = false;

            while (endTurn == false) {
                if (input == "f") {
                    // Display available Abilities
                    Ability* abilities = fightingPlayer.getInventory().getAbilities();
                    Shield* shields = fightingPlayer.getInventory().getShields();

                    // Ask for an ability
                    bool proceed = false;
                    while (proceed == false) {
                        // Get length of total abilities, then display options
                        int totalAbilities = fightingPlayer.getInventory().getNumAbilities();
                        string options;
                        cout << "Choose an ability!" << endl;
                        for (int i = 0; i < totalAbilities; i++) {
                            cout << abilities[i].getName() + "(" + to_string(i) + ")" << endl;
                        }
                        
                        cin >> input;
                        bool isValid = false;
                        
                        // Check if the input is in the list of possible abilities
                        for (int i = 0; i < totalAbilities; i++) {
                            if (stoi(input) == i) {
                                isValid = true;
                            }
                        }
                        
                        // If the input is valid, make that the chosen ability
                        if (isValid == true) {
                            chosenPlayerAbility = abilities[stoi(input)];
                            proceed = true;
                        } else {
                            cout << "Invalid option, please input a valid number from the list above." << endl;
                        }
                    }
                    
                    // Ask for a shield input
                    proceed = false;
                    while (proceed == false) {
                        // Get length of total shields, then display options
                        int totalShields = fightingPlayer.getInventory().getNumShields();
                        string options;
                        cout << "Choose a shield!" << endl;
                        for (int i = 0; i < totalShields; i++) {
                            cout << shields[i].getName() + "(" + to_string(i) + ")" << endl;
                        }
                        
                        cin >> input;
                        bool isValid = false;
                        
                        // Check if the input is in the list of all shields
                        for (int i = 0; i < totalShields; i++) {
                            if (stoi(input) == i) {
                                isValid = true;
                            }
                        }
                        
                        // If the input is valid, make that the chosen shield and remove one durability
                        // If the shield is not usable, do not select it as the chosen shield
                        if (isValid == true) {
                            if (shields[stoi(input)].getUsability() == true) {
                                int newDurability = shields[stoi(input)].getDurability() - 1;
                                shields[stoi(input)].setDurability(newDurability);
                                chosenPlayerShield = shields[stoi(input)];

                                // Check if it is still usable
                                if (chosenPlayerShield.getDurability() == 0) {
                                    shields[stoi(input)].setUsability(false);
                                }

                                proceed = true;
                            } else {
                                cout << "This shield is broken... please select a different shield and get this one repaired at the armory." << endl;
                            }
                        } else {
                            cout << "Invalid option, please input a valid number from the list above." << endl;
                        }
                    }

                    // Do potion effects
                    // Increase damage, defense, or healthpoints by specific stat increase
                    // Increase healthpoints for one turn (immediate use)
                    if (chosenPlayerPotion.getType() == healing && chosenPlayerPotion.getTurnsInEffect() == 1) {
                        int newHealthPoints = (fightingPlayer.getStats().getHealthpoints() * chosenPlayerPotion.getStatIncreasePercentage()) / 100;
                        fightingPlayer.getStats().setHealthpoints(newHealthPoints);
                    } else if (chosenPlayerPotion.getType() == strength) {
                        // Increase stat only if its in use
                        // Return it back to normal once its no longer in effect
                        if (chosenPlayerPotion.getTurnsInEffect() == 4) {
                            int newDamage = (fightingPlayer.getStats().getDamage() * chosenPlayerPotion.getStatIncreasePercentage()) / 100;
                            fightingPlayer.getStats().setDamage(newDamage);
                        } else if (chosenPlayerPotion.getTurnsInEffect() == 0) {
                            int newDamage = (fightingPlayer.getStats().getDamage() * chosenPlayerPotion.getStatIncreasePercentage()) / chosenPlayerPotion.getStatIncreasePercentage();
                            fightingPlayer.getStats().setDamage(newDamage);
                        }
                    } else if (chosenPlayerPotion.getType() == defense) {
                        // Increase stat only if its in use
                        // Return it back to normal once its no longer in effect
                        if (chosenPlayerPotion.getTurnsInEffect() == 4) {
                            int newDefense = (fightingPlayer.getStats().getDefense() * chosenPlayerPotion.getStatIncreasePercentage()) / 100;
                            fightingPlayer.getStats().setDefense(newDefense);
                        } else if (chosenPlayerPotion.getTurnsInEffect() == 0) {
                            int newDefense = (fightingPlayer.getStats().getDefense() * chosenPlayerPotion.getStatIncreasePercentage()) / chosenPlayerPotion.getStatIncreasePercentage();
                            fightingPlayer.getStats().setDefense(newDefense);
                        }
                    }

                    // Do damage to enemy & activate attack cutscenes
                    int damage = ((fightingPlayer.getStats().getDamage() * isEffective(chosenPlayerAbility, chosenEnemyShield))/2) - enemy.getStats().getDefense();

                    // Always do at least 1 damage
                    if (damage < 1) {
                        damage = 1;
                    }

                    int newHealthpoints = enemy.getStats().getHealthpoints() - damage;
                    enemy.getStats().setHealthpoints(newHealthpoints);

                    // Display attack cutscenes
                    // cutscenes[x].display;

                    // End turn
                    endTurn = true;

                    // Check if enemy healthpoints is at or below zero
                    // End battle if the player won
                    if (enemy.getStats().getHealthpoints() < 1) {
                        endBattleResults();
                    }					 

                } else if (input == "p") {
                    // Display Potion Options
                    Potion* potions = fightingPlayer.getInventory().getPotions();
                    int totalPotions = fightingPlayer.getInventory().getNumPotions();

                    // Ask for a potion, if possible
                    bool proceed = false;
                    while (proceed == false) {
                        // If there are none, return to the battle menu
                        if (totalPotions == 0) {
                            proceed = true;
                            cout << "Sorry, there are no available potions to use." << endl;
                            break;
                        } else if (chosenPlayerPotion.getTurnsInEffect() > 0) {
                            proceed = true;
                            cout << "A potion is already in use, please decide something else" << endl;
                            break;
                        } else {
                            // Ask player for potion
                            cout << "Choose a potion!" << endl;
                            for (int i = 0; i < totalPotions; i++) {
                                cout << potions[i].getName() + "(" + to_string(i) + ")" << endl;
                            }

                            string input;
                            cin >> input;

                            bool isValid = false;
                            
                            // Check if the input is in the list of possible potions
                            for (int i = 0; i < totalPotions; i++) {
                                if (stoi(input) == i) {
                                    isValid = true;
                                }
                            }
                            
                            // If the input is valid, make that the chosen potion & remove it from the fightingPlayer Inventory
                            if (isValid == true) {
                                chosenPlayerPotion = potions[stoi(input)];
                                proceed = true;

                                // Remove it from Inventory
                                for (int i = 0; i < totalPotions; i++) {
                                    if (i == stoi(input))
                                    {
                                            Potion* newPotions = new Potion[totalPotions-1];
                                            copy(potions, potions+i, newPotions);
                                            copy(potions+i+1, potions+totalPotions, newPotions+i);
                                            delete[] potions;
                                            potions = newPotions;
                                            totalPotions--;
                                            fightingPlayer.getInventory().setNumPotions(totalPotions);
                                    }
                                }
                                
                                // Use potion
                                // Increase damage, defense, or healthpoints by specific stat increase
                                // Increase healthpoints for one turn (immediate use)
                                if (chosenPlayerPotion.getType() == healing && chosenPlayerPotion.getTurnsInEffect() == 1) {
                                    int newHealthPoints = (fightingPlayer.getStats().getHealthpoints() * chosenPlayerPotion.getStatIncreasePercentage()) / 100;
                                    fightingPlayer.getStats().setHealthpoints(newHealthPoints);
                                } else if (chosenPlayerPotion.getType() == strength) {
                                    // Increase stat only if its in use
                                    // Return it back to normal once its no longer in effect
                                    if (chosenPlayerPotion.getTurnsInEffect() == 4) {
                                        int newDamage = (fightingPlayer.getStats().getDamage() * chosenPlayerPotion.getStatIncreasePercentage()) / 100;
                                        fightingPlayer.getStats().setDamage(newDamage);
                                    } else if (chosenPlayerPotion.getTurnsInEffect() == 0) {
                                        int newDamage = (fightingPlayer.getStats().getDamage() * chosenPlayerPotion.getStatIncreasePercentage()) / chosenPlayerPotion.getStatIncreasePercentage();
                                        fightingPlayer.getStats().setDamage(newDamage);
                                    }
                                } else if (chosenPlayerPotion.getType() == defense) {
                                    // Increase stat only if its in use
                                    // Return it back to normal once its no longer in effect
                                    if (chosenPlayerPotion.getTurnsInEffect() == 4) {
                                        int newDefense = (fightingPlayer.getStats().getDefense() * chosenPlayerPotion.getStatIncreasePercentage()) / 100;
                                        fightingPlayer.getStats().setDefense(newDefense);
                                    } else if (chosenPlayerPotion.getTurnsInEffect() == 0) {
                                        int newDefense = (fightingPlayer.getStats().getDefense() * chosenPlayerPotion.getStatIncreasePercentage()) / chosenPlayerPotion.getStatIncreasePercentage();
                                        fightingPlayer.getStats().setDefense(newDefense);
                                    }
                                }

                                endTurn = true;

                            } else {
                                cout << "Invalid option, please input a valid number from the list above." << endl;
                            }
					    }
                    }
                } else if (input == "c") {
                    // Display Character Sheet Cutscene
                    // cutscenes[x].display();
                    // Implement this further later

                } else if (input == "f") {
                    // Confirm if the user wants to flee
                    // If so, leave the arena.
                    bool proceed = false;
                    while (proceed == false) {
                        cout << "Are you sure you want to leave (y/n)?" << endl;
                        
                        string input;
                        cin >> input;
                        
                        // Convert input to lowercase
                        for (int i = 0; i < input.length(); i++) {
                            input[i] = tolower(input[i]);
                        }

                        if (input == "y") {
                            proceed = true;
                            isOutcome = true;
                            return false;
                        } else if (input == "n") {
                        } else {
                            cout << "Invalid input. Please try again." << endl;
                        }
                    }
                }
            }
	    } else {
            // Enemy Turn Logic

            // Randomly decide to either fight or use a potion
            // 0 - Fight, 1 - Potion
            int enemyDecision = rand()%(2);
            bool endTurn = false;

            while (endTurn == false) {
                if (enemyDecision == 0) {
                    Ability* abilities = enemy.getInventory().getAbilities();
                    Shield* shields = enemy.getInventory().getShields();

                    int totalAbilities = enemy.getInventory().getNumAbilities();
                    int totalShields = enemy.getInventory().getNumShields();
                    int abilityNum = rand()%(totalAbilities);
                    int shieldNum = rand()%(totalShields);

                    chosenEnemyAbility = abilities[abilityNum];
                    chosenEnemyShield = shields[shieldNum];

                    // Do damage to player & activate attack cutscenes
                    int damage = ((enemy.getStats().getDamage() * isEffective(chosenEnemyAbility, chosenPlayerShield))/2) - fightingPlayer.getStats().getDefense();

                    // Always do at least 1 damage
                    if (damage < 1) {
                        damage = 1;
                    }

                    int newHealthpoints = fightingPlayer.getStats().getHealthpoints() - damage;
                    fightingPlayer.getStats().setHealthpoints(newHealthpoints);

                    // Display attack cutscenes
                    // cutscenes[x].display;

                    // End turn
                    endTurn = true;

                    // Check if player healthpoints is at or below zero
                    // End battle if the enemy won
                    if (fightingPlayer.getStats().getHealthpoints() < 1) {
                        // cutscenes[x].display();
                        isOutcome = true;
                        return false;
                    }

                } else {
                    // Check if there are any potions left
                    Potion* potions = enemy.getInventory().getPotions();
                    int totalPotions = enemy.getInventory().getNumPotions();
                    
                    if (totalPotions == 0) {
                        continue;
                    } else {
                        // Select Potion
                        int potionNum = rand()%(totalPotions);
                        chosenEnemyPotion = potions[potionNum];

                        // Remove it from enemy's inventory
                        for (int i = 0; i < totalPotions; i++) {
                            if (i == potionNum)
                            {
                                Potion* newPotions = new Potion[totalPotions-1];
                                copy(potions, potions+i, newPotions);
                                copy(potions+i+1, potions+totalPotions, newPotions+i);
                                delete[] potions;
                                potions = newPotions;
                                totalPotions--;
                                enemy.getInventory().setNumPotions(totalPotions);
                            }
                        }
                        // Use potion
                        // Increase damage, defense, or healthpoints by specific stat increase
                        // Increase healthpoints for one turn (immediate use)
                        if (chosenEnemyPotion.getType() == healing && chosenEnemyPotion.getTurnsInEffect() == 1) {
                            int newHealthPoints = (enemy.getStats().getHealthpoints() * chosenEnemyPotion.getStatIncreasePercentage()) / 100;
                            enemy.getStats().setHealthpoints(newHealthPoints);
                        } else if (chosenEnemyPotion.getType() == strength) {
                            // Increase stat only if its in use
                            // Return it back to normal once its no longer in effect
                            if (chosenEnemyPotion.getTurnsInEffect() == 4) {
                                int newDamage = (enemy.getStats().getDamage() * chosenEnemyPotion.getStatIncreasePercentage()) / 100;
                                enemy.getStats().setDamage(newDamage);
                            } else if (chosenEnemyPotion.getTurnsInEffect() == 0) {
                                int newDamage = (enemy.getStats().getDamage() * chosenEnemyPotion.getStatIncreasePercentage()) / chosenEnemyPotion.getStatIncreasePercentage();
                                enemy.getStats().setDamage(newDamage);
                            }
                        } else if (chosenEnemyPotion.getType() == defense) {
                            // Increase stat only if its in use
                            // Return it back to normal once its no longer in effect
                            if (chosenEnemyPotion.getTurnsInEffect() == 4) {
                                int newDefense = (enemy.getStats().getDefense() * chosenEnemyPotion.getStatIncreasePercentage()) / 100;
                                enemy.getStats().setDefense(newDefense);
                            } else if (chosenEnemyPotion.getTurnsInEffect() == 0) {
                                int newDefense = (enemy.getStats().getDefense() * chosenEnemyPotion.getStatIncreasePercentage()) / chosenEnemyPotion.getStatIncreasePercentage();
                                enemy.getStats().setDefense(newDefense);
                            }
                        }

                        endTurn = true;
                        
                    }
                }
            }
        }
    }
}

bool Arena::endBattleResults()
{
    // Victory Cutscene
    // Cutscenes[x].display();

    // Add Enemy Experience and Balance to Player
    int newExperience = fightingPlayer.getExperiencePoints() + enemy.getExperienceReward();
    fightingPlayer.setExperiencePoints(newExperience);
    int newPlayerBalance = fightingPlayer.getInventory().getBalance() + enemy.getInventory().getBalance();
    fightingPlayer.getInventory().setBalance(newPlayerBalance);

    // If experience is 50 or more, level up the player and player stats
    if (fightingPlayer.getExperiencePoints() >= 50) {
        int newLevel = fightingPlayer.getStats().getLevel() + 1;
        cout << "You leveled up! New level: " << newLevel << endl;
        fightingPlayer.getStats().setLevel(newLevel);
    
        // Update all stats
        double newPlayerHealthpoints = fightingPlayer.getStats().getHealthpoints() + 10.0;
        double newPlayerDamage = fightingPlayer.getStats().getHealthpoints() + 2.0;
        double newPlayerDefense = fightingPlayer.getStats().getHealthpoints() + 1.0;
        int newPlayerExperience = fightingPlayer.getExperiencePoints() - 50;

        fightingPlayer.getStats().setHealthpoints(newPlayerHealthpoints);
        fightingPlayer.getStats().setDamage(newPlayerDamage);
        fightingPlayer.getStats().setDefense(newPlayerDefense);
        fightingPlayer.setExperiencePoints(newPlayerExperience);
    }

    // Ask if the player wants to leave the arena
    cout << "Do you want to fight another enemy (y/n)?" << endl;
    string input;
    cin >> input;
    
    // Convert input to lowercase
    for (int i = 0; i < input.length(); i++) {
        input[i] = tolower(input[i]);
    }

    bool proceed = false;
    while (proceed == false)
    {
        if (input == "y") {
            proceed = true;
            generateEnemy();
            iterateTurns();
        } else if (input == "n") {
            proceed = true;
            break;
        } else {
            cout << "This is an invalid input. Please try again." << endl;
        }
    }
}

Player Arena::leaveArena()
{
    cout << "You are now leaving the arena..." << endl;

    // Set stats back to normal
    double newPlayerHealthpoints = fightingPlayer.getStats().getHealthpoints() + (10.0*fightingPlayer.getStats().getLevel());
    double newPlayerDamage = fightingPlayer.getStats().getHealthpoints() + (2.0*fightingPlayer.getStats().getLevel());;
    double newPlayerDefense = fightingPlayer.getStats().getHealthpoints() + (1.0*fightingPlayer.getStats().getLevel());;
    
    fightingPlayer.getStats().setHealthpoints(newPlayerHealthpoints);
    fightingPlayer.getStats().setDamage(newPlayerDamage);
    fightingPlayer.getStats().setDefense(newPlayerDefense);

    return fightingPlayer;
}