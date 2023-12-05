#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void recur(vector<vector<int> > &v, int a, int b, int top, int bottom, int left, int right) {
    if (a == 0) {
        v[top][left] = b;
        return;
    }
    int midRow = top + (bottom - top) / 2;
    int midCol = left + (right - left) / 2;
    recur(v, a - 1, b, top, midRow, left, midCol);
    recur(v, a - 1, b - 1, top, midRow, midCol, right);
    recur(v, a - 1, b + 1, midRow, bottom, left, midCol);
    recur(v, a - 1, b, midRow, bottom, midCol, right);
}

int main() {
    int a, b;
    cin >> a >> b;
    int size = pow(2, a);
    vector<vector<int> > matrix(size, vector<int>(size, 0));
    recur(matrix, a, b, 0, size, 0, size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
