#include <iostream>
#include "RestaurantSystem.h"


using namespace std;

void displayMainMenu() {
    cout << "student restaurant management system" << endl;
    cout << "1.show menu" << endl;
    cout << "2. new order registr" << endl;
    cout << "3. order delivery" << endl;
    cout << "4. caceled order" << endl;
    cout << "5. change order" << endl;
    cout << "6. check all order" << endl;
    cout << "7. checking order" << endl;
    cout << "8.check order delivery" << endl;
    cout << "9. checking canceled order" << endl;
    cout << "10. save data to file" << endl;
    cout << "11.loading data from file " << endl;
    cout << "0. exit" << endl;
    cout << "choose ";
}

int main() {
    RestaurantSystem system;
    int choice;

    cout << "welcome student restaurant management system" << endl;

    do {
        displayMainMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                system.displayMenu();
                break;
            case 2:
                system.createNewOrder();
                break;
            case 3:
                system.deliverOrder();
                break;
            case 4:
                system.cancelOrder();
                break;
            case 5:
                system.changeOrder();
                break;
            case 6:
                system.reviewAllOrders();
                break;
            case 7:
                system.reviewOrdersByStatus(IN_PROGRESS);
                break;
            case 8:
                system.reviewOrdersByStatus(DELIVERED);
                break;
            case 9:
                system.reviewOrdersByStatus(CANCELLED);
                break;
            case 10:
                system.saveToFile();
                break;
           // case 11:
               // system.loadFromFile();
               // break;
            case 0:
                system.saveToFile();
                cout << "thank you data saved" << endl;
                break;
            default:
                cout << "incorrect try again please." << endl;
        }

    } while (choice != 0);

    return 0;
}