#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a;
    cin >> n >> a;
    vector<int> cheftime(n);
    for (int i = 0; i < n; i++) {
        cin >> cheftime[i];
    }
    while (a--) {
        long long customer, seatingtime = -1;
        cin >> customer;
        long long lefttime = 1, righttime = pow(10,12);
        while (lefttime <= righttime) {
            long long midtime = lefttime + (righttime - lefttime) / 2;
            long long waitingtime = 0;
            for (int i = 0; i < cheftime.size(); i++) {
                waitingtime += (midtime / cheftime[i] + 1);
            }
            if (waitingtime >= customer) {
                seatingtime = midtime;
                righttime = midtime - 1;
            } 
            else {
                lefttime = midtime + 1;
            }
        }
        cout << seatingtime << endl;
    }
}
