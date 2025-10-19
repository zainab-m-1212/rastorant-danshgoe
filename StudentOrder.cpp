#include "StudentOrder.h"
#include <iostream>

using namespace std;

StudentOrder::StudentOrder(int orderNum, string stdId, string fName, string lName) {
    orderNumber = orderNum;
    studentId = stdId;
    firstName = fName;
    lastName = lName;
    status = IN_PROGRESS;
    itemsHead = nullptr;
    next = nullptr;
}

StudentOrder::~StudentOrder() {
    OrderItem* current = itemsHead;
    while (current != nullptr) {
        OrderItem* nextItem = current->next;
        delete current;
        current = nextItem;
    }
}

void StudentOrder::addItem(MenuItem* menuItem, int quantity) {
    OrderItem* newItem = new OrderItem(menuItem, quantity);

    if (itemsHead == nullptr) {
        itemsHead = newItem;
    } else {
        OrderItem* current = itemsHead;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newItem;
    }
}

bool StudentOrder::removeItem(int menuItemId) {
    OrderItem* current = itemsHead;
    OrderItem* prev = nullptr;

    while (current != nullptr) {
        if (current->item->id == menuItemId) {
            if (prev == nullptr) {
                itemsHead = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

double StudentOrder::calculateTotal() {
    double total = 0.0;
    OrderItem* current = itemsHead;
    while (current != nullptr) {
        total += current->item->price * current->quantity;
        current = current->next;
    }
    return total;
}

bool StudentOrder::hasItems() {
    return itemsHead != nullptr;
}

void StudentOrder::displayOrder() {
    cout << "number order " << orderNumber << " " << endl;
    cout << "student " << firstName << " " << lastName  << studentId  << endl;

    cout << "status ";
    switch (status) {
        case IN_PROGRESS: cout << "doing"; break;
        case DELIVERED: cout << "delivered"; break;
        case CANCELLED: cout << "caceled"; break;
    }
    cout << endl;

    cout << "items oredr" << endl;
    OrderItem* current = itemsHead;

    if (current == nullptr) {
        cout << " no item regisr" << endl;
    } else {
        while (current != nullptr) {
            current->display();
            current = current->next;
        }
    }

    cout << "total  " << calculateTotal() << "money" << endl;
    cout << "   " << endl;
}