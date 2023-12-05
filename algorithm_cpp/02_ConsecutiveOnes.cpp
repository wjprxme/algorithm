#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int size1 = pow(2, n);
    for (int i = 0; i < size1; i++) {
        int consecutiveOnes = 0;
        for (int j = n - 1; j >= 0; j--) {
            int size2 = pow(2, j);
            if (i & size2) {
                consecutiveOnes++;
            } 
            else {
                consecutiveOnes = 0;
            }
            if (consecutiveOnes == k) {
                for (int l = n - 1; l >= 0; l--) {
                    int size3 = pow(2, l);
                    cout << (i / size3) % 2;
                }
                cout << endl;
                break;
            }
        }
    }
}