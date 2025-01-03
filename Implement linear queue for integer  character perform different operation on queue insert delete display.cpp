#include <iostream>
using namespace std;

int m;

class queue {
private:
    int f, r, q[10], n, i;  // q[10] for queue array, n for element
public:
    queue() {
        f = r = 0;
    }

    void insert();
    void del();
    void dis();
};

void queue::insert() {
    if (r == m - 1) {  // Overflow condition
        cout << "\nOverflow";
    } else {
        cout << "\nEnter Element in Queue: ";
        cin >> n;
        if (f == 0)  // First element insertion
            f = 1;
        r++;
        q[r] = n;
    }
}

void queue::del() {
    if (f == 0) {  // Underflow condition
        cout << "\nUnderflow";
    } else {
        int n;
        n = q[f];
        if (f == r)  // Reset if the queue becomes empty
            f = r = 0;
        else
            f++;
        cout << "\nDeleted element is: " << n;
    }
}

void queue::dis() {
    if (f == 0) {  // Underflow condition
        cout << "\nUnderflow";
    } else {
        cout << "\nElements in queue are: ";
        for (i = f; i <= r; i++) {
            cout << q[i] << "\t";
        }
    }
}

int main() {
    queue q;
    int ch = 0;
    
    cout << "Enter size of queue: ";
    cin >> m;
    
    cout << "\n1. Insert 2. Display 3. Delete 4. Exit\n";
    while (ch != 4) {
        cout << "\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: q.insert(); break;
            case 2: q.dis(); break;
            case 3: q.del(); break;
            case 4: exit(0);
            default: cout << "\nInvalid choice! Please try again.\n"; break;
        }
    }

    return 0;
}


// */ Output */
// Enter size of queue 3
// 1.insert 2.display 3.delete 4. exit
// Enter ch:3
// Underflow
// Enter ch:1
// Enter Element in Queue=10
// Enter ch:1
// Enter Element in Queue=20
// Enter ch:1
// Enter Element in Queue=30
// Enter ch:1
// Overflow
// Enter ch:2
// Elements in queue are:10 20 30
// Enter ch:3
// Deleted element is 10
// Enter ch:2
// Elements in queue are:20 30
// Enter ch:4