#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// First Fit algorithm
void firstFit(vector<int>& items, int binCapacity) {
    vector<int> bins;

    for (int i = 0; i < items.size(); i++) {
        bool isPlaced = false;

        for (int j = 0; j < bins.size(); j++) {
            if (bins[j] + items[i] <= binCapacity) {
                bins[j] += items[i];
                isPlaced = true;
                break;
            }
        }

        if (!isPlaced) {
            bins.push_back(items[i]);
        }
    }

    cout << "First Fit Algorithm: Number of bins used = " << bins.size() << endl;
    cout << "Bin Details:\n";
    for (int i = 0; i < bins.size(); i++) {
        cout << "Bin " << i + 1 << ": " << bins[i] << endl;
    }
}

// Best Fit algorithm
void bestFit(vector<int>& items, int binCapacity) {
    vector<int> bins;

    for (int i = 0; i < items.size(); i++) {
        int minSpace = binCapacity + 1;  // Initialize with a value greater than binCapacity
        int bestBin = -1;

        for (int j = 0; j < bins.size(); j++) {
            if (bins[j] + items[i] <= binCapacity && bins[j] + items[i] < minSpace) {
                minSpace = bins[j] + items[i];
                bestBin = j;
            }
        }

        if (bestBin != -1) {
            bins[bestBin] += items[i];
        } else {
            bins.push_back(items[i]);
        }
    }

    cout << "Best Fit Algorithm: Number of bins used = " << bins.size() << endl;
    cout << "Bin Details:\n";
    for (int i = 0; i < bins.size(); i++) {
        cout << "Bin " << i + 1 << ": " << bins[i] << endl;
    }
}

// First Fit Decreasing algorithm
void firstFitDecreasing(vector<int>& items, int binCapacity) {
    sort(items.rbegin(), items.rend());  // Sort the items in non-increasing order

    firstFit(items, binCapacity);
}

// Best Fit Decreasing algorithm
void bestFitDecreasing(vector<int>& items, int binCapacity) {
    sort(items.rbegin(), items.rend());  // Sort the items in non-increasing order

    bestFit(items, binCapacity);
}

int main() {
    int itemCount;
    cout << "Enter the number of items: ";
    cin >> itemCount;

    vector<int> items(itemCount);
    cout << "Enter the sizes of the items:\n";
    for (int i = 0; i < itemCount; i++) {
        cout << "Item " << i + 1 << ": ";
        cin >> items[i];
    }

    int binCapacity;
    cout << "Enter the bin capacity: ";
    cin >> binCapacity;
    cout << endl;
    firstFit(items, binCapacity);
    cout << endl;
    bestFit(items, binCapacity);
    cout << endl;
    firstFitDecreasing(items, binCapacity);
    cout << endl;
    bestFitDecreasing(items, binCapacity);

    return 0;
}
