#ifndef ORDERITEM_H
#define ORDERITEM_H

#include "MenuItem.h"

class OrderItem {
public:
    MenuItem* item;
    int quantity;
    OrderItem* next;

    OrderItem(MenuItem* menuItem, int qty);
    void  display () const;
};

#endif