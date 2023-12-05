#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int> > v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].second;
    }

    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
    }
    sort(v.begin(), v.end());
    
    int interval = 0, sum = 0;

    for (int i = 0; i < n; i++) {
        if (v[i].second >= interval) {
            interval = v[i].first;
            sum++;
        }
    }

    cout << sum;
}
