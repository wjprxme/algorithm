#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int n, m, k, w, cnt = 0, sum = 0;
void solve(vector<vector<int> > &tower, vector<int> &monpos, int idx, vector<int> &monhp) {
    if (idx < k) {
        for (int i = 0; i < tower[idx].size(); i++) {
            if (monpos[tower[idx][i]] > 0) {continue;}
            monpos[tower[idx][i]]--;
            break;
        }
        solve(tower, monpos, idx + 1, monhp);
    }
    else {
        for (int i = 0; i < m; i++) {cnt += monhp[i] - monpos[i];}
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k >> w;
    vector<pair<int, int> > monster(m);
    vector<int> monpos(m, 0), monhp(m, 0), towpos(k);
    vector<vector<int> > tower(k);
    for (int i = 0; i < m; i++) {cin >> monster[i].first;}
    for (int i = 0; i < m; i++) {cin >> monster[i].second;}
    sort(monster.begin(), monster.end());
    for (int i = 0; i < m; i++) {
        monpos[i] = monster[i].second;
        monhp[i] = monster[i].second;
        sum += monster[i].second;
    }
    for (int i = 0; i < k; i++) {cin >> towpos[i];}
    sort(towpos.begin(), towpos.end());
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            if (monster[j].first >= towpos[i] - w && monster[j].first <= towpos[i] + w) {
                tower[i].push_back(j);
            }
        }
    }
    solve(tower, monpos, 0, monhp);
    cout << sum - cnt;
}