#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
    int n, e;
    cin >> n >> e;
    unordered_map <int, int> nodecolor;
    unordered_map <int, vector <int> > adj; 
    while (e--) {
        int a, b;
        cin >> a >> b;
        nodecolor[a] = 1;
        nodecolor[b] = 1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (auto &node : adj) {
        for (auto &adjnode : node.second) {
            if (nodecolor[node.first] == nodecolor[adjnode]) {
                nodecolor[adjnode]++;
            }
        }
    }
    int minnodecolor = 1;
    for (auto &color : nodecolor) {
        if (minnodecolor < color.second) {
            minnodecolor = color.second;
        }
    }
    int tmp = minnodecolor;
    for (auto &node : adj) {
        for (auto &adjnode : node.second) {
            if (nodecolor[node.first] == nodecolor[adjnode]){
                nodecolor[adjnode]++;
            }
        }
    }
    for (auto &color : nodecolor) {
        if (minnodecolor < color.second) {
            minnodecolor = color.second;
        }
    }
    if (tmp == minnodecolor - 1) {
        tmp--;
    }
    cout << tmp;
}
