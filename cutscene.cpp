#include "cutscene.h"

// Constructors / Destructors
Cutscene::Cutscene()
{
}

Cutscene::~Cutscene()
{
}

Cutscene::Cutscene(string* screens, int length, int timeInterval)
{
    this->screens = screens;
    this->length = length;
    this->timeInterval = timeInterval;
}

// Getters
string* Cutscene::getScreens()
{
    return screens;
}

int Cutscene::getLength()
{
    return length;
}

int Cutscene::getTimeInterval()
{
    return timeInterval;
}

// Setters
void Cutscene::setScreens(string* screens)
{
    this->screens = screens;
}

void Cutscene::setLength(int length)
{
    this->length = length;
}

void Cutscene::setTimeInterval(int timeInterval)
{
    this->timeInterval = timeInterval;
}

// Custom Functions

void Cutscene::create(string file, int length, int timeInterval)
{
    // Generate Start Menu
    // Pre-defined variables
    string* screens;
    ifstream menu;
    menu.open(file);
    
    // Use a file with start menu strings & display a cutscene
    screens = new string[length];

    for (int i = 0; i < length; i++)
    {
        string input;
        getline(menu, input, '\t') >> input;
        screens[i] = input;
    }
    menu.close();

    setScreens(screens);
    setLength(length);
    setTimeInterval(timeInterval);
}

void Cutscene::display()
{
    // Display all lines in the sequence, then pause
    for (int i = 0; i < length; i++)
    {
        cout << screens[i] << endl;
    }
    this_thread::sleep_for(chrono::milliseconds(timeInterval*1000));
}