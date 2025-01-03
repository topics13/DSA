#include <iostream>
using namespace std;

class heap {
    int n, a[10], q, i, j, k, key;

public:
    void get();
    void create();
    void display();
};

void heap::get() {
    cout << "\nEnter Range: ";
    cin >> n;
    cout << "\nEnter the elements: ";
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

void heap::create() {
    for (q = 2; q <= n; q++) {
        i = q;
        key = a[q];
        j = i / 2;
        while (i > 1 && key > a[j]) { // Max Heap
            a[i] = a[j];
            i = j;
            j = i / 2;
            if (j < 1)
                j = 1;
        }
        a[i] = key;
    }
}

void heap::display() {
    cout << "\nHeap Tree: ";
    for (i = 1; i <= n; i++) {
        cout << a[i] << "\t";
    }
}

int main() {
    heap h;
    h.get();
    h.create();
    h.display();
    return 0;
}


// */ Output */
// Enter the number of node5
// Enter the adjancy matrix:
// 0 1 1 0 0
// 1 0 0 1 1
// 1 0 0 1 0
// 0 1 1 0 1
// 0 1 0 1 0
// 1 2 4 3 5