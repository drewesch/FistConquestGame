#include "abilityList.h"

// Function Object (Functor)
Ability AbilityList::operator()(int num, bool isPlayer)
{
    // Returns an ability based on input number and if it is a player or not
    // Players and enemies should have different names and descriptions for the same items
    if (num == 0) {
        // Normal
        Ability normalAbility;

        if (isPlayer == true) {
            normalAbility.setName("Good Ol' Fist");
            normalAbility.setDescription("Fight them guards with nothing but brute force!");
        } else {
            normalAbility.setName("Standard Sword");
            normalAbility.setDescription("Fight them guards with nothing but brute force!");
        }

        normalAbility.setPrice(2000);
        normalAbility.setElement(normal);
        return normalAbility;
    } else if (num == 1) {
        // Air
        Ability airAbility;

        if (isPlayer == true) {
            airAbility.setName("Air Fist");
            airAbility.setDescription("Blow them away with your epic fist!\nEffective Against: Water");
        } else {
            airAbility.setName("Air Sword");
            airAbility.setDescription("Blow them away with your epic fist!\nEffective Against: Water");
        }

        airAbility.setPrice(2000);
        airAbility.setElement(air);
        return airAbility;
    } else if (num == 2) {
        // Water
        Ability waterAbility;

        if (isPlayer == true) {
            waterAbility.setName("Water Fist");
            waterAbility.setDescription("Better than the world's largest water balloon!\nEffective Against: Earth");   
        } else {
            waterAbility.setName("Water Sword");
            waterAbility.setDescription("Better than the world's largest water balloon!\nEffective Against: Earth");
        }

        waterAbility.setPrice(2000);
        waterAbility.setElement(water);
        return waterAbility;
    } else if (num == 3) {
        // Earth
        Ability earthAbility;

        if (isPlayer == true) {
            earthAbility.setName("Earth Fist");
            earthAbility.setDescription("Cause an earth-shattering rock-alanche!\nEffective Against: Fire");
        } else {
            earthAbility.setName("Earth Sword");
            earthAbility.setDescription("Cause an earth-shattering rock-alanche!\nEffective Against: Fire");
        }

        earthAbility.setPrice(2000);
        earthAbility.setElement(earth);
        return earthAbility;
    } else if (num == 4) {
        // Fire
        Ability fireAbility;

        if (isPlayer == true) {
            fireAbility.setName("Fire Fist");
            fireAbility.setDescription("Ignite them with a fiery swing of your fist!\nEffective Against: Air");
        } else {
            fireAbility.setName("Fire Sword");
            fireAbility.setDescription("Ignite them with a fiery swing of your fist!\nEffective Against: Air");
        }

        fireAbility.setPrice(2000);
        fireAbility.setElement(fire);
        return fireAbility;
    }
}