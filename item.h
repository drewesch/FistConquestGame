#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

using namespace std;

class Item
{
    private:
    string name;
    string description;
    int price;
    
    public:
    // Constructors / Destructors
    Item();
    ~Item();
    Item(string, string, int);

    // Getters
    string getName();
    string getDescription();
    int getPrice();

    // Setters
    void setName(string);
    void setDescription(string);
    void setPrice(int);

    // Overloaded Operators
    bool operator==(Item &i2);
};

#endif