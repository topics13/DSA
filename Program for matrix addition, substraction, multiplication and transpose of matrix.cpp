#include <iostream>
using namespace std;

class matrix {
    int a[5][5], b[5][5], c[5][5], d[5][5], e[5][5];
    int p, q, i, j, k, n, m;

public:
    void get();
    void add();
    void sub();
    void trans();
    void mul();
};

void matrix::get() {
    cout << "\nEnter Number of Rows & Columns for the first matrix: ";
    cin >> n >> m;
    cout << "\nEnter the first Matrix:\n";
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    cout << "\nEnter Number of Rows & Columns for the second matrix: ";
    cin >> p >> q;
    cout << "\nEnter the second Matrix:\n";
    for(i = 0; i < p; i++) {
        for(j = 0; j < q; j++) {
            cin >> b[i][j];
        }
    }
}

void matrix::add() {
    if (n == p && m == q) {
        cout << "\nThe addition of two matrices is: \n";
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                c[i][j] = a[i][j] + b[i][j];
                cout << c[i][j] << "\t";
            }
            cout << "\n";
        }
    } else {
        cout << "\nMatrix addition is not possible. Dimensions do not match.\n";
    }
}

void matrix::sub() {
    if (n == p && m == q) {
        cout << "\nThe subtraction of two matrices is: \n";
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                d[i][j] = a[i][j] - b[i][j];
                cout << d[i][j] << "\t";
            }
            cout << "\n";
        }
    } else {
        cout << "\nMatrix subtraction is not possible. Dimensions do not match.\n";
    }
}

void matrix::trans() {
    cout << "\nThe transpose of the first matrix is: \n";
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            e[j][i] = a[i][j];  // Transpose logic
            cout << e[j][i] << "\t";
        }
        cout << "\n";
    }
}

void matrix::mul() {
    if (m == p) {
        cout << "\nThe matrix multiplication result is: \n";
        for(i = 0; i < n; i++) {
            for(j = 0; j < q; j++) {
                c[i][j] = 0;
                for(k = 0; k < m; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
                cout << c[i][j] << "\t";
            }
            cout << "\n";
        }
    } else {
        cout << "\nMatrix multiplication is not possible. Number of columns in first matrix must equal number of rows in second matrix.\n";
    }
}

int main() {
    matrix m;
    m.get();
    int choice;
    
    cout << "\n1. Add\n2. Subtract\n3. Transpose\n4. Multiply\n5. Exit\n";
    
    while(true) {
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: m.add(); break;
            case 2: m.sub(); break;
            case 3: m.trans(); break;
            case 4: m.mul(); break;
            case 5: return 0;
            default: cout << "\nInvalid choice! Try again.\n"; break;
        }
    }
    return 0;
}


// */ Output */
// Enter Number of Row & Column : 3 3
// Enter the first Matrix:
// 1 2 3
// 4 5 6
// 7 8 9
// Enter Number of Row & Column : 3 3
// Enter the first Matrix:
// 1 2 3
// 4 5 6
// 7 8 9
// The addition of two matrix is :
// 2 4 6
// 8 10 12
// 14 16 18
// The Substraction of two matrix is :
// 0 0 0
// 0 0 0
// 0 0 0
// The Transpose of first matrix is :
// 1 4 7
// 2 5 8
// 3 6 9
// The Matrix Multiplication is :
// 30 36 42
// 66 81 96
// 102 126 150