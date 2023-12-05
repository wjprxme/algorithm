#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int f, w, n;
    cin >> f >> w >> n;
    set <int> s;
    int x;
    for (int i = 0; i < f; i++) {
        cin >> x;
        s.insert(x);
    }
    int last = - w - 1, ans = 0;
    for (auto &itr : s) {
        if (itr <= last + w) {
            continue;
        }
        last = itr + w;
        ans++;
    }
    cout << ans;
}
