#ifndef STUDENTORDER_H
#define STUDENTORDER_H

#include "OrderItem.h"
#include <string>

using namespace std;

enum OrderStatus {
    IN_PROGRESS,
    DELIVERED,
    CANCELLED
};

class StudentOrder {
public:
    int orderNumber;
    string studentId;
    string firstName;
    string lastName;
    OrderStatus status;
    OrderItem* itemsHead;
    StudentOrder* next;

    StudentOrder(int orderNum, string stdId, string fName, string lName);
    ~StudentOrder();

    void addItem(MenuItem* menuItem, int quantity);
    bool removeItem(int menuItemId);
    double calculateTotal();
    bool hasItems();
    void displayOrder();
};

#endif