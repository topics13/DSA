#include <iostream>
#include <queue>
using namespace std;

class bfstree {
    int reach[20], a[20][20], n, i, j;
public:
    bfstree() {
        for (i = 0; i < 20; i++) reach[i] = 0;
    }
    void get();
    void bfs();
};

void bfstree::get() {
    cout << "\nEnter number of vertices: ";
    cin >> n;
    cout << "\nEnter the adjacency matrix:\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
}

void bfstree::bfs() {
    queue<int> q;
    reach[1] = 1; // Start BFS from node 1 (index 1 in 1-based indexing)
    q.push(1); // Enqueue the starting node (node 1)

    cout << "\nBFS Traversal: ";
    while (!q.empty()) {
        int index = q.front();
        cout << index << "\t";
        q.pop();

        // Check all adjacent nodes
        for (j = 1; j <= n; j++) {
            if (a[index][j] == 1 && reach[j] == 0) {
                reach[j] = 1; // Mark the node as visited
                q.push(j); // Enqueue the node
            }
        }
    }
}

int main() {
    bfstree b;
    b.get();
    b.bfs(); // Perform BFS
    return 0;
}

// */ Output */
// Enter number of vertices:6
// Enter Adjacency matrix:
// 0 1 1 0 0 0
// 1 0 0 1 0 0
// 1 0 0 0 0 1
// 0 1 0 0 1 1
// 0 0 0 1 0 0
// 0 0 1 1 0 0
// BFS is 1 2 3 4 6 5