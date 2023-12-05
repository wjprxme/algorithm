#include <iostream>
#include <vector>
using namespace std;
bool found = false;
int ans = 0;
void dfs(vector <vector <int> > &adj , vector <bool> &visited , 
vector <int> &distance , int v , int depth , int parent){
    visited[v] = true;
    distance[v] = depth;
    for (int i = 0; i < adj[v].size(); i++){
        if (!visited[adj[v][i]]) {
            dfs(adj, visited, distance, adj[v][i], depth + 1, v);
        }
        else if(visited[adj[v][i]] && adj[v][i] != parent){
            if (!found) {
                ans = depth + 1 - (distance[adj[v][i]]);
                found = true;
            }
            return; 
        }
    }
    visited[v] = false;
}
int main(){
    int n;
    cin >> n;
    vector <vector <int> > adj(n);
    for(int i = 0 ; i < n ; i++){
        int a , b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector <int> distance(n);
    vector <bool> visited(n, false);
    dfs(adj, visited, distance, 0, 0, -1);
    cout << ans;
}
