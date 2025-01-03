#include<iostream>
#include<conio.h>

class demo
{
    int a[10], i, j, n, item, k;

public:
    void get();
    void insert();
    void del();
    void dis();
};

void demo::get()
{
    std::cout << "\nEnter n: ";
    std::cin >> n;
    std::cout << "\nEnter Array Elements: ";
    for(i = 0; i < n; i++) // Use 0-based indexing
        std::cin >> a[i];
}

void demo::insert()
{
    std::cout << "\nEnter Position (1 to " << n + 1 << "): ";
    std::cin >> k;
    if(k < 1 || k > n + 1) {
        std::cout << "\nInvalid position!";
        return;
    }
    std::cout << "\nEnter Item: ";
    std::cin >> item;
    
    j = n;
    while(j >= k - 1) {
        a[j + 1] = a[j];
        j--;
    }
    a[k - 1] = item; // Correct index for 0-based array
    n++;
}

void demo::del()
{
    std::cout << "\nEnter Position (1 to " << n << "): ";
    std::cin >> k;
    if(k < 1 || k > n) {
        std::cout << "\nInvalid position!";
        return;
    }
    j = k - 1; // Correct index for 0-based array
    while(j < n - 1) {
        a[j] = a[j + 1];
        j++;
    }
    n--;
}

void demo::dis()
{
    std::cout << "\nElements are: \n";
    for(i = 0; i < n; i++) // Use 0-based indexing
        std::cout << a[i] << "\t";
}

int main()
{
    demo d;
    int ch = 0;

    d.get();
    std::cout << "\n1. Insert 2. Delete 3. Display 4. Exit\n";
    
    while(ch != 4)
    {
        std::cout << "\nEnter choice: ";
        std::cin >> ch;
        
        switch(ch)
        {
            case 1: d.insert(); break;
            case 2: d.del(); break;
            case 3: d.dis(); break;
            case 4: return 0; break;
            default: std::cout << "\nInvalid choice!"; break;
        }
    }
    return 0;
}

// */ Output */
// Enter n 3
// Enter Array Element:1 2 4
// 1. Insert 2.Del 3.Dis 4. Exit
// Enter choice 3
// Elements are
// 1 2 4
// Enter choice 1
// Enter Position: 2
// Enter Item: 6
// Enter choice 3
// Elements are
// 1 6 2 4
// Enter choice 2
// Enter Position: 3
// Enter choice 3
// Elements are
// 1 6 4
// Enter choice 4

