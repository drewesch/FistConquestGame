#include "potionList.h"

// Function Object (Functor)
Potion PotionList::operator()(int num)
{
    if (num == 0) {
        Potion healingPotion;
        healingPotion.setName("Healing Potion");
        healingPotion.setDescription("Gets you out of a tight spot! Heal 50% of your health! Note: Takes up your whole turn and immediately takes effect.");
        healingPotion.setPrice(100);
        healingPotion.setType(healing);
        healingPotion.setStatIncreasePercentage(150);
        healingPotion.setTurnsInEffect(1);
        return healingPotion;
    } else if (num == 1) {
        Potion strengthPotion;
        strengthPotion.setName("Strength Potion");
        strengthPotion.setDescription("Level out the playing field! Increase your damage by 50%! Note: Takes up your whole turn and lasts three turns.");
        strengthPotion.setPrice(150);
        strengthPotion.setType(strength);
        strengthPotion.setStatIncreasePercentage(150);
        strengthPotion.setTurnsInEffect(4);
        return strengthPotion;
    } else if (num == 2) {
        Potion defensePotion;
        defensePotion.setName("Defense Potion");
        defensePotion.setDescription("Level out the playing field! Increase your defense by 50%! Note: Takes up your whole turn and lasts three turns.");
        defensePotion.setPrice(150);
        defensePotion.setType(defense);
        defensePotion.setStatIncreasePercentage(150);
        defensePotion.setTurnsInEffect(4);
        return defensePotion;
    }
}