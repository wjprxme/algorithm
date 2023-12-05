#include <iostream>
#include <vector>
using namespace std;

int main() {
    int r, c, t;
    cin >> r >> c >> t;

    vector <vector <int> > v(r, vector <int> (c));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> v[i][j];
        }
    }

    for (int day = 1; day <= t; day++) {
        vector <vector <int> > newv = v;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (v[i][j] == 1) {
                    if (i > 0 && v[i - 1][j] != 2) {
                        newv[i - 1][j] = 1;
                    }
                    if (i < r - 1 && v[i + 1][j] != 2) {
                        newv[i + 1][j] = 1;
                    }
                    if (j > 0 && v[i][j - 1] != 2) {
                        newv[i][j - 1] = 1;
                    }
                    if (j < c - 1 && v[i][j + 1] != 2) {
                        newv[i][j + 1] = 1;
                    }
                }
            }
        }
        v = newv;
    }
    int sum = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (v[i][j] == 1) {
                sum++;
            }
        }
    }
    cout << sum;
}
