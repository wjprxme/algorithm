#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool solve(string s) {
    if (s.size() == 2) {
        return s == "01";
    }
    string a = "", b = "";
    for (int i = 0; i < s.size();i++){
        if (i < s.size() / 2) {
            a += s[i];
        }
        else {
            b += s[i];
        }
    }
    bool x = solve(a);
    reverse(a.begin(), a.end());
    bool y = solve(a);
    bool z = solve(b);
    return (x || y) && z; 
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    int n, k;
    cin >> n >> k;
    while (n--) {
        string s = "";
        int size = pow(2, k);
        for (int i = 0; i < size; i++) {
            string t;
            cin >> t;
            s += t;
        }
        if (solve(s)) {
            cout << "yes";
        }
        else {
            cout << "no";
        }
    }
}
