#include <iostream>
#include <vector>
using namespace std;

bool safe(int row, int col, vector <int>& colplacement) {
    for (int prevrow = 0; prevrow < row; prevrow++) {
        int prevcol = colplacement[prevrow];
        if (prevcol == col || abs(prevrow - row) == abs(prevcol - col)) {
            return false;
        }
    }
    return true;
}

void check(int row, int n, vector <int>& colplacement, int& count) {
    if (row == n) {
        count++;
        return;
    }
    for (int col = 0; col < n; col++) {
        if (safe(row, col, colplacement)) {
            colplacement[row] = col;
            check (row + 1, n, colplacement, count);
        }
    }
}

int ways(int n) {
    vector <int> colplacement(n, 0);
    int count = 0;
    check(0, n, colplacement, count);
    return count;
}

int main() {
    int n;
    cin >> n;
    cout << ways(n);
}