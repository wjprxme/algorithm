#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> v(k);
    set<int> s;
    for (int i = 0; i < k; ++i) {
        cin >> v[i];
        s.insert(v[i]);
    }
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < v.size(); j++) {
            if (i >= v[j]) {
                dp[i] = (dp[i] + dp[i - v[j]]) % 1000003;
            }
        }
    }
    cout << dp[n] << endl;
}
