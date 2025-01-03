#include <iostream>
using namespace std;

class dfstree {
    int a[20][20], visited[20], n, i, j;
public:
    void dfs(int);
    void get();
};

void dfstree::get() {
    cout << "\nEnter the number of nodes: ";
    cin >> n;

    for(i = 0; i < n; i++) {
        visited[i] = 0; // Initialize all nodes as unvisited
    }

    cout << "\nEnter the adjacency matrix:\n";
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            cin >> a[i][j]; // Input adjacency matrix
        }
    }

    cout << "DFS Traversal starting from node 1:\n";
    dfs(0); // Start DFS from node 0 (first node)
}

void dfstree::dfs(int v) {
    visited[v] = 1; // Mark the current node as visited
    cout << "\t" << v + 1; // Print the node number (1-based indexing)

    // Visit all the adjacent nodes that are not visited yet
    for(int k = 0; k < n; k++) {
        if(a[v][k] == 1 && visited[k] == 0) {
            dfs(k); // Recursively visit the unvisited adjacent node
        }
    }
}

int main() {
    dfstree d;
    d.get(); // Get the input and start DFS traversal
    return 0;
}

// */ Output */
// Enter the number of node5
// Enter the adjancy matrix:
// 0 1 1 0 0
// 1 0 0 1 1
// 1 0 0 1 0
// 0 1 1 0 1
// 0 1 0 1 0
// 1 2 4 3 5