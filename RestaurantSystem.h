#ifndef RESTAURANTSYSTEM_H
#define RESTAURANTSYSTEM_H

#include "StudentOrder.h"
#include <fstream>
#include <string>

using namespace std;

class RestaurantSystem {
private:
    MenuItem* menuHead;
    StudentOrder* ordersHead;
    int nextOrderNumber;
    int nextMenuItemId;

    void clearAllData();
    void initializeSampleMenu();
    void addItemsToOrder(StudentOrder* order);
    MenuItem* findMenuItemById(int id);
    StudentOrder* findOrderByNumber(int orderNumber);

public:
    RestaurantSystem();
    ~RestaurantSystem();

    void addMenuItem(string name, double price, string category);
    void displayMenu();
    void createNewOrder();
    void deliverOrder();
    void cancelOrder();
    void changeOrder();
    void reviewAllOrders();
    void reviewOrdersByStatus(OrderStatus status);
    void saveToFile();
   // void loadFromFile();
};

#endif