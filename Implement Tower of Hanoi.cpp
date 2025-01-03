#include<iostream>
using namespace std;

class demo {
    int n;
public:
    void tower(int n, char beg, char aux, char end);
    void get();
};

void demo::get() {
    cout << "\nEnter the number of disks: ";
    cin >> n;
    tower(n, 'A', 'B', 'C');
}

void demo::tower(int n, char beg, char aux, char end) {
    if (n != 0) {
        tower(n - 1, beg, end, aux);
        cout << "\nMove disk " << n << " from " << beg << " to " << end << "\n";
        tower(n - 1, aux, beg, end);
    }
}

int main() {
    demo d;
    d.get();
    return 0;
}

// */ Output */
// Enter the number of disk: 3
// Move disk 1 from A to C
// Move disk 2 from A to B
// Move disk 1 from C to B
// Move disk 3 from A to C
// Move disk 1 from B to A
// Move disk 2 from B to C
// Move disk 1 from A to C