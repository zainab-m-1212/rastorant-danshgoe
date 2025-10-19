#include "MenuItem.h"

MenuItem::MenuItem() : id(0), name(""), price(0.0), category(""), next(nullptr) {}

MenuItem::MenuItem(int itemId, string itemName, double itemPrice, string itemCategory) {
    id = itemId;
    name = itemName;
    price = itemPrice;
    category = itemCategory;
    next = nullptr;
}

void MenuItem::display() {
    cout << id << " " << name << "  " << price << " money (" << category << ")" << endl;
}