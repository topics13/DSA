#include <iostream>
using namespace std;

class node {
    int info;
    node* link;
    int count;

public:
    node() {
        count = 0;
    }
    void insert();
    void display();
    void del();
};

node* start = NULL;

void node::insert() {
    int item;
    node* p = new node;
    cout << "\nEnter Element: ";
    cin >> item;
    p->info = item;
    p->link = NULL;

    if (start == NULL) {
        start = p;
        p->link = start; // Points to itself
        count++;
    } else {
        node* temp = start;
        while (temp->link != start)
            temp = temp->link;
        temp->link = p;
        p->link = start;
        count++;
    }
}

void node::display() {
    if (start == NULL) {
        cout << "\nCircular Linked List is empty";
        return;
    }

    node* temp = start;
    cout << "\nNodes in the Circular Linked List: ";
    do {
        cout << temp->info << " -> ";
        temp = temp->link;
    } while (temp != start);
    cout << "START\n";
    cout << "Number of nodes in the Circular Linked List: " << count;
}

void node::del() {
    int pos;
    cout << "\nEnter Position to delete: ";
    cin >> pos;

    if (start == NULL) {
        cout << "\nCircular Linked List is empty.";
        return;
    }

    if (pos < 1 || pos > count) {
        cout << "\nInvalid Position!";
        return;
    }

    if (pos == 1) {
        // Deleting the first node
        node* temp = start;
        node* last = start;

        while (last->link != start)
            last = last->link;

        if (last == start) { // Only one node
            start = NULL;
        } else {
            start = start->link;
            last->link = start;
        }

        cout << "\nDeleted Element: " << temp->info;
        delete temp;
        count--;
    } else {
        // Deleting a node at a specific position
        node* temp = start;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->link;
        }
        node* delNode = temp->link;
        temp->link = delNode->link;

        cout << "\nDeleted Element: " << delNode->info;
        delete delNode;
        count--;
    }
}

int main() {
    node n;
    int ch;

    cout << "\n1. Insert 2. Display 3. Delete 4. Exit\n";
    do {
        cout << "\nEnter Choice: ";
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
                cout << "\nExiting...";
                break;
            default:
                cout << "\nInvalid choice!";
                break;
        }
    } while (ch != 4);

    return 0;
}

// */ Output */
// 1.Insert 2.Display 3.Delete 4.Exit
// Enter Choice1
// Enter Element:10
// Enter Choice1
// Enter Element:20
// Enter Choice2
// 10->20
// Number of nodes in CLL are :2
// Enter Choice3
// Enter Position:2
// Deleted element is20
// Enter Choice2
// 10
// Number of nodes in CLL are :1
// Enter Choice3
// Enter Position:1
// LL Empty:
// Enter Choice2
// LL empty
// Enter Choice 4