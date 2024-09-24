#include <iostream>
#include <vector>
using namespace std;

class Item {
public:
    string name;
    float price;

    Item(string n, float p) : name(n), price(p) {}
};

class ShoppingList {
private:
    vector<Item> items;

public:
    void addItem(string name, float price) {
        items.emplace_back(name, price);
    }

    void removeItem(string name) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->name == name) {
                items.erase(it);
                cout << "Item removed: " << name << endl;
                return;
          
					  }
        }
        cout << "Item not found: " << name << endl;
    }

    void displayItems() const {
        if (items.empty()) {
            cout << "Shopping list is empty." << endl;
            return;
        }
        cout << "Items in the shopping list:" << endl;
        for (const auto& item : items) {
            cout << "Name: " << item.name << ", Price: " << item.price << endl;
        }
    }

    float calculateTotalCost() const {
        float total = 0;
        for (const auto& item : items) {
            total += item.price;
        }
        return total;
    }
};

int main() {
    ShoppingList list;
    char choice;
    string name;
    float price;

    do {
        cout << "1. Add Item\n2. Remove Item\n3. Display Items\n4. Calculate Total Cost\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter item name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter item price: ";
                cin >> price;
                list.addItem(name, price);
                break;
            case '2':
                cout << "Enter item name to remove: ";
                cin.ignore();
                getline(cin, name);
                list.removeItem(name);
                break;
            case '3':
                list.displayItems();
                break;
            case '4':
                cout << "Total Cost: " << list.calculateTotalCost() << endl;
                break;
            case '5':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '5');

    return 0;
}
