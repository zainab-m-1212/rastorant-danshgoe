#include "OrderItem.h"
#include <iostream>

using namespace std;

OrderItem::OrderItem(MenuItem* menuItem, int qty) : item(menuItem), quantity(qty), next(nullptr) {}

void  OrderItem::display () const {
    cout << "  " << item->name << " (number " << quantity
         << " price " << item->price
         << " total " << (item->price * quantity) << "money)" << endl;
}