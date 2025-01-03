#include <iostream>
using namespace std;

class heap {
    int n, a[10], q, i, j, key, temp;
public:
    void get();
    void create();
    void sort();
    void display();
};

void heap::get() {
    cout << "\nEnter range: ";
    cin >> n;
    cout << "\nEnter the elements:\n";
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void heap::create() {
    // Building the max heap
    for (q = 1; q < n; q++) {
        i = q;
        key = a[q];
        j = (i - 1) / 2;  // Parent node
        while (i > 0 && key > a[j]) {  // Max-heapify condition
            a[i] = a[j];
            i = j;
            j = (i - 1) / 2;
        }
        a[i] = key;
    }
}

void heap::sort() {
    create();  // Create the max heap
    cout << "\nMax Heap Tree:\n";
    display();  // Display the max heap before sorting

    for (q = n - 1; q > 0; q--) {
        // Swap the root (max) with the last element
        temp = a[0];
        a[0] = a[q];
        a[q] = temp;

        // Reheapify the root element
        i = 0;
        key = a[i];
        j = 2 * i + 1;  // Left child

        while (j < q) {
            // Find the larger of the two children
            if (j + 1 < q && a[j + 1] > a[j]) {
                j++;
            }

            // If the key is larger than both children, we can stop
            if (key >= a[j]) {
                break;
            }

            // Move the larger child up
            a[i] = a[j];
            i = j;
            j = 2 * i + 1;
        }
        a[i] = key;
    }
}

void heap::display() {
    for (i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    heap h;
    h.get();
    h.sort();
    cout << "\nSorted elements are:\n";
    h.display();
    return 0;
}

// */ Output */
// Enter range: 5
// Enter the elements
// 12 3 45 6 18
// Max Heap Tree45 18 12 3 6
// Sorted element are:3 6 12 18 45