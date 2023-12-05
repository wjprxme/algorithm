#include <iostream>
#include <vector>
using namespace std;
bool dfs(vector <vector <int> > &adj, vector <bool> &visited, int i, int parent) {
    visited[i] = true;
    for (int j = 0; j < adj[i].size(); j++) {
        if (visited[adj[i][j]] == false) {
            if (dfs(adj, visited, adj[i][j], i)) {
                return true;
            }
        }
        else if (adj[i][j] != parent) {
            return true;
        }
    }
    return false;
}
bool circuit (vector <vector <int> > &adj, vector <bool> &visited, int i) {
    for (int i = 0; i < visited.size(); i++) {
        visited[i] = false;
    }
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] == false) {
            if (dfs(adj, visited, i, -1)) {
                return true;
            }
        }
    }
    return false;
}
int main () {
    int t;
    cin >> t;
    while (t--) {
        int n, e;
        cin >> n >> e;
        vector <vector <int> > adj(n);
        vector <bool> visited(n, false);
        while (e--) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if (circuit(adj, visited, n)) {cout << "YES" << endl;}
        else {cout << "NO" << endl;}
    }
}