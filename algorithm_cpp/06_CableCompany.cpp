#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, w, sum = 0; cin >> N;
    vector<vector<int> > cost(N, vector<int>(N, 0));
    for ( int i = 0; i < N; i++ ) {
        for ( int j = i+1; j < N; j++ ) {
            cin >> w;
            cost[i][j] = cost[j][i] = w;
        }
    }
    vector<bool> taken(N, false);
    vector<int> d(N, 10e12);
    d[0] = 0;
    for ( int i = 0; i < N; i++ ) {
        int min = 10e12;
        int idx;
        for ( int i = 0; i < N; i++ ) {
            if ( !taken[i] && d[i] < min ) {
                min = d[i];
                idx = i;
            }
        }
        taken[idx] = true;
        sum += d[idx];

        for ( int j = 0; j < N; j++ ) {
            if ( !taken[j] && d[j] > cost[idx][j] ) {
                d[j] = cost[idx][j];
            }
        }
    }
    cout << sum;
}

