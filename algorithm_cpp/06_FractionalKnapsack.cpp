#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    double w, n;
    cin >> w >> n;
    vector <pair <double, pair <double, double> > > item(n);
    for (auto &i : item) {
        cin >> i.second.first;
    }
    for (auto &i : item) {
        cin >> i.second.second;
        i.first = - i.second.first / i.second.second;
    }
    sort(item.begin(), item.end());
    double totalvalue = 0, totalweight = 0;
    for (auto &i : item) {
        if (totalweight + i.second.second > w) {
            totalvalue += i.second.first * (w - totalweight) / i.second.second;
            break;
        }
        totalvalue += i.second.first;
        totalweight += i.second.second;
    }
    cout << setprecision(4) << fixed << totalvalue ;
}

