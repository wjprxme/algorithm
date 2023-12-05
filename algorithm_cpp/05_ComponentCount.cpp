#include <iostream>
#include <vector>
using namespace std;

void dfs(vector <vector <int> > &adj, vector <bool> &visited, int i) {
    visited[i] = true;
    for (int j = 0; j < adj[i].size(); j++) {
        if (visited[adj[i][j]] == false) {
            dfs(adj, visited, adj[i][j]);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int v, e;
    cin >> v >> e;
    vector <vector <int> > adj(v + 1);
    vector <bool> visited(v + 1, false);
    while (e--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int count = 0;
    for (int i = 1; i < v + 1; i++) {
        if (visited[i] == false) {
            dfs(adj, visited, i);
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
