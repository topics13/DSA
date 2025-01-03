#include <iostream>
using namespace std;

int n; // Global declaration for array size

class merge {
    int a[10], b[10], i, j;
public:
    void read();
    void merge_sort(int l, int h);
    void merge1(int low, int m, int high);
    void disp();
};

void merge::read() {
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void merge::merge_sort(int l, int h) {
    int mid;
    if (l < h) {
        mid = (l + h) / 2;
        merge_sort(l, mid);       // Recursively sort the left half
        merge_sort(mid + 1, h);   // Recursively sort the right half
        merge1(l, mid, h);        // Merge the sorted halves
    }
}

void merge::merge1(int low, int m, int high) {
    int h = low;
    int i = low;
    j = m + 1;

    while ((h <= m) && (j <= high)) {
        if (a[h] <= a[j]) {
            b[i] = a[h];
            i++;
            h++;
        } else {
            b[i] = a[j];
            i++;
            j++;
        }
    }

    if (h <= m) {
        while (h <= m) {
            b[i] = a[h];
            i++;
            h++;
        }
    } else {
        while (j <= high) {
            b[i] = a[j];
            i++;
            j++;
        }
    }

    for (int k = low; k <= high; k++) {
        a[k] = b[k];
    }
}

void merge::disp() {
    for (i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
}

int main() {
    merge m;
    int l, h;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    cout << "Enter the elements: ";
    m.read();
    
    cout << "\nBefore Sorting: ";
    m.disp();

    l = 0;
    h = n - 1;

    m.merge_sort(l, h);

    cout << "\nAfter Sorting: ";
    m.disp();

    return 0;
}

// */ Output */
// Enter Elements5
// 12 -34 5 67 -8
// Display the array elements
// 12 -34 5 67 -8
// After Sorting
// -34 -8 5 12 67