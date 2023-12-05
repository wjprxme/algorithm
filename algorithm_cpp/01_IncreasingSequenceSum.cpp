#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    v[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            v[j] += v[j - i];
        }
    }
    cout << v[n] << endl;
} 

// #include <iostream>
// using namespace std;

// int n, total = 0;

// void iss(int sum, int idx) {
//     if (sum == n) {
//         total++;
//         return;
//     }
//     else if (sum < n) {
//         for (int i = idx; i <= n; i++) {
//             iss(sum + i, i);
//         }
//     }
// }

// int main () {
//     cin >> n;
//     iss (0, 1);
//     cout << total;
// }
