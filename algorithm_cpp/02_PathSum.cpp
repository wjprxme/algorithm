#include <iostream>
#include <vector>
using namespace std;
void checkAns(const vector<vector<int> >& adj, const vector<int>& maxWeight, const int& n, int cap,
            vector<bool>& visited, int curNode, int curSum,
            int goal, bool& found) {
    if (curSum == goal) {
        found = true;
        return;
    }
    if (curSum > goal || curSum + cap < goal) {return;}
    visited[curNode] = true;
    for (int i = 0; i < n; ++i) {
        if (adj[curNode][i] && !visited[i]) {
            checkAns(adj, maxWeight, n, cap - maxWeight[i], visited, i, curSum + adj[curNode][i], goal, found);
            if (found) return;
        }
    }
    visited[curNode] = false;
    return;
}
int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n, m; cin >> n >> m;
    int ansWeight[8];
    vector<int> maxWeight(n);
    int cap = 0;
    vector<vector<int> > adj(n, vector<int>(n, 0));
    for (int i = 0; i < 8; i++) {cin >> ansWeight[i];}
    for (int i = 0; i < m; ++i) {
        int a, b, w; cin >> a >> b >> w;
        adj[a][b] = adj[b][a] = w;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {maxWeight[i] = max(maxWeight[i], adj[i][j]);}
        cap += maxWeight[i];
    }
    for (int i = 0; i < 8; i++) {
        bool found = false;
        for (int j = 0; j < n; ++j) {
            vector<bool> visited(n, false);
            checkAns(adj, maxWeight, n, cap - maxWeight[j], visited, j, 0, ansWeight[i], found);
            if (found) {cout << "YES"; break;}
        }
        if (!found) cout << "NO";
        cout << endl;
    }
}