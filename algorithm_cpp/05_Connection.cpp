#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs(vector<vector<bool> >& edge, vector<bool>& visited, 
vector<int>& distance, int start, int k, int& maxfriends) {
    queue<int> q;
    distance[start] = 0;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int idx = q.front();
        q.pop();
        if (distance[idx] == k) continue;
        for (int j = 0; j < edge.size(); j++) {
            if (edge[idx][j] && !visited[j]) {
                visited[j] = true;
                distance[j] = distance[idx] + 1;
                q.push(j);
                maxfriends++;
            }
        }
    }
}
int main() {
    int n, e, k;
    cin >> n >> e >> k;
    vector <vector<bool> > edge(n, vector<bool>(n, false));
    vector <bool> visited(n, false);
    vector <int> distance(n, n);
    for (int i = 0; i < e; i++) {
        int b, c;
        cin >> b >> c;
        edge[b][c] = edge[c][b] = true;
    }
    int maxfriends = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[j] = false;
            distance[j] = n;
        }
        int count = 1;
        bfs(edge, visited, distance, i, k, count);
        maxfriends = max(maxfriends, count);
    }
    cout << maxfriends << endl;
}
