#ifndef MENUITEM_H
#define MENUITEM_H
#include <iostream>
using namespace std;

#include <string>
using namespace std;

class MenuItem {
public:
    int id;
    string name;
    double price;
    string category;
    MenuItem* next;

    MenuItem();
    MenuItem(int itemId, string itemName, double itemPrice, string itemCategory);
    void display();
};

#endif