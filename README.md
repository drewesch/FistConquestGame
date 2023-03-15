# Fist Conquest - The Game
A self-developed C++ game based in the UNIX CLI.


## Game Overview
Fist Conquest is an text-based arena-style game, where the only weapon you have to fight an enemy is, well, a fist!

After creating your player, fight in a text-based arena and defeat enemies to gain currency and unlock new elements for your first. Unlock different elements to fight enemies with fists of fire, electricity, and more! Tackle tougher enemies with shields and potions, and level up by gaining experience in the arena.

Once the player is ready for a challenge, head to a boss arena to take on a boss! Fight up to three mini bosses and one final boss to complete the game!

## Debugging the Save File
Saved information will be stored within the "save.txt" file. Save file information is separated into three distinct sections:
- Section #1: Player Information - records the Player Name, Save ID, Stats, Inventory, Current Player Balance, and the current experience amount.
- Section #2: Armory Information - stores information about the store. It stores a generated list of abilities that the player has not currently obtained. Moreover, the types of available items will be categorized under Abilities, Shields, Potions. Finally, it stores what the current repair price is for the shop.
- Section #3: Boss Arenas Information - Stores which bosses the player needs to defeat in order to win the game. If there are none left, the game will not be allowed to run.
