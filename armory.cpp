#include "armory.h"

// Constructors / Destructors
Armory::Armory()
{
}

Armory::~Armory()
{
}

Armory::Armory(Ability* abilities, int numAbilities, Shield* shields, int numShields, Potion* potions, int numPotions, int repairPrice)
{
    this->abilities = abilities;
    this->numAbilities = numAbilities;
    this->shields = shields;
    this->numShields = numShields;
    this->potions = potions;
    this->numPotions = numPotions;
    this->repairPrice = repairPrice;
}

// Getters
Ability* Armory::getAbilities()
{
    return abilities;
}

int Armory::getNumAbilities()
{
    return numAbilities;
}

Shield* Armory::getShields()
{
    return shields;
}

int Armory::getNumShields()
{
    return numShields;
}

Potion* Armory::getPotions()
{
    return potions;
}

int Armory::getNumPotions()
{
    return numPotions;
}

int Armory::getRepairPrice()
{
    return repairPrice;
}

// Setters
void Armory::setAbilities(Ability* abilities)
{
    this->abilities = abilities;
}

void Armory::setNumAbilities(int numAbilities)
{
    this->numAbilities = numAbilities;
}

void Armory::setShields(Shield* shields)
{
    this->shields = shields;
}

void Armory::setNumShields(int numShields)
{
    this->numShields = numShields;
}

void Armory::setPotions(Potion* potions)
{
    this->potions = potions;
}

void Armory::setNumPotions(int numPotions)
{
    this->numPotions = numPotions;
}

void Armory::setRepairPrice(int repairPrice)
{
    this->repairPrice = repairPrice;
}

// Custom Functions
void Armory::generateArmory(Player player)
{
    // Determine what abilities and shields the player has
    // If the player already has them, do not put them in the shop
    Inventory model = player.getInventory();
    Ability* playerAbilities = model.getAbilities();
    Shield* playerShields = model.getShields();

    // Call Item Lists (Functors)
    AbilityList abilityList;
    ShieldList shieldList;
    PotionList potionList;

    // All available abilities
    Ability* shopAbilities;

    setNumAbilities(4);
    shopAbilities = new Ability[numAbilities];

    // Have every type except normal available
    shopAbilities[0] = abilityList(1, true);
    shopAbilities[1] = abilityList(2, true);
    shopAbilities[2] = abilityList(3, true);
    shopAbilities[3] = abilityList(4, true);

    // All available shields
    Shield* shopShields;

    setNumShields(4);
    shopShields = new Shield[numShields];

    // Have every type except normal available
    shopShields[0] = shieldList(1, true);
    shopShields[1] = shieldList(2, true);
    shopShields[2] = shieldList(3, true);
    shopShields[3] = shieldList(4, true);

    // All available potions
    Potion* shopPotions;
    setNumPotions(3);
    shopPotions = new Potion[numPotions];

    shopPotions[0] = potionList(0);
    shopPotions[1] = potionList(1);
    shopPotions[2] = potionList(2);

    // Check if the player has any of the same abilities
    // If so, remove them from the armory
    int totalPlayerAbilities = player.getInventory().getNumAbilities();
    for (int i = 0; i < numAbilities; i++) {
        for (int j = 0; j < totalPlayerAbilities; j++)
        {
            if (shopAbilities[i] == playerAbilities[j])
            {
                Ability* newAbilities = new Ability[numAbilities-1];
                copy(shopAbilities, shopAbilities+i, newAbilities);
                copy(shopAbilities+i+1, shopAbilities+numAbilities, newAbilities+i);
                delete[] shopAbilities;
                shopAbilities = newAbilities;
                numAbilities--;
            }
        }
    }

    // Check if the player has any of the same shields
    // If so, remove them from the armory
    int totalPlayerShields = player.getInventory().getNumShields();
    for (int i = 0; i < numShields; i++) {
        for (int j = 0; j < totalPlayerShields; j++)
        {
            if (shopShields[i] == playerShields[j])
            {
                Shield* newShields = new Shield[numShields-1];
                copy(shopShields, shopShields+i, newShields);
                copy(shopShields+i+1, shopShields+numShields, newShields+i);
                delete[] shopShields;
                shopShields = newShields;
                numShields--;

            }
        }
    }

    // Decide which items should go into the shop randomly
    // If there are no available abilities or shields, none should be available
    abilities = new Ability[1];
    shields = new Shield[1];
    potions = new Potion[2];

    int randomAbility;
    int randomShield;

    // Decide Abilities if any are left
    if (numAbilities == 0) {
        randomAbility = -1;
    } else {
        randomAbility = rand()%(numAbilities+1) + 1;
    }

    // Decide Shields if any are left
    if (numShields == 0) {
        randomShield = -1;
    } else {
        randomShield = rand()%(numShields+1) + 1;
    }

    // Decide Potions
    // Two of the three potions are always available
    int randomPotion1 = rand()%3;
    int randomPotion2 = rand()%3;
    while (randomPotion1 == randomPotion2)
    {
        randomPotion1 = rand()%3;
    }

    // Set Available Abilities, Shields, and Potions
    if (randomAbility == -1) {
    } else {
        abilities[0] = shopAbilities[randomAbility];
    }

    if (randomShield == -1) {
    } else {
        shields[0] = shopShields[randomShield];
    }

    potions[0] = shopPotions[randomPotion1];
    potions[1] = shopPotions[randomPotion2];

    // Set Shield Repair Price
    repairPrice = 750;
}

Ability Armory::buyAbility()
{
    // Remove the ability from the armory and return the ability
    int totalAbilities = numAbilities;
    Ability returnAbility = abilities[0];

    for (int i = 0; i < totalAbilities; i++) {
        Ability* newAbilities = new Ability[totalAbilities-1];
        copy(abilities, abilities+i, newAbilities);
        copy(abilities+i+1, abilities+totalAbilities, newAbilities+i);
        delete[] abilities;
        abilities = newAbilities;
        totalAbilities--;
    }

    return abilities[0];
}

Shield Armory::buyShield()
{
    // Remove the shield from the armory and return the shield
    int totalShields = numShields;
    Shield returnShield = shields[0];

    for (int i = 0; i < totalShields; i++) {
        Shield* newShields = new Shield[totalShields-1];
        copy(shields, shields+i, newShields);
        copy(shields+i+1, shields+totalShields, newShields+i);
        delete[] shields;
        shields = newShields;
        totalShields--;
    }
    
    return returnShield;
}

Potion Armory::buyPotion(int potionNum)
{
    // Return the selected potion
    return potions[potionNum];
}

Shield* Armory::repairShields(Player player)
{
    // Set the durability to 20 and usability to true for all of the player's shields
    // Ignore the normal shield to ensure the player always has a shield to use
    Shield* playerShields = player.getInventory().getShields();
    int totalPlayerShields = player.getInventory().getNumShields();

    for (int i = 0; i < totalPlayerShields; i++) {
        if (playerShields[i].getElement() == normal) {
        } else {
            playerShields[i].setDurability(20);
            playerShields[i].setUsability(true);
        }
    }

    // Return the repaired shields
    return playerShields;
}