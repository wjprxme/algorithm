#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector <vector <int> > &adj, vector <bool> &visited, int i, int &vertex) {
    visited[i] = true;
    if (adj[i].size() > 2) {
        return false;
    }
    else if (adj[i].size() == 1) {
        vertex++;
    }
    for (int j = 0; j < adj[i].size(); j++) {
        if (visited[adj[i][j]] == false) {
            dfs(adj, visited, adj[i][j], vertex);
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int v, e;
    cin >> v >> e;
    vector <vector <int> > adj(v);
    vector <bool> visited(v, false);
    while (e--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int count = 0;
    for (int i = 0; i < v; i++) {
        if (visited[i] == false) {
            int vertex = 0;
            if (dfs(adj, visited, i, vertex) && (vertex == 2 || adj[i].size() == 0)) {
                count++;
            } 
        }
    }
    cout << count << endl;
}
