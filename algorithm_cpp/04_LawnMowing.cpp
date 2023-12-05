#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    long long a;
    vector<long long> A(n + 1);
    A[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        A[i] = A[i - 1] + a;
    }
    while (m--) {
        long long l, budget;
        cin >> l >> budget;
        long long left = l, right = n + 1;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long sum = A[mid] - A[l] + (mid - l) * k;
            if (sum <= budget) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        cout << A[left - 1] - A[l] << endl;
    }
}
