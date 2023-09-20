#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item
struct Item {
    int weight;
    int value;
};
double fractionalKnapsack(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return double(a.value) / a.weight > double(b.value) / b.weight;
    });

    double max_value = 0.0;

    for (const Item& item : items) {
        if (capacity >= item.weight) {
            max_value += item.value;
            capacity -= item.weight;
        } else {
            max_value += (double(item.value) / item.weight) * capacity;
            break;
        }
    }
    return max_value;
}

int main() {
    vector<Item> items = {{2, 10}, {3, 5}, {5, 15}, {7, 7}, {1, 6}};
    int capacity = 10;

    double max_value = fractionalKnapsack(items, capacity);
    cout << "Maximum value: " << max_value << endl;
    return 0;
}
