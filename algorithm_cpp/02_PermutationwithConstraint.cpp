#include <iostream>
#include <vector>
using namespace std;

int n, m;

void permutation(vector<int> currentPermutation, vector<bool> isUsed, vector<int> parent) {
    if (currentPermutation.size() == n) {
        for (int i = 0; i < n; i++) {
            cout << currentPermutation[i] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!isUsed[i] && (parent[i] == -1 || isUsed[parent[i]])) {
            isUsed[i] = true;
            currentPermutation.push_back(i);

            permutation(currentPermutation, isUsed, parent);
            
            isUsed[i] = false;
            currentPermutation.pop_back();
        }
    }
}

int main() {
    cin >> n >> m;

    vector <int> currentPermutation;
    vector <bool> isUsed(n, false);
    vector <int> parent(n, -1);

    int p, q;

    while (m--) {
        cin >> p >> q;
        parent[q] = p;
    }

    permutation(currentPermutation, isUsed, parent);
}