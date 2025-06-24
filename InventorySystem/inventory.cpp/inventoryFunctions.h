// InventoryFunctions.h
#ifndef INVENTORY_FUNCTIONS_H
#define INVENTORY_FUNCTIONS_H

#include <vector>
#include "inventoryItem.h"

void displayMenu();
void clearInputBuffer();
void addItem(std::vector<InventoryItem>& inventory);
void viewItems(const std::vector<InventoryItem>& inventory);
void updateItem(std::vector<InventoryItem>& inventory);
void deleteItem(std::vector<InventoryItem>& inventory);
void searchItem(const std::vector<InventoryItem>& inventory);

#endif
