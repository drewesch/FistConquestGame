#include "shieldList.h"

// Function Object (Functor)
Shield ShieldList::operator()(int num, bool isPlayer)
{
    // Returns an shield based on input number and if it is a player or not
    // Players and enemies may have different names and descriptions for items
    // Uniquely for players vs. enemies, enemies will have "infinite" durability, while player shields can break
    if (num == 0) {
        // Normal
        Shield normalShield;

        if (isPlayer == true) {
            normalShield.setName("Trusty-Shield");
            normalShield.setDescription("Best shield in the business! Made by the Trusties!");
            // Only this shield will have "infinite" durability
            // This is to ensure the game does not break
            normalShield.setDurability(INT16_MAX);
        } else {
            normalShield.setName("Normal Shield");
            normalShield.setDescription("I wonder who made this shield... hmm...");
            normalShield.setDurability(INT16_MAX);
        }

        normalShield.setPrice(2000);
        normalShield.setElement(normal);
        normalShield.setParryPercentage(10.0);
        normalShield.setReducePercentage(30.0);
        normalShield.setReduceAmount(50.0);
        normalShield.setUsability(true);
        return normalShield;
    } else if (num == 1) {
        // Air
        Shield airShield;

        if (isPlayer == true) {
            airShield.setDurability(20);
        } else {
            airShield.setDurability(INT16_MAX);
        }

        airShield.setName("Air Shield");
        airShield.setDescription("Sir Trusty designed this shield to withstand the worst windstorms! \nDefends Against: Air");
        airShield.setPrice(2000);
        airShield.setElement(air);
        airShield.setParryPercentage(10.0);
        airShield.setReducePercentage(30.0);
        airShield.setReduceAmount(50.0);
        airShield.setUsability(true);
        return airShield;
    } else if (num == 2) {
        // Water
        Shield waterShield;

        if (isPlayer == true) {
            waterShield.setDurability(20);
        } else {
            waterShield.setDurability(INT16_MAX);                
        }

        waterShield.setName("Water Shield");
        waterShield.setDescription("Sir Trusty made this shield from a super dense and rubberized paste he had in his house! \nDefends Against: Water");
        waterShield.setPrice(2000);
        waterShield.setElement(water);
        waterShield.setParryPercentage(10.0);
        waterShield.setReducePercentage(30.0);
        waterShield.setReduceAmount(50.0);
        waterShield.setUsability(true);
        return waterShield;
    } else if (num == 3) {
        // Earth
        Shield earthShield;

        if (isPlayer == true) {
            earthShield.setDurability(20);                
        } else {
            earthShield.setDurability(INT16_MAX);                  
        }


        earthShield.setName("Earth Shield");
        earthShield.setDescription("Sir Trusty gives a 100% guarantee you can stand your ground with this shield or your money back! \nDefends Against: Earth");
        earthShield.setPrice(2000);
        earthShield.setElement(earth);
        earthShield.setParryPercentage(10.0);
        earthShield.setReducePercentage(30.0);
        earthShield.setReduceAmount(50.0);
        earthShield.setUsability(true);
        return earthShield;
    } else if (num == 4) {
        // Fire
        Shield fireShield;

        if (isPlayer == true) {
            fireShield.setDurability(20);                
        } else {
            fireShield.setDurability(INT16_MAX);                  
        }

        fireShield.setName("Fire Shield");
        fireShield.setDescription("Sir Trusty got his inspiration for this shield design after visiting the top of a volcano! \nDefends Against: Fire");
        fireShield.setPrice(2000);
        fireShield.setElement(fire);
        fireShield.setParryPercentage(10.0);
        fireShield.setReducePercentage(30.0);
        fireShield.setReduceAmount(50.0);
        fireShield.setUsability(true);
        return fireShield;
    }
}