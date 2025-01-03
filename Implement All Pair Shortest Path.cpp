#include <iostream>
using namespace std;

class Path {
    int a[5][5], i, j, k, n, s, d;

public:
    void insert();
    void display();
};

void Path::insert() {
    cout << "\nEnter the number of vertices: ";
    cin >> n;
    cout << "\nEnter the matrix (use -1 for no direct path between vertices):\n";
    
    // Input matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == -1 && i != j)  // No path between different vertices
                a[i][j] = 9999;  // Set a large value for no path
        }
    }

    // Floyd-Warshall algorithm to find shortest paths
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (a[i][j] > a[i][k] + a[k][j]) {
                    a[i][j] = a[i][k] + a[k][j];  // Update shortest path
                }
            }
        }
    }
}

void Path::display() {
    // Display the shortest path matrix
    cout << "\nShortest path matrix:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] == 9999)
                cout << "INF\t";  // INF represents no path
            else
                cout << a[i][j] << "\t";
        }
        cout << "\n";
    }

    // Ask for the source and destination vertices
    cout << "\nEnter the source vertex (0-based index): ";
    cin >> s;
    cout << "\nEnter the destination vertex (0-based index): ";
    cin >> d;

    // Display the shortest path from source to destination
    cout << "\nThe shortest path from vertex " << s << " to vertex " << d << " is: ";
    if (a[s][d] == 9999)
        cout << "No path exists\n";
    else
        cout << a[s][d] << "\n";
}

int main() {
    Path p;
    p.insert();
    cout << "\nShortest path is:\n";
    p.display();
    return 0;
}

// */ Output */
// Enter the no. of vertices 3
// Enter the matrix:0 4 11
// 6 0 2
// 3 -1 0
// Shortest path is
// 0 4 6
// 5 0 2
// 3 7 0
// Enter the source vertex:3
// Enter the destination vertex:2
// Path from Source 3 to destination 2 is 7