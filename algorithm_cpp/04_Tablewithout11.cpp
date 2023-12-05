#include <iostream>
#include <map>
using namespace std;

map <long long, long long> memo;
long long recur(long long n) {
    if (n == 2) {
        return 7;
    } 
    else if (n == 3) {
        return 17;
    }
    if (n > 3) {
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }
    }
    long long result = 2 * recur(n - 1) + recur(n - 2);
    memo[n] = result % 100000007;
    return memo[n];
}

int main() {
    long long n;
    cin >> n;
    cout << recur(n) << endl;
}
