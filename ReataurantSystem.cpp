#include "RestaurantSystem.h"
#include <iostream>


using namespace std;

RestaurantSystem::RestaurantSystem() {
    menuHead = nullptr;
    ordersHead = nullptr;
    nextOrderNumber = 1;
    nextMenuItemId = 1;
    initializeSampleMenu();
}

RestaurantSystem::~RestaurantSystem() {
    clearAllData();
}

void RestaurantSystem::clearAllData() {
    MenuItem* currentMenu = menuHead;
    while (currentMenu != nullptr) {
        MenuItem* nextMenu = currentMenu->next;
        delete currentMenu;
        currentMenu = nextMenu;
    }
    menuHead = nullptr;

    StudentOrder* currentOrder = ordersHead;
    while (currentOrder != nullptr) {
        StudentOrder* nextOrder = currentOrder->next;
        delete currentOrder;
        currentOrder = nextOrder;
    }
    ordersHead = nullptr;
}

 void RestaurantSystem::initializeSampleMenu() {
    addMenuItem("chalaw kabab kobida", 180000, "food");
    addMenuItem("chlaw joja", 150000, "food");
    addMenuItem("qorma sabzi", 120000, "food");
    addMenuItem("zereshk", 130000, "food");

    addMenuItem("salad shirazi", 45000, "appetizer");
    addMenuItem("mast o khiar", 35000, "appetizer");
    addMenuItem("nan paneer sabzi", 60000, "appetizer");
    addMenuItem("آash reshta", 80000, "appetizer");

    addMenuItem("noshaba", 25000, "drink");
    addMenuItem("dogh", 20000, "drink");
    addMenuItem("Ab madani", 15000, "drink");
    addMenuItem("chai", 10000, "drink");
}

void RestaurantSystem::addMenuItem(string name, double price, string category) {
    MenuItem* newItem = new MenuItem(nextMenuItemId++, name, price, category);

    if (menuHead == nullptr) {
        menuHead = newItem;
    } else {
        MenuItem* current = menuHead;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newItem;
    }
}



void RestaurantSystem::displayMenu() {
    cout << "\n restaurant menu " << endl;
    if (menuHead == nullptr) {
        cout << "  menu is empty!" << endl;
        return;
    }

    MenuItem* current = menuHead;
    while (current != nullptr) {
        current->display();
        current = current->next;
    }
}

void RestaurantSystem::createNewOrder() {
    string studentId, firstName, lastName;

    cout << "\n new order " << endl;
    cout << " id: ";
    cin >> studentId;
    cout << "name: ";
    cin >> firstName;
    cout << "family name : ";
    cin >> lastName;

    StudentOrder* newOrder = new StudentOrder(nextOrderNumber++, studentId, firstName, lastName);
    newOrder->next = ordersHead;
    ordersHead = newOrder;

    cout << " order with number  " << newOrder->orderNumber << " saved ." << endl;
    addItemsToOrder(newOrder);
}

void RestaurantSystem::addItemsToOrder(StudentOrder* order) {
    char continueAdding;

    do {
        displayMenu();
        int itemId, quantity;

        cout << " id selected: ";
        cin >> itemId;
        cout << "number: ";
        cin >> quantity;

        MenuItem* item = findMenuItemById(itemId);
        if (item != nullptr) {
            order->addItem(item, quantity);
            cout << item->name << "added to order ." << endl;
        } else {
            cout << "not found!" << endl;
        }

        cout << "آadd other item؟ (y/n): ";
        cin >> continueAdding;

    } while (continueAdding == 'y' || continueAdding == 'Y');
}

MenuItem* RestaurantSystem::findMenuItemById(int id) {
    MenuItem* current = menuHead;
    while (current != nullptr) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

StudentOrder* RestaurantSystem::findOrderByNumber(int orderNumber) {
    StudentOrder* current = ordersHead;
    while (current != nullptr) {
        if (current->orderNumber == orderNumber) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void RestaurantSystem::deliverOrder() {
    int orderNumber;
    cout << "number order for delivery ";
    cin >> orderNumber;

    StudentOrder* order = findOrderByNumber(orderNumber);
    if (order != nullptr) {
        if (order->status == CANCELLED) {
            cout << "order canceled" << endl;
        } else {
            order->status = DELIVERED;
            cout << "order " << orderNumber << " delivered." << endl;
        }
    } else {
        cout << "number order is wrong" << endl;
    }
}

void RestaurantSystem::cancelOrder() {
    int orderNumber;
    cout << "number order for cencaled ";
    cin >> orderNumber;

    StudentOrder* order = findOrderByNumber(orderNumber);
    if (order != nullptr) {
        if (order->status == DELIVERED) {
            cout << "order delivered cannot be canceled" << endl;
        } else if (order->status == CANCELLED) {
            cout << "order has been canceled" << endl;
        } else {
            order->status = CANCELLED;
            cout << "order " << orderNumber << "delivered" << endl;
        }
    } else {
        cout << "order not found with this number" << endl;
    }
}

void RestaurantSystem::changeOrder() {
    int orderNumber;
    cout << "number order for change ";
    cin >> orderNumber;

    StudentOrder* order = findOrderByNumber(orderNumber);
    if (order == nullptr) {
        cout << "order not found with this number" << endl;
        return;
    }

    if (order->status != IN_PROGRESS) {
        cout << "only the order in progress can change" << endl;
        return;
    }

    int choice;
    cout << "\nadd item" << endl;
    cout << "delete item" << endl;
    cout << "choose ";
    cin >> choice;

    if (choice == 1) {
        addItemsToOrder(order);
    } else if (choice == 2) {
        cout << "new order item" << endl;
        OrderItem* current = order->itemsHead;
        while (current != nullptr) {
            cout << "  " << current->item->id << ". " << current->item->name
                 << " number " << current->quantity  << endl;
            current = current->next;
        }

        int itemId;
        cout << "item id for delete ";
        cin >> itemId;

        if (order->removeItem(itemId)) {
            cout << " item deleted" << endl;
            if (!order->hasItems()) {
                cout << "order has no item" << endl;
            }
        } else {
            cout << "item not found in order" << endl;
        }
    } else {
        cout << "error" << endl;
    }
}

void RestaurantSystem::reviewAllOrders() {
    cout << "\ncheck all order" << endl;
    if (ordersHead == nullptr) {
        cout << "no order saved" << endl;
        return;
    }

    StudentOrder* current = ordersHead;
    while (current != nullptr) {
        current->displayOrder();
        current = current->next;
    }
}

void RestaurantSystem::reviewOrdersByStatus(OrderStatus status) {
    string statusName;
    switch (status) {
        case IN_PROGRESS: statusName = "doing"; break;
        case DELIVERED: statusName = "delivered"; break;
        case CANCELLED: statusName = "canceled"; break;
    }

    cout << "\norders " << statusName << "  " << endl;

    bool found = false;
    StudentOrder* current = ordersHead;
    while (current != nullptr) {
        if (current->status == status) {
            current->displayOrder();
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        cout << "no order with this status" << endl;
    }
}

void RestaurantSystem::saveToFile() {
    ofstream menuFile("menu.txt");
    ofstream ordersFile("orders.txt");

    if (!menuFile.is_open() || !ordersFile.is_open()) {
        cout << " error open file to saved" << endl;
        return;
    }

    MenuItem* currentMenu = menuHead;
    while (currentMenu != nullptr) {
        menuFile << currentMenu->id << "  " << currentMenu->name << "  "
                << currentMenu->price << "  " << currentMenu->category << endl;
        currentMenu = currentMenu->next;
    }
    menuFile.close();

    StudentOrder* currentOrder = ordersHead;
    while (currentOrder != nullptr) {
        ordersFile << currentOrder->orderNumber << "  " << currentOrder->studentId << "  "
                  << currentOrder->firstName << " " << currentOrder->lastName << " "
                  << currentOrder->status << endl;

        OrderItem* currentItem = currentOrder->itemsHead;
        while (currentItem != nullptr) {
            ordersFile << "Item" << currentItem->item->id << " " << currentItem->quantity << endl;
            currentItem = currentItem->next;
        }

        ordersFile << "END_ORDER" << endl;
        currentOrder = currentOrder->next;
    }
    ordersFile.close();

    cout << "data file save to menu.txt و orders.txt" << endl;
}

//void RestaurantSystem::loadFromFile() {
  ///  cout << "قابلیت بارگذفایل در این نسخه پیاده‌سازی نشده است.اری از " << endl;
   // cout << "منوی نمونه به طور خودکار ایجاد شد." << endl;
//}