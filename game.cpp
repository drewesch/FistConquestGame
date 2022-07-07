#include "game.h"

// Constructors / Destructors
Game::Game()
{
}

Game::~Game()
{
}

Game::Game(Player player, Armory armory, BossArena* bossArenas, int numBossArenas)
{
    this->player = player;
    this->armory = armory;
    this->bossArenas = bossArenas;
    this->numBossArenas = numBossArenas;
}

// Getters
Player Game::getPlayer()
{
    return player;
}

Armory Game::getArmory()
{
    return armory;
}

BossArena* Game::getBossArenas()
{
    return bossArenas;
}

int Game::getNumBossArenas()
{
    return numBossArenas;
}

// Setters
void Game::setPlayer(Player player)
{
    this->player = player;
}

void Game::setArmory(Armory armory)
{
    this->armory = armory;
}

void Game::setBossArenas(BossArena* bossArenas)
{
    this->bossArenas = bossArenas;
}

void Game::setNumBossArenas(int numBossArenas) {
    this->numBossArenas = numBossArenas;
}

// Custom Functions
void Game::startGame() {
    // Load Cutscenes
    CutsceneList cutscenes;

    // Display Start Menu
    // cutscenes(0).display();

    /*
    Start Menu Decision (Move this to a function in Game)
    Option #1: Start a new game (N)
    Option #2: Load a prior save (L)
    Option #3: Exit the game (E)

    Loop over these options until the user has made a decision
    */

    bool proceed = false;
    while (proceed == false) {
        string input;
        cout << "What would you like to do?" << endl;
        cout << "Start a new game (n), Load a game (l), or exit the game (e)?" << endl;
        cin >> input;

        // Convert input to lowercase
        for (int i = 0; i < input.length(); i++) {
            input[i] = tolower(input[i]);
        }
        
        if (input == "n") {
            // Generate Player & Play Beginning Cutscene
            proceed = true;
            generateGame();
        } else if (input == "l") {
            // Ask for Identification Number, load game, and bring user to main menu
            bool proceedLoad = false;
            while (proceedLoad == false) {
                int ID;
                cout << "What is your profile identification number?" << endl;
                cout << "Note: You can find it at the top of the text file associated with the game profile." << endl;
                cin >> ID;

                if (isdigit(ID) == true) {
                    proceedLoad = true;
                    proceed = true;
                    cout << "Loading game..." << endl;
                    loadGame(ID);
                } else {
                    bool proceedLoad2 = false;
                    while (proceedLoad2 == false) {
                        cout << "This input was an invalid identification number. Try again (y/n)?" << endl;
                        cin >> input;
                        
                        // Convert input to lowercase
                        for (int i = 0; i < input.length(); i++) {
                            input[i] = tolower(input[i]);
                        }

                        if (input == "y") {
                            proceedLoad2 = true;
                        } else if (input == "n") {
                            proceedLoad = true;
                            proceedLoad2 = true;
                        }
                    }
                }
            }
        } else if (input == "e") {
            bool proceedExit = false;
            while (proceedExit == false) {
                cout << "Are you sure you want to leave the game (y/n)?" << endl;
                cin >> input;

                // Convert input to lowercase
                for (int i = 0; i < input.length(); i++) {
                    input[i] = tolower(input[i]);
                }

                if (input == "y") {
                    proceed = true;
                    proceedExit = true;
                    exit(0);
                } else if (input == "n") {
                    proceedExit = true;
                } else {
                    bool proceedExit2 = false;
                    while (proceedExit2 == false) {
                        cout << "This was an invalid input. Do you want to leave the game (y/n)?" << endl;
                        cin >> input;

                        // Convert input to lowercase
                        for (int i = 0; i < input.length(); i++) {
                            input[i] = tolower(input[i]);
                        }

                        if (input == "y") {
                            proceedExit2 = true;
                            proceedExit = true;
                            proceed = true;
                            exit(0);
                        } else if (input == "n") {
                            proceedExit = true;
                        }
                    }
                }
            }
        } else {
            cout << "This was an invalid input. Please try again." << endl;
        }
    }
}

void Game::generateGame() {
    // Variables to create Game object
    Player player;
    Armory armory;
    Arena arena;
    BossArena* bossArenas;
    int numBossArenas;

    // Ask for username
    string username;
    cout << "What will your username be?" << endl;
    cin >> username;
    this_thread::sleep_for(chrono::milliseconds(1*1000));
    cout << "Awesome, " << username << ", welcome to the kingdom of Marmothia!" << endl;
    this_thread::sleep_for(chrono::milliseconds(3*1000));

    // Give the player a random identifier
    int saveID;
    saveID = rand()%1000000;
    cout << "This is your save identification number: " << saveID << endl;
    cout << "This will be the name of your save file.\nInput this number when you want to reload your save point!" << endl;
    this_thread::sleep_for(chrono::milliseconds(5*1000));
    cout << "Generating a new game..." << endl;

    // Default Player Statistics
    Stats defaultStats;
    defaultStats.setLevel(1);
    defaultStats.setDamage(10.0);
    defaultStats.setDefense(5.0);
    defaultStats.setHealthpoints(100.0);
    cout << "continue" << endl;

    // Generate Default Player Inventory
    // Players starts with the default ability + shield, 1 healing potion, and 100 Sapphires
    
    // Call Item Lists (Functors)
    AbilityList abilityList;
    ShieldList shieldList;
    PotionList potionList;

    // Default Items
    Ability* abilities;
    int numAbilities = 1;
    abilities = new Ability[numAbilities];
    abilities[0] = abilityList(0, true);
    
    Shield* shields;
    int numShields = 1;
    shields = new Shield[numShields];
    shields[0] = shieldList(0, true);

    Potion* potions;
    int numPotions = 1;
    potions = new Potion[numPotions];
    potions[0] = potionList(0);

    int defaultBalance = 100;

    Inventory defaultInventory;
    defaultInventory.setAbilities(abilities);
    defaultInventory.setNumAbilities(numAbilities);
    defaultInventory.setShields(shields);
    defaultInventory.setNumShields(numShields);
    defaultInventory.setPotions(potions);
    defaultInventory.setNumPotions(numPotions);
    defaultInventory.setBalance(defaultBalance);
    cout << "continue" << endl;

    // Set initial experience
    int experiencePoints = 0;

    // Create the Player!
    player.setName(username);
    player.setStats(defaultStats);
    player.setInventory(defaultInventory);
    player.setSaveID(saveID);
    player.setExperiencePoints(experiencePoints);
    cout << "continue" << endl;

    // Create the Armory
    armory.generateArmory(player);
    cout << "complete" << endl;

    // Generate the Pre-coded Boss Arenas
    generateBossArenas();
    cout << "complete" << endl;
    
    // Save
    save();

    // Tutorial Cutscene

    // Go to main menu
    displayMainMenu();
}

void Game::generateBossArenas()
{
    // There should be 3 total arenas with different names and differet arrays of enemies
    BossArenaList bossArenaList;
    setNumBossArenas(3);
    BossArena* newBossArenas = new BossArena[numBossArenas];
    newBossArenas[0] = bossArenaList(0);
    newBossArenas[1] = bossArenaList(1);
    newBossArenas[2] = bossArenaList(2);
    bossArenas = newBossArenas;
}

void Game::loadGame(int ID) {
    /* 
    List of Loadable Objects:
        1. Player Data 
        2. Current Armory 
        3. Remaining Boss Arenas 
    */

    ifstream saveFile;
    saveFile.open("./Game-Saves/"+to_string(ID)+".txt");
    string input;

    // Load Player Data
    // Set non-object player variables (name, saveid, experiencepoints)
    getline(saveFile, input, '\t');
    player.setName(input);
    getline(saveFile, input, '\t');
    player.setSaveID(stoi(input));
    getline(saveFile, input, '\t');
    player.setExperiencePoints(stoi(input));

    // Set Player Stats
    Stats playerStats;
    getline(saveFile, input, '\t');
    playerStats.setLevel(stoi(input));
    getline(saveFile, input, '\t');
    playerStats.setHealthpoints(stod(input));
    getline(saveFile, input, '\t');
    playerStats.setDamage(stod(input));
    getline(saveFile, input, '\t');
    playerStats.setDefense(stod(input));
    player.setStats(playerStats);

    // Set Player Inventory
    Inventory playerInventory;
    Ability* abilities;
    int numAbilities;
    Shield* shields;
    int numShields;
    Potion* potions;
    int numPotions;
    AbilityList abilityList;
    ShieldList shieldList;
    PotionList potionList;

    // Set Abilities, Shields, and Potions based on the number specified and the names from the text file

    // Set Player Abilities
    getline(saveFile, input, '\t');
    numAbilities = stoi(input);
    abilities = new Ability[numAbilities];
    for (int i = 0; i < numAbilities; i++) {
        getline(saveFile, input, '\t');
        if (input == "Good Ol' Fist") {
            abilities[i] = abilityList(0, true);
        } else if (input == "Air Ability") {
            abilities[i] = abilityList(1, true);
        } else if (input == "Water Ability") {
            abilities[i] = abilityList(2, true);
        } else if (input == "Earth Ability") {
            abilities[i] = abilityList(3, true);
        } else if (input == "Fire Ability") {
            abilities[i] = abilityList(4, true);
        }
    }
    playerInventory.setAbilities(abilities);

    // Set Player Shields
    getline(saveFile, input, '\t');
    numShields = stoi(input);
    shields = new Shield[numShields];
    for (int i = 0; i < numShields; i++) {
        getline(saveFile, input, '\t');
        if (input == "Trusty-Shield") {
            shields[i] = shieldList(0, true);
        } else if (input == "Air Shield") {
            shields[i] = shieldList(1, true);
        } else if (input == "Water Shield") {
            shields[i] = shieldList(2, true);
        } else if (input == "Earth Shield") {
             shields[i] = shieldList(3, true);
        } else if (input == "Fire Shield") {
            shields[i] = shieldList(4, true);
        }
    }
    playerInventory.setShields(shields);

    // Set Player Potions
    getline(saveFile, input, '\t');
    numPotions = stoi(input);
    potions = new Potion[numPotions];
    for (int i = 0; i < numPotions; i++) {
        getline(saveFile, input, '\t');
        if (input == "Healing Potion") {
            //potions[i] = potionList(0);
        } else if (input == "Strength Potion") {
            //potions[i] = potionList(1);
        } else if (input == "Defense Potion") {
            //potions[i] = potionList(2);
        }
    }
    playerInventory.setPotions(potions);
    
    // Set balance, then set completed inventory
    getline(saveFile, input, '\t');
    int balance = stoi(input);
    playerInventory.setBalance(balance);
    player.setInventory(playerInventory);
    
    // Load Armory Data
    Ability* shopAbilities = new Ability[1];
    Shield* shopShields = new Shield[1];
    Potion* shopPotions = new Potion[2];

    // Shop Abilities
    getline(saveFile, input, '\t');
    numAbilities = stoi(input);
    for (int i = 0; i < numAbilities; i++) {
        getline(saveFile, input, '\t');
        if (input == "Air Ability") {
            shopAbilities[i] = abilityList(1, true);
        } else if (input == "Water Ability") {
            shopAbilities[i] = abilityList(2, true);
        } else if (input == "Earth Ability") {
            shopAbilities[i] = abilityList(3, true);
        } else if (input == "Fire Ability") {
            shopAbilities[i] = abilityList(4, true);
        }
    }
    armory.setAbilities(shopAbilities);
    armory.setNumAbilities(numAbilities);

    // Shop Shields
    getline(saveFile, input, '\t');
    numShields = stoi(input);
    for (int i = 0; i < numShields; i++) {
        getline(saveFile, input, '\t');
        if (input == "Air Shield") {
            shopShields[i] = shieldList(1, true);
        } else if (input == "Water Shield") {
            shopShields[i] = shieldList(2, true);
        } else if (input == "Earth Shield") {
            shopShields[i] = shieldList(3, true);
        } else if (input == "Fire Shield") {
            shopShields[i] = shieldList(4, true);
        }
    }
    armory.setShields(shopShields);
    armory.setNumShields(numShields);

    // Shop Potions
    getline(saveFile, input, '\t');
    numPotions = stoi(input);
    for (int i = 0; i < numPotions; i++) {
        getline(saveFile, input, '\t');
        if (input == "Healing Potion") {
            shopPotions[i] = potionList(0);
        } else if (input == "Strength Potion") {
            shopPotions[i] = potionList(1);
        } else if (input == "Defense Potion") {
            shopPotions[i] = potionList(2);
        }
    }
    armory.setPotions(shopPotions);
    armory.setNumPotions(numPotions);

    // Set Shield Repair Price
    int repairPrice = 750;
    armory.setRepairPrice(repairPrice);

    // Load Boss Arenas
    BossArenaList bossArenaList;
    getline(saveFile, input, '\t');
    int numBossArenas = stoi(input);
    for (int i = 0; i < numBossArenas; i++) {
        getline(saveFile, input, '\t');
        if (input == "Mallard's Tower") {
            bossArenas[i] = bossArenaList(0);
        } else if (input == "Honchman's Stronghold") {
            bossArenas[i] = bossArenaList(1);
        } else if (input == "King's Throne Room") {
            bossArenas[i] = bossArenaList(2);
        }
    }

    saveFile.close();
}

void Game::save()
{
    /* 
    List of Savable Objects:
        1. Player Data 
        2. Current Armory 
        3. Remaining Boss Arenas 
    */

    ofstream saveFile;
    saveFile.open("./Game-Saves/"+to_string(player.getSaveID())+".txt");
    string output;

    // Save Player Data
    
    // Save Name, Save ID, and Experience Points
    output = (player.getName() + "\t" + to_string(player.getSaveID()) + "\t" + to_string(player.getExperiencePoints()));
    saveFile << output << endl;

    // Save Stats
    Stats playerStats = player.getStats();
    output = (to_string(playerStats.getLevel()) + "\t" + to_string(playerStats.getHealthpoints()) + "\t" + to_string(playerStats.getDamage()) + "\t" + to_string(playerStats.getDamage()));
    saveFile << output << endl;
    
    // Save Inventory
    Inventory playerInventory = player.getInventory();
    Ability* playerAbilities = playerInventory.getAbilities();
    Shield* playerShields = playerInventory.getShields();
    Potion* playerPotions = playerInventory.getPotions();

    // To do this, we need to record the number of abilities, and then save the name for each one
    // We'll draw these names when we load the game to convert it to an object
    int numAbilities = playerInventory.getNumAbilities();
    int numShields = playerInventory.getNumShields();
    int numPotions = playerInventory.getNumPotions();

    output = (to_string(numAbilities) + "\t");

    for (int i = 0; i < numAbilities; i++) {
        output += playerAbilities[i].getName() + "\t";
    }

    output += (to_string(numShields) + "\t");
    for (int i = 0; i < numShields; i++) {
        output += playerShields[i].getName() + "\t";
    }

    output += (to_string(numPotions) + "\t");
    for (int i = 0; i < numPotions; i++) {
        output += playerShields[i].getName() + "\t";
    }

    output += to_string(playerInventory.getBalance()) + "\t";
    saveFile << output << endl;

    // Save Armory Data
    Ability* armoryAbilities;
    Shield* armoryShields;
    Potion* armoryPotions;

    numAbilities = armory.getNumAbilities();
    numShields = armory.getNumShields();
    numPotions = armory.getNumPotions();

    // Use the same idea to save armory items
    output = (to_string(numAbilities) + "\t");
    for (int i = 0; i < numAbilities; i++) {
        output += armoryAbilities[i].getName() + "\t";
    }

    output += (to_string(numShields) + "\t");
    for (int i = 0; i < numAbilities; i++) {
        output += armoryShields[i].getName() + "\t";
    }

    output += (to_string(numPotions) + "\t");
    for (int i = 0; i < numPotions; i++) {
        output += armoryPotions[i].getName() + "\t";
    }

    saveFile << output << endl;

    // Save Boss Arenas
    int numBossArenas = getNumBossArenas();

    // Use the same idea to save boss arenas
    // We'll load these in through a method that refers to the boss name
    output = (to_string(numBossArenas) + "\t");
    for (int i = 0; i < numBossArenas; i++) {
        output += bossArenas[i].getBossName() + "\t";
    }

    output += "end";
    saveFile << output << endl;

    saveFile.close();
}

void Game::exitGame()
{
    cout << "Saving your progress..." << endl;
    save();

    // Close Program
    exit(0);
}

void Game::displayCharacterSheet()
{
    // Generate and display a Cutscene

    // Ask if they want to view anything
}

void Game::displayMainMenu()
{
    // Show Main Menu Cutscene
    CutsceneList cutscenes;
    // cutscenes(2).display();

    // Main Decisions
    // Should not stop until the game has stopped or the player has completed the game
    bool proceed = false;

    while (proceed == false) {
        // Give user option to pick Armory, Arena, Boss Arena, Character Stats, Or Exit Game
        cout << "Where do you want to go?" << endl;
        string input;
        cin >> input;

        // Convert input to lowercase
        for (int i = 0; i < input.length(); i++) {
            input[i] = tolower(input[i]);
        }

        if (input == "a") {
            startArmory();
        } else if (input == "f") {
            startArenaBattle();
        } else if (input == "b") {
            startBossArenaBattle();
        } else if (input == "c") {
            displayCharacterSheet();
        } else if (input == "e") {
            bool confirm = false;
            while (confirm == false) {
                cout << "Are you sure you want to exit the game (y/n)?" << endl;
                cin >> input;
                
                // Convert input to lowercase
                for (int i = 0; i < input.length(); i++) {
                    input[i] = tolower(input[i]);
                }

                if (input == "y") {
                    exitGame();
                } else if (input == "n") {
                } else {
                    cout << "This was an invalid input. Please try again." << endl;
                }
            }
        } else {
            cout << "This was an invalid input. Please try again." << endl;
        }
    }
}

void Game::startArmory()
{
    // Display Armory Cutscene
    CutsceneList cutscenes;
    cutscenes(3).display();

    // Ask user for input option
    bool proceed = false;
    while (proceed == false)
    {
        string input;
        cout << "What do you want to do?" << endl;
        cout << "Buy an Item: Ability (A), Shield (S), Potion (P)" << endl;
        cout << "Repair your shields (R)" << endl;
        cout << "Exit the armory (E)" << endl;
        cin >> input;

        // Convert input to lowercase
        for (int i = 0; i < input.length(); i++) {
            input[i] = tolower(input[i]);
        }
        
        bool proceedArmory = false;
        while (proceedArmory == false) {
            Ability* armoryAbilities = armory.getAbilities();
            int totalArmoryAbilities = armory.getNumAbilities();
            Shield* armoryShields = armory.getShields();
            int totalArmoryShields = armory.getNumShields();
            Potion* armoryPotions = armory.getPotions();
            int totalArmoryPotions = armory.getNumPotions();

            if (input == "a") {
                // Ask user which ability to buy
                bool proceedPurchase = false;
                while (proceedPurchase == false) {
                    if (totalArmoryAbilities == 0) {
                        cout << "Sorry, there are no more abilities available." << endl;
                        proceedPurchase = true;
                    } else {
                        cout << "Would you like to purchase today's ability (y/n)?" << endl;
                        cout << "Today's ability: " << armory.getAbilities()[0].getName();
                        
                        string input;
                        cin >> input;

                        // Convert input to lowercase
                        for (int i = 0; i < input.length(); i++) {
                            input[i] = tolower(input[i]);
                        }

                        if (input == "y") {
                            // If the player does not have Sapphires, return them to the original armory decision
                            proceedPurchase = true;
                            if (player.getInventory().getBalance() < armory.getAbilities()[0].getPrice()) {
                                cout << "Sorry, you do not have enough Sapphires to purchase this." << endl;
                            } else {
                                // Deduct cost from player balance
                                int playerBalance = player.getInventory().getBalance();
                                int newPlayerBalance = newPlayerBalance - armory.getAbilities()[0].getPrice();
                                player.getInventory().setBalance(newPlayerBalance);

                                // Add Ability to inventory
                                Ability* playerAbilities = player.getInventory().getAbilities();
                                int totalAbilities = player.getInventory().getNumAbilities();

                                Ability newAbility = armory.buyAbility();
                                Ability* newAbilities = new Ability[totalAbilities+1];

                                for (int i = 0; i < totalAbilities+1; i++) {
                                    if (i != totalAbilities) {
                                        newAbilities[i] = playerAbilities[i];
                                    } else {
                                        newAbilities[i] = newAbility;
                                    }
                                }
                                player.getInventory().setNumAbilities(totalAbilities+1);
                                                                
                                // Deallocate and set new player abilities
                                delete[] playerAbilities;
                                playerAbilities = newAbilities;
                                player.getInventory().setAbilities(playerAbilities);
                            }
                        }
                    }
                }

            } else if (input == "s") {
                // Ask user which shield to buy
                bool proceedPurchase = false;
                while (proceedPurchase == false) {
                    if (totalArmoryShields == 0) {
                        cout << "Sorry, there are no more shields available." << endl;
                        proceedPurchase = true;
                    } else {
                        cout << "Would you like to purchase today's shields (y/n)?" << endl;
                        cout << "Todays's shield: " << armory.getShields()[0].getName();
                        
                        string input;
                        cin >> input;

                        // Convert input to lowercase
                        for (int i = 0; i < input.length(); i++) {
                            input[i] = tolower(input[i]);
                        }

                        if (input == "y") {
                            // If the player does not have Sapphires, return them to the original armory decision
                            proceedPurchase = true;
                            if (player.getInventory().getBalance() < armory.getShields()[0].getPrice()) {
                                cout << "Sorry, you do not have enough Sapphires to purchase this." << endl;
                            } else {
                                // Deduct cost from player balance
                                int playerBalance = player.getInventory().getBalance();
                                int newPlayerBalance = newPlayerBalance - armory.getShields()[0].getPrice();
                                player.getInventory().setBalance(newPlayerBalance);

                                // Add Shield to inventory
                                Shield* playerShields = player.getInventory().getShields();
                                int totalShields = player.getInventory().getNumShields();

                                Shield newShield = armory.buyShield();
                                Shield* newShields = new Shield[totalShields+1];

                                for (int i = 0; i < totalShields+1; i++) {
                                    if (i != totalShields) {
                                        newShields[i] = playerShields[i];
                                    } else {
                                        newShields[i] = newShield;
                                    }
                                }
                                player.getInventory().setNumShields(totalShields+1);
                                
                                // Deallocate and set new player shields
                                delete[] playerShields;
                                playerShields = newShields;
                                player.getInventory().setShields(playerShields);
                            }
                        }
                    }
                }
            } else if (input == "p") {
                bool proceed = false;
                while (proceed == false) {
                    cout << "Which potion would you like to buy (please input specified integer)?" << endl;
                    for (int i = 0; i < totalArmoryPotions; i++) {
                        cout << "Potion [" << to_string(i) << "]: " << armoryPotions[i].getName();
                    }

                    cin >> input;

                    // Check if potion decision is valid
                    if (stoi(input) >= 0 && stoi(input) < totalArmoryPotions) {
                        if (player.getInventory().getBalance() < armoryPotions[stoi(input)].getPrice()) {
                            cout << "Sorry, you do not have enough Sapphires to purchase this potion." << endl;
                        } else {
                            proceed = true;
                            // Deduct cost from player balance and add potion to player inventory
                            int playerBalance = player.getInventory().getBalance();
                            int newPlayerBalance = newPlayerBalance - armoryPotions[stoi(input)].getPrice();
                            player.getInventory().setBalance(newPlayerBalance);

                            Potion* playerPotions = player.getInventory().getPotions();
                            int totalPotions = player.getInventory().getNumPotions();
                            Potion newPotion = armory.buyPotion(stoi(input));
                            Potion* newPotions = new Potion[totalPotions+1];

                            for (int i = 0; i < totalArmoryPotions+1; i++) {
                                if (i != totalArmoryPotions) {
                                    newPotions[i] = playerPotions[i];
                                } else {
                                    newPotions[i] = newPotion;
                                }
                            }
                            player.getInventory().setNumPotions(totalPotions+1);

                            // Deallocate and set new player potions
                            delete[] playerPotions;
                            playerPotions = newPotions;
                            player.getInventory().setPotions(playerPotions);
                        }
                    } else {
                        cout << "This was an invalid input. Please try again." << endl;
                    }
                }
            } else if (input == "r") {
                bool proceed = false;
                while (proceed == false) {
                    // Confirm that the user wants to repair shields
                    cout << "Are you sure you want to repair your shields (y/n)?" << endl;
                    cin >> input;

                    // Convert input to lowercase
                    for (int i = 0; i < input.length(); i++) {
                        input[i] = tolower(input[i]);
                    }

                    if (input == "y") {
                        proceed = true;
                        if (player.getInventory().getBalance() < armory.getRepairPrice()) {
                            cout << "Sorry. You do not have Sapphires to repair your shield." << endl;
                        } else {
                            // Deduct cost from player balance and repair shields
                            int playerBalance = player.getInventory().getBalance();
                            int newPlayerBalance = newPlayerBalance - armory.getRepairPrice();
                            player.getInventory().setBalance(newPlayerBalance);
                            player.getInventory().setShields(armory.repairShields(player));
                        }
                    } else if (input == "n") {
                        proceed = true;
                    } else {
                        cout << "This was an invalid input. Please try again." << endl;
                    }
                }
            } else if (input == "e") {
                proceedArmory = true;
            } else {
                cout << "This input was invalid. Please try again." << endl;
            }
        }
    }

}

void Game::startArenaBattle()
{
    // Run Arena here using Arena Methods
    Arena arena;
    arena.setFightingPlayer(player);
    bool isInArena = true;

    // Keep fighting until the player decides to leave to leave or is defeated
    while (isInArena == true) {
        arena.generateEnemy();
        isInArena = arena.iterateTurns();
    }

    // Get the player with updated stats once the player is done fighting
    player = arena.leaveArena();

    // Generate a new armory before leaving
    armory.generateArmory(player);
}

void Game::startBossArenaBattle()
{
    // Same Ordeal with Armory Methods
    // However, we remove the current Boss Arena once it is finished
    BossArena currentBossFight = bossArenas[0];
    int totalBossArenas = getNumBossArenas();
    currentBossFight.setFightingPlayer(player);
    
    bool isInArena = true;
    Enemy* enemies = currentBossFight.getEnemies();
    int totalEnemies = currentBossFight.getNumEnemies();

    cout << "Now fighting in... " << currentBossFight.getBossName() << "!" << endl;

    // Keep fighting until the player is defeated or the boss arena is out of enemies
    while (isInArena == true) {
        for (int i = 0; i < totalEnemies; i++) {
            bool victory;
            currentBossFight.setEnemy(enemies[i]);
            victory = currentBossFight.iterateTurns();
            
            // Break loop if player is defeated
            if (victory == false) {
                player = currentBossFight.leaveArena();
                
                // Generate a new armory before leaving
                armory.generateArmory(player);
                break;
            }

            // Break loop if player has defeated all enemies
            // Remove this boss arena from the list
            if (isInArena == true || i == (totalEnemies - 1)) {
                cout << "Congradulations, " << player.getName() << "! You defeated " << currentBossFight.getBossName() << "!" << endl;
                player = currentBossFight.leaveArena();
                
                // Generate a new armory before leaving
                armory.generateArmory(player);

                // Remove Boss Arena
                BossArena* newBossArenas = new BossArena[totalBossArenas-1];
                copy(bossArenas, bossArenas, newBossArenas);
                copy(bossArenas+1, bossArenas+totalBossArenas, newBossArenas);
                delete[] bossArenas;
                bossArenas = newBossArenas;
                totalBossArenas--;
            }
        }
    }
    
    save();

    // Check if the game is out of boss arenas
    // If so, go to the final cutscene and end the game.
    if (totalBossArenas == 0) {
        // Play Final Cutscenes

        cout << "Congradulations, " << player.getName() << "! You win the game!" << endl;
        exit(0);
    }
}