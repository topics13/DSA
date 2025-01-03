#include <iostream>
using namespace std;

class Demo {
    int a[10], n;

public:
    void get();
    void asc_sort();
    void dsc_sort();
    void disp();
    int getSize() { return n; } // Public function to access 'n'
};

void Demo::get() {
    cout << "\nEnter the array size (max 10): ";
    cin >> n;

    if (n <= 0 || n > 10) {
        cout << "Invalid size. Please enter a size between 1 and 10.\n";
        n = 0; // Reset size to prevent further operations
        return;
    }

    cout << "\nEnter the array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void Demo::asc_sort() {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(a[i], a[min_index]);
        }
    }
}

void Demo::dsc_sort() {
    for (int i = 0; i < n - 1; i++) {
        int max_index = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[max_index]) {
                max_index = j;
            }
        }
        if (max_index != i) {
            swap(a[i], a[max_index]);
        }
    }
}

void Demo::disp() {
    if (n == 0) {
        cout << "Array is empty or not initialized.\n";
        return;
    }

    cout << "\nThe array elements are:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    Demo d;

    d.get();
    if (d.getSize() == 0) { // Use public member function to access 'n'
        return 0; // Exit if input was invalid
    }

    cout << "\nOriginal Array:";
    d.disp();

    d.asc_sort();
    cout << "\nAfter Ascending Sort:";
    d.disp();

    d.dsc_sort();
    cout << "\nAfter Descending Sort:";
    d.disp();

    return 0;
}


// */ Output */
// Enter the array size:4
// Enter the array element:12 3 -45 -6
// The array element are12 3 -45 -6
// After ascending sort:
// The array element are-45 -6 3 12
// After Descending sort:
// The array element are12 3 -6 -45