#include<iostream>
#include<string.h>
using namespace std;

class demo {
    int x[20], temp;
    int a, n, i, j, left, right;
public:
    void get();
    void asort(int, int);
    int partition(int, int);
    void disp();
};

void demo::get() {
    cout << "\nEnter the array size: ";
    cin >> n;
    cout << "\nEnter the array elements: ";
    for (i = 0; i < n; i++) {  // Index starts from 0
        cin >> x[i];
    }
    asort(0, n - 1); // Modify to work with 0-indexing
}

void demo::asort(int p, int q) {
    if (p < q) {
        j = partition(p, q);
        asort(p, j - 1);
        asort(j + 1, q);
    }
}

int demo::partition(int lb, int ub) {
    a = x[lb];
    left = lb + 1;
    right = ub;
    do {
        while (x[left] < a && left <= ub)  // Ascending: x[left] < a
            left++;
        while (x[right] > a && right >= lb)  // Descending: x[right] > a
            right--;
        if (left < right) {
            temp = x[left];
            x[left] = x[right];
            x[right] = temp;
        }
    } while (left <= right);

    x[lb] = x[right];
    x[right] = a;

    return right;
}

void demo::disp() {
    cout << "\nThe array elements are: ";
    for (i = 0; i < n; i++) {
        cout << x[i] << "\t";
    }
}

int main() {
    demo d;
    d.get();
    cout << "\nAfter Ascending Sort: ";  // Change to "After Descending Sort" if needed
    d.disp();
    return 0;
}

// */ Output */
// Enter the array size: 5
// Enter the array element:12 3 -45 -67 8
// After Ascending sort
// The array element are:-67 -45 3 8 12