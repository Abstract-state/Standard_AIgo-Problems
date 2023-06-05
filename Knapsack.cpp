#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
};

// Comparator function to sort items in descending order of value-to-weight ratio
bool compareItems(const Item& item1, const Item& item2) {
    double ratio1 = static_cast<double>(item1.value) / item1.weight;
    double ratio2 = static_cast<double>(item2.value) / item2.weight;
    return ratio1 > ratio2;
}

void fractionalKnapsack(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), compareItems);

    int currentWeight = 0;
    double totalValue = 0.0;
    vector<double> fractions(items.size(), 0.0);

    for (int i = 0; i < items.size(); i++) {
        if (currentWeight + items[i].weight <= capacity) {
            fractions[i] = 1.0;
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            double remainingWeight = capacity - currentWeight;
            fractions[i] = remainingWeight / items[i].weight;
            totalValue += fractions[i] * items[i].value;
            break;
        }
    }

    for (int i = 0; i < items.size(); i++) {
        cout << "Item " << i + 1 << " taken: " << fractions[i] << endl;
    }

    cout << "Maximum Profit: " << totalValue << endl;
}

void knapsack01(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), compareItems);

    vector<int> selectedItems(items.size(), 0);
    int currentWeight = 0;
    int totalValue = 0;

    for (int i = 0; i < items.size(); i++) {
        if (currentWeight + items[i].weight <= capacity) {
            selectedItems[i] = 1;
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            break;
        }
    }

    for (int i = 0; i < items.size(); i++) {
        cout << "Item " << i + 1 << " taken: " << selectedItems[i] << endl;
    }

    cout << "Maximum Profit: " << totalValue << endl;
}

int main() {
    int numItems;
    cout << "Enter the number of items: ";
    cin >> numItems;

    vector<Item> items(numItems);
    for (int i = 0; i < numItems; i++) {
        cout << "Enter weight and value for item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].value;
    }

    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    cout << "\nFractional Knapsack:\n";
    fractionalKnapsack(items, capacity);

    cout << "\n0/1 Knapsack:\n";
    knapsack01(items, capacity);

    return 0;
}
