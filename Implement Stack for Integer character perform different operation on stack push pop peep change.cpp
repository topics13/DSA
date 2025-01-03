#include <iostream>
using namespace std;

int n;

class stack {
private:
    int s[10], top, ele, i;  // Use a fixed-size array for simplicity in this case
public:
    stack() {
        top = -1;  // Initialize top to -1 (empty stack)
    }

    void push();
    void dis();
    void pop();
    void peep();
    void change();
};

void stack::push() {
    if(top >= n - 1) {
        cout << "\nStack is overflow:";
    } else {
        cout << "\nEnter element: ";
        cin >> ele;
        top++;
        s[top] = ele;
    }
}

void stack::dis() {
    if(top == -1) {
        cout << "\nStack is Empty";
    } else {
        cout << "\nElements in stack are:\n";
        for(i = top; i >= 0; i--)
            cout << s[i] << "\t";
    }
}

void stack::pop() {
    if(top == -1) {
        cout << "\nUnderflow";
    } else {
        cout << "\nPopped element is: " << s[top];
        top--;
    }
}

void stack::peep() {
    cout << "\nEnter position: ";
    cin >> i;
    if(i < 1 || i > top + 1) {
        cout << "\nInvalid position!";
    } else {
        cout << "\nPeep element at position " << i << " is: " << s[top - i + 1];
    }
}

void stack::change() {
    cout << "\nEnter position: ";
    cin >> i;
    if(i < 1 || i > top + 1) {
        cout << "\nInvalid position!";
    } else {
        int new_element;
        cout << "\nEnter new element: ";
        cin >> new_element;
        s[top - i + 1] = new_element;
    }
}

int main() {
    stack s;
    cout << "Enter size of stack: ";
    cin >> n;
    int ch = 0;

    cout << "\n1. Push 2. Display 3. Pop 4. Peep 5. Change 6. Exit\n";
    while(ch != 6) {
        cout << "\nEnter choice: ";
        cin >> ch;
        switch(ch) {
            case 1: s.push(); break;
            case 2: s.dis(); break;
            case 3: s.pop(); break;
            case 4: s.peep(); break;
            case 5: s.change(); break;
            case 6: exit(0);
            default: cout << "\nInvalid choice! Please try again.\n"; break;
        }
    }

    return 0;
}


// */ Output */
// Enter size of stack 3
// 1. Push 2.Display 3.Pop 4.Peep 5.Change 6.Exit
// Enter ch :1
// Enter element:10
// Enter ch :1
// Enter element:20
// Enter ch :1
// Enter element:30
// Enter ch :1
// Stack is overflow:
// Enter ch :2
// Elements in stack are:
// 30 20 10
// Enter ch :3
// Pop ele is 30
// Enter ch :2
// Elements in stack are:
// 20 10
// Enter ch :4
// Enter position:1
// Peep ele is 20
// Enter ch :
// 2
// Elements in stack are:
// 20 10
// Enter ch :5
// Enter position 1
// Enter element:80
// Enter ch :2
// Elements in stack are:
// 80 10
// Enter ch : 6