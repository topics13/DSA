#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class Demo {
    int b[20][20], a[20];  // Buckets and array to be sorted
    int n, l; // n: Array size, l: Maximum number of digits in largest number
public:
    void get();
    void sort();
    void disp();
    int getSize(); // Public getter for n
};

void Demo::get() {
    cout << "Enter the array size: ";
    cin >> n;

    // Initialize the bucket array with -1 to indicate empty slots
    for (int i = 0; i < 20; i++) 
        for (int j = 0; j < 20; j++) 
            b[i][j] = -1;

    // Generate and input array elements
    cout << "Enter the array element: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Display initial array
    cout << "\nThe array element are: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;

    // Find the maximum number of digits in any number in the array
    l = 0;
    for (int i = 0; i < n; i++) {
        int k = 0, c = a[i];
        while (c > 0) {
            k++;
            c /= 10;
        }
        if (l < k) 
            l = k;
    }
}

void Demo::sort() {
    for (int j = 1; j <= l; j++) {
        // Step 1: Fill buckets based on the current digit (from least significant digit)
        cout << "\nStep " << j << " : Fill buckets based on digit " << j << endl;

        for (int i = 0; i < n; i++) {
            int k = (int(a[i] / pow(10, j - 1)) % 10); // Extract the current digit
            int z = 0;
            // Insert number into the appropriate bucket (k-th bucket)
            while (b[k][z] != -1) 
                z++;
            b[k][z] = a[i];
        }

        // Display the contents of each bucket after filling
        for (int k = 0; k < 10; k++) {
            cout << "Bucket " << k << ": ";
            for (int z = 0; z < n; z++) {
                if (b[k][z] != -1) 
                    cout << b[k][z] << " ";
            }
            cout << endl;
        }

        // Step 2: Collect numbers from the buckets back into the array (in reverse order)
        int i = 0;
        for (int k = 9; k >= 0; k--) {
            int z = 0;
            while (b[k][z] != -1) {
                a[i] = b[k][z];
                b[k][z] = -1;  // Reset the bucket
                i++;
                z++;
            }
        }

        // Display the array after collecting numbers from the buckets
        cout << "After collecting numbers from the buckets: ";
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

void Demo::disp() {
    // Display the final sorted array
    cout << "\nThe array elements after sorting: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
}

int Demo::getSize() {
    return n;
}

int main() {
    Demo d;
    d.get();

    if (d.getSize() > 0) {
        cout << "\nAfter ascending sort:"; // Start sorting process
        d.sort(); // Sort the array
        d.disp(); // Display the final sorted array
    }

    return 0;
}


// */ Output */
// Enter the array size 5
// Enter the array element:
// The array element are:10 3 335 33 355
// After ascending sort
// 0 3 5 3 5
// 3 5 0 3 1
// 3 3 0 0 0
// The array element are 355 335 33 10 3