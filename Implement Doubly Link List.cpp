#include <iostream>
using namespace std;

class node {
    int info;
    node* left, * right;

public:
    void insert();
    void display();
    void del();
};

node* start = NULL, * temp = NULL, * current = NULL, * temp1 = NULL;

void node::insert() {
    int item;
    node* p = new node;
    cout << "\nEnter element: ";
    cin >> item;
    p->info = item;
    p->left = NULL;
    p->right = NULL;

    if (start == NULL) {
        start = p;
        return;
    }
    else {
        temp = start;
        while (temp->right != NULL)
            temp = temp->right;
        temp->right = p;
        p->left = temp; // Connect the previous node's right pointer to this new node
    }
}

void node::display() {
    current = start;
    if (current == NULL) {
        cout << "\n DLL is empty.";
        return;
    }
    else {
        cout << "\nNodes in DLL are: ";
        while (current != NULL) {
            cout << current->info << "\t";
            current = current->right; // Move to the next node
        }
    }
}

void node::del() {
    if (start == NULL) {
        cout << "\nDLL is empty.";
        return;
    }
    temp = start;
    start = temp->right;
    if (start != NULL) {
        start->left = NULL; // Set the new head's left pointer to NULL
    }
    temp->right = NULL; // Disconnect the deleted node from the list
    cout << "\nDeleted element is " << temp->info;
    delete temp; // Free the memory for the deleted node
}

int main() {
    node n;
    int ch = 0;

    cout << "\n1. Insert 2. Display 3. Delete 4. Exit\n";
    while (ch != 4) {
        cout << "\nEnter choice: ";
        cin >> ch;
        switch (ch) {
        case 1: 
            n.insert(); 
            break;
        case 2: 
            n.display(); 
            break;
        case 3: 
            n.del(); 
            break;
        case 4: 
            exit(0); 
            break;
        default:
            cout << "\nInvalid choice!";
            break;
        }
    }

    return 0;
}

// */ Output */
// 1. Insert 2. Display 3.Delete 4. Exit
// Enter choice2
// LL Empty:
// Enter choice1
// Enter element:10
// Enter choice1
// Enter element:20
// Enter choice1
// Enter element:30
// Enter choice2
// node in DLL are :10 20 30
// Enter choice3
// deleted element is10
// Enter choice2
// node in DLL are :20 30
// Enter choice3
// deleted element is20
// Enter choice3
// deleted element is30
// Enter choice2
// LL Empty:
// Enter choice3
// LL Empty:
// Enter choice