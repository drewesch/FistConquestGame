#ifndef CUTSCENE_H
#define CUTSCENE_H

#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

class Cutscene
{
    private:
    string* screens;
    int length;
    int timeInterval;
    
    public:
    // Constructors / Destructors
    Cutscene();
    ~Cutscene();
    Cutscene(string*, int, int);

    // Getters
    string* getScreens();
    int getLength();
    int getTimeInterval();

    // Setters
    void setScreens(string*);
    void setLength(int);
    void setTimeInterval(int);

    // Custom Functions
    void create(string, int, int);
    void display();
};

#endif