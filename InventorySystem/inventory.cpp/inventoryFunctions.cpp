#include "inventoryFunctions.h"
#include <iostream>
#include <iomanip>
#include <limits>

void displayMenu() {
    std::cout << "\n--- Inventory Management System ---\n"
              << "1. Add Item\n"
              << "2. View Items\n"
              << "3. Update Item\n"
              << "4. Delete Item\n"
              << "5. Search Item\n"
              << "6. Exit\n"
              << "-----------------------------------\n"
              << "Enter your choice: ";
}

void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void addItem(std::vector<InventoryItem>& inventory) {
    InventoryItem newItem;
    std::cout << "\n--- Add New Item ---\n";
    clearInputBuffer();
    do {
        std::cout << "Enter item name: ";
        std::getline(std::cin, newItem.name);
        if (newItem.name.empty()) {
            std::cout << "Item name cannot be empty.\n";
        }
    } while (newItem.name.empty());

    for (const auto& item : inventory) {
        if (item.name == newItem.name) {
            std::cout << "Item already exists. Use update instead.\n";
            return;
        }
    }

    std::cout << "Enter quantity: ";
    while (!(std::cin >> newItem.quantity) || newItem.quantity < 0) {
        std::cout << "Invalid quantity. Try again: ";
        std::cin.clear(); clearInputBuffer();
    }

    std::cout << "Enter price: ";
    while (!(std::cin >> newItem.price) || newItem.price < 0) {
        std::cout << "Invalid price. Try again: ";
        std::cin.clear(); clearInputBuffer();
    }

    inventory.push_back(newItem);
    std::cout << "Item added successfully!\n";
    clearInputBuffer();
}

void viewItems(const std::vector<InventoryItem>& inventory) {
    std::cout << "\n--- Current Inventory ---\n";
    if (inventory.empty()) {
        std::cout << "Inventory is empty.\n";
        return;
    }

    const int nameWidth = 25;
    const int qtyWidth = 10;
    const int priceWidth = 10;

    std::cout << std::string(nameWidth + qtyWidth + priceWidth, '-') << '\n';
    std::cout << std::left << std::setw(nameWidth) << "Name"
              << std::setw(qtyWidth) << "Quantity"
              << std::setw(priceWidth) << "Price" << '\n';
    std::cout << std::string(nameWidth + qtyWidth + priceWidth, '-') << '\n';

    for (const auto& item : inventory) {
        std::cout << std::left << std::setw(nameWidth) << item.name
                  << std::setw(qtyWidth) << item.quantity
                  << std::setw(priceWidth) << std::fixed << std::setprecision(2) << item.price << '\n';
    }
    std::cout << std::string(nameWidth + qtyWidth + priceWidth, '-') << '\n';
}

void updateItem(std::vector<InventoryItem>& inventory) {
    std::string name;
    std::cout << "\n--- Update Item ---\n";
    if (inventory.empty()) {
        std::cout << "Inventory is empty.\n";
        return;
    }

    clearInputBuffer();
    std::cout << "Enter name of item to update: ";
    std::getline(std::cin, name);

    for (auto& item : inventory) {
        if (item.name == name) {
            std::cout << "Enter new quantity: ";
            while (!(std::cin >> item.quantity) || item.quantity < 0) {
                std::cout << "Invalid quantity. Try again: ";
                std::cin.clear(); clearInputBuffer();
            }

            std::cout << "Enter new price: ";
            while (!(std::cin >> item.price) || item.price < 0) {
                std::cout << "Invalid price. Try again: ";
                std::cin.clear(); clearInputBuffer();
            }

            std::cout << "Item updated.\n";
            clearInputBuffer();
            return;
        }
    }
    std::cout << "Item not found.\n";
}

void deleteItem(std::vector<InventoryItem>& inventory) {
    std::string name;
    std::cout << "\n--- Delete Item ---\n";
    if (inventory.empty()) {
        std::cout << "Inventory is empty.\n";
        return;
    }

    clearInputBuffer();
    std::cout << "Enter name of item to delete: ";
    std::getline(std::cin, name);

    for (size_t i = 0; i < inventory.size(); ++i) {
        if (inventory[i].name == name) {
            inventory.erase(inventory.begin() + i);
            std::cout << "Item deleted.\n";
            return;
        }
    }
    std::cout << "Item not found.\n";
}

void searchItem(const std::vector<InventoryItem>& inventory) {
    std::string name;
    std::cout << "\n--- Search Item ---\n";
    if (inventory.empty()) {
        std::cout << "Inventory is empty.\n";
        return;
    }

    clearInputBuffer();
    std::cout << "Enter name of item to search: ";
    std::getline(std::cin, name);

    for (const auto& item : inventory) {
        if (item.name == name) {
            const int nameWidth = 25;
            const int qtyWidth = 10;
            const int priceWidth = 10;

            std::cout << "\nItem Found:\n";
            std::cout << std::string(nameWidth + qtyWidth + priceWidth, '-') << '\n';
            std::cout << std::left << std::setw(nameWidth) << "Name"
                      << std::setw(qtyWidth) << "Quantity"
                      << std::setw(priceWidth) << "Price" << '\n';
            std::cout << std::string(nameWidth + qtyWidth + priceWidth, '-') << '\n';
            std::cout << std::left << std::setw(nameWidth) << item.name
                      << std::setw(qtyWidth) << item.quantity
                      << std::setw(priceWidth) << std::fixed << std::setprecision(2) << item.price << '\n';
            std::cout << std::string(nameWidth + qtyWidth + priceWidth, '-') << '\n';
            return;
        }
    }
    std::cout << "Item not found.\n";
}
