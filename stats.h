#ifndef STATS_H
#define STATS_H

#include <string>
#include <iostream>

using namespace std;

class Stats
{
    private:
    int level;
    double damage;
    double defense;
    double healthpoints;
    
    public:
    // Constructors / Destructors
    Stats();
    ~Stats();
    Stats(int, double, double, double);

    // Getters
    int getLevel();
    double getDamage();
    double getDefense();
    double getHealthpoints();

    // Setters
    void setLevel(int);
    void setDamage(double);
    void setDefense(double);
    void setHealthpoints(double);
};

#endif