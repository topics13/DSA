#include <iostream>
using namespace std;

class demo {
    int a[10], i, j, n, f, temp, ele, mid, low, high;
public:
    void get();
    void sort();
    void linear();
    void binary();
    void dis();
};

void demo::get() {
    cout << "\nEnter n: ";
    cin >> n;
    cout << "\nEnter array Elements: ";
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void demo::linear() {
    int ele;
    cout << "\nEnter the element to be searched: ";
    cin >> ele;
    for (i = 0; i < n; i++) {
        if (a[i] == ele) {
            cout << "\nSuccessful search";
            cout << "\nElement is found at position " << i + 1;
            return;
        }
    }
    cout << "\nUnsuccessful search:";
    cout << "\nElement is not found.";
}

void demo::sort() {
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] < a[j + 1]) {  // Sort in descending order
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void demo::binary() {
    cout << "\nEnter element to be searched: ";
    cin >> ele;
    f = 0;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == ele) {
            f = 1;
            cout << "\nElement is found at position: " << mid + 1;
            return;
        }
        else if (a[mid] < ele)
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (f == 0)
        cout << "\nElement is not found.";
}

void demo::dis() {
    cout << "\nElements are:\n";
    for (i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    demo d;
    int ch;
    d.get();
    d.dis();
    cout << "\n1: Linear Search  2: Binary Search  3: Exit\n";
    
    while (true) {
        cout << "\nEnter Choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            d.linear();
            break;
        case 2:
            d.sort();
            d.dis();
            d.binary();
            break;
        case 3:
            return 0;  // Exit the program
        default:
            cout << "Invalid choice. Please try again.";
        }
    }
    return 0;
}

// */ Output */
// Enter n:3
// Enter array Elements:12 3 45
// Element are
// 12 3 45
// 1:Linear 2:Binary 3:exit
// Enter Choice:1
// Enter the element to be search 3
// Successful search
// Element is found at position 2
// Enter Choice:2
// Element are
// 45 12 3
// Enter element to be search 12
// Element is found at :2
// Enter Choice:2
// Element are
// 45 12 3
// Enter element to be search 56
// Element is not found:
// Enter Choice:3