#include <iostream>
#include <climits>
using namespace std;

class single {
    int n;
    int cost[10][10], s[10], e[10], near1[10], t[10][3], m, minedge, k, l, mincost;
    int jindex;
    
public:
    void get();
    void prim();
    void display();
};

void single::get() {
    m = 1;
    minedge = INT_MAX;
    cout << "\nEnter the number of vertices: ";
    cin >> n;
    
    cout << "\nEnter the Adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            if (cost[i][j] == -1) {
                cost[i][j] = INT_MAX;
            }
            else {
                e[m] = cost[i][j];
                if (e[m] < minedge) {
                    minedge = e[m];
                    k = i;
                    l = j;
                }
                m++;
            }
        }
    }
}

void single::prim() {
    t[0][0] = k;
    t[0][1] = l;
    mincost = cost[k][l];

    for (int i = 0; i < n; i++) {
        if (cost[i][l] < cost[i][k]) {
            near1[i] = l;
        }
        else {
            near1[i] = k;
        }
    }

    near1[k] = near1[l] = 0;

    for (int i = 1; i < n - 1; i++) {
        int minj = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (near1[j] != 0) {
                if (cost[j][near1[j]] < minj) {
                    minj = cost[j][near1[j]];
                    jindex = j;
                }
            }
        }

        t[i][0] = jindex;
        t[i][1] = near1[jindex];
        mincost += cost[jindex][near1[jindex]];
        near1[jindex] = 0;

        for (int k1 = 0; k1 < n; k1++) {
            if (near1[k1] != 0 && cost[k1][near1[k1]] > cost[k1][jindex]) {
                near1[k1] = jindex;
            }
        }
    }

    cout << "\nMinimum cost = " << mincost;
}

void single::display() {
    cout << "\nMinimum Spanning Tree Path:\n";
    cout << t[0][0] + 1 << " -> " << t[0][1] + 1;  // Output as 1-based index
    for (int i = 1; i < n - 1; i++) {
        cout << " -> " << t[i][0] + 1 << " -> " << t[i][1] + 1;
    }
    cout << endl;
}

int main() {
    single d;
    d.get();
    d.prim();
    d.display();
    return 0;
}

// */ Output */
// Enter the no. of vertices
// 7
// Enter the Adjacenecy matrix
// -1 28 -1 -1 -1 10 -1
// 28 -1 16 -1 -1 -1 14
// -1 16 -1 12 -1 -1 -1
// -1 -1 12 -1 22 -1 18
// -1 -1 -1 22 -1 25 24
// 10 -1 -1 -1 25 -1 -1
// -1 14 -1 18 24 -1 -1
// Mincost =99
// Minimum Spanning Tree Path as follow
// 1->6->5->4->3->2->7