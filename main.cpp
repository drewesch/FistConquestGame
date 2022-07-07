#include <iostream>
#include <fstream>
#include <string>
#include "game.h"
#include "cutscene.h"

int main() {
    srand(time(0));
    cout << "Loading game..." << endl;
    cout << "Note: Please make sure your console screen is widened to be able to view the game." << endl;
    Game newGame;
    
    newGame.startGame();
    newGame.displayMainMenu();
}