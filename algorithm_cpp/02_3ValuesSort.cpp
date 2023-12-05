#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector <int> v(n);
    vector <int> count(4, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == 1) {count[1]++;}
        else if (v[i] == 2) {count[2]++;}
        else if (v[i] == 3) {count[3]++;}
    }
    vector <int> sorted_v = v;
    vector <int> c(4, 0);
    sort(sorted_v.begin(), sorted_v.end());
    for (int i = 0; i < n; i++) {
        if (i < count[1] && v[i] == 2) {
            c[2]++;
        }
        else if (i < count[1] && v[i] == 3) {
            c[3]++;
        }
        else if (i >= count[1] && i < count[1] + count[2] && v[i] == 1 && c[2] == 0) {
            c[1]++;
        }
        else if (i >= count[1] && i < count[1] + count[2] && v[i] == 1 && c[2] > 0) {
            c[0]++;
            c[2]--;
        }
        else if (i >= count[1] && i < count[1] + count[2] && v[i] == 3) {
            c[3]++;
        }
        else if (i >= count[1] + count[2] && v[i] == 1) {
            c[0]++;
            c[3]--;
        }
        else if (i >= count[1] + count[2] && v[i] == 2) {
            c[0]++;
            c[3]--;
        }
    }
    cout << c[0] + c[1] + c[2] + c[3];