#include <iostream>
using namespace std;

class Queue {
    int a[5], r, f;

public:
    Queue() {
        f = r = -1; // Initialize front and rear to -1
    }

    void push();
    void pop();
    void show();
};

void Queue::push() {
    int item;
    if ((r + 1) % 5 == f) {
        // Check for overflow (queue is full)
        cout << "\nOverflow";
    } else {
        if (r == 4) {
            r = -1;  // Wrap around to the beginning
        }
        r++;
        cout << "\nEnter item: ";
        cin >> item;
        a[r] = item;

        if (f == -1) {
            f = 0;  // Set front to 0 if the queue is empty
        }
    }
}

void Queue::pop() {
    if (f == -1) {
        // Check for underflow (queue is empty)
        cout << "\nUnderflow";
    } else {
        cout << "\nDeleted element is: " << a[f];
        if (f == r) {
            // If the queue becomes empty after pop
            f = r = -1;
        } else {
            if (f == 4) {
                f = 0; // Wrap around front
            } else {
                f++; // Move front forward
            }
        }
    }
}

void Queue::show() {
    if (f == -1) {
        // If queue is empty
        cout << "\nQueue is empty!";
    } else {
        cout << "\nQueue elements are: ";
        int i = f;
        while (i != r) {
            cout << a[i] << " ";
            i = (i + 1) % 5;  // Move to next element in circular manner
        }
        cout << a[r] << " ";  // Display the last element
    }
}

int main() {
    Queue s;
    int ch;
    do {
        cout << "\n1: Push 2: Pop 3: Show 4: Exit";
        cout << "\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: s.push(); break;
            case 2: s.pop(); break;
            case 3: s.show(); break;
            default: cout << "\nWrong Choice!";
        }
    } while (ch != 4);

    return 0;
}


// */ Output */
// 1: Push 2: Pop 3: Show 4: Exit
// Enter choice: 1
// Enter item: 10

// 1: Push 2: Pop 3: Show 4: Exit
// Enter choice: 1
// Enter item: 20

// 1: Push 2: Pop 3: Show 4: Exit
// Enter choice: 1
// Enter item: 30

// 1: Push 2: Pop 3: Show 4: Exit
// Enter choice: 3
// Queue elements are: 10 20 30 

// 1: Push 2: Pop 3: Show 4: Exit
// Enter choice: 2
// Deleted element is: 10

// 1: Push 2: Pop 3: Show 4: Exit
// Enter choice: 3
// Queue elements are: 20 30 

// 1: Push 2: Pop 3: Show 4: Exit
// Enter choice: 2
// Deleted element is: 20

// 1: Push 2: Pop 3: Show 4: Exit
// Enter choice: 3
// Queue elements are: 30 

// 1: Push 2: Pop 3: Show 4: Exit
// Enter choice: 4
// Exiting...