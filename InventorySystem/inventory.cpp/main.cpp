// main.cpp
#include <iostream>
#include <vector>
#include "inventoryItem.h"
#include "inventoryFunctions.h"

int main() {
    std::vector<InventoryItem> inventory;
    int choice;

    do {
        displayMenu();
        while (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number: ";
            std::cin.clear();
            clearInputBuffer();
        }

        switch (choice) {
            case 1: addItem(inventory); break;
            case 2: viewItems(inventory); break;
            case 3: updateItem(inventory); break;
            case 4: deleteItem(inventory); break;
            case 5: searchItem(inventory); break;
            case 6: std::cout << "Goodbye!\n"; break;
            default: std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
