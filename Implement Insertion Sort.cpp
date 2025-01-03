#include <iostream>
using namespace std;

class InsertionSort {
    int n, a[10];

public:
    void get();
    void sort();
    void display();
    int getSize(); // Getter method to access n
};

void InsertionSort::get() {
    cout << "Enter Range: ";
    cin >> n;

    if (n <= 0 || n > 10) {
        cout << "Invalid range. Please enter a number between 1 and 10.\n";
        n = 0; // Reset n to avoid further operations
        return;
    }

    cout << "Elements are: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void InsertionSort::sort() {
    for (int i = 1; i < n; i++) {
        int temp = a[i];
        int ptr = i - 1;

        while (ptr >= 0 && temp < a[ptr]) {
            a[ptr + 1] = a[ptr];
            ptr--;
        }
        a[ptr + 1] = temp;
    }
}

void InsertionSort::display() {
    cout << "Sorted Element using Insertion Sort: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int InsertionSort::getSize() {
    return n; // Return the value of n
}

int main() {
    InsertionSort sorter;
    sorter.get();

    if (sorter.getSize() > 0) { // Use the getter method to check n
        sorter.sort();
        sorter.display();
    }

    return 0;
}

// */ Output */
// Enter Range:5
// Elements are :10 3 335 33 355
// Sorted Element using Insertion Sort:3 10 33 335 355