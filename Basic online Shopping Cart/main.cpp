#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Product structure
struct Product {
int id;
string name;
double price;
};

// Function to display available products
void displayProducts(const vector<Product>& products){
cout << "Available Product:\n";
for (const auto& product : products) {
    cout << product.id << ". " << product.name << " - $" << product.price << endl;
}
cout << endl;
}

// Function to display the cart

void displayCart(const vector<Product>& cart) {
if (cart.empty()) {
    cout << "Your cart is empty.\n";
    return;
}

double total = 0;
cout << "Your Cart:\n";
for (const auto& item : cart) {
    cout << "- " << item.name << " - $" << item.price << endl;
    total += item.price;
}
cout << "Total: $" << total << "\n\n";
}

int main() {

//Product list
vector<Product> products = {
{1, "Laptop", 799.99},
{2, "Smartphone", 499.99},
{3, "Headphones", 99.99},
{4, "Smartwatch", 199.99}
};

vector<Product> cart;
int choice;

while (true) {
    cout << "\nE-commerce System\n";
    cout << "1. View Products\n";
    cout << "2. Add to Cart\n";
    cout << "3. View Cart\n";
    cout << "4. Checkout\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        displayProducts(products);
    }
    else if (choice == 2) {
        int productId;
        displayProducts(products);
        cout << "Enter the product ID to cart: ";
        cin >> productId;

        bool found = false;
        for (const auto& product : products) {
            if (product.id == productId) {
                cart.push_back(product);
                cout << product.name << " added to cart.\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Invalid Product ID\n";
        }
    }
    else if (choice == 3) {
        displayCart(cart);
    }
    else if (choice == 4) {
        displayCart(cart);
        if (!cart.empty()) {
            cout << "Thank you for shopping! Your order has been placed.\n";
            cart.clear();
        }
    }
    else if (choice == 5) {
        cout << "Exiting program. Thank you!\n";
        break;
    } else {
    cout << "Invalid choice. Please try again.\n";
    }
}
return 0;
}
