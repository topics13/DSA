#include <iostream>
using namespace std;

class Demo {
    int a[10], n;

public:
    void get();
    void asc_sort();
    void dec_sort();
    void disp();
};

void Demo::get() {
    cout << "\nEnter the array size (max 10): ";
    cin >> n;

    if (n > 10 || n <= 0) {
        cout << "\nInvalid size. Please enter a size between 1 and 10.";
        return;
    }

    cout << "\nEnter the array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void Demo::asc_sort() {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) // Exit if no swaps occurred
            break;
    }
}

void Demo::dec_sort() {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] < a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) // Exit if no swaps occurred
            break;
    }
}

void Demo::disp() {
    cout << "\nThe array elements are:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    Demo d;

    d.get();
    cout << "\nOriginal Array:";
    d.disp();

    d.asc_sort();
    cout << "\nAfter Ascending Sort:";
    d.disp();

    d.dec_sort();
    cout << "\nAfter Descending Sort:";
    d.disp();

    return 0;
}

// */ Output */
// Enter the array size: 3
// Enter the array element: 12 3 45
// The array element are12 3 45
// After Ascending Sort:
// The array element are3 12 45
// After Descending Sort:
// The array element are45 12 3