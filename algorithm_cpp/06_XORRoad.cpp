// Prim's Algorithm - Maximum Spanning Tree

#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long n, c;
    cin >> n;
    vector<long long> node(n);
    vector<long long> max_d (n, -1);
    vector<bool> visited(n, false);
    for (long long i = 0; i < n; i++){
        cin >> node[i];
    }
    long long ans = 0;
    max_d[0] = 0;

    for (long long round = 0; round < n; round++){
        //find max node
        long long max = -1;
        long long u;
        for (long long i = 0; i < n; i++){
            if (max_d[i] > max && !visited[i]){
                max = max_d[i];
                u = i;
            }
        }
        visited[u] = true;
        ans += max_d[u];

        //update
        for (long long v = 0; v < n; v++){
            long long len = node[u] ^ node[v];
            if (len > max_d[v] && !visited[v] )
                max_d[v] = len;
        }
    }
    cout << ans;
}

