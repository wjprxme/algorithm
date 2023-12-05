#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v[2 * n - 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            v[i - j + n - 1].push_back(a);
        }
    }
    int m2 = 0;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        int m = 0, sum = 0;
        for (auto x : v[i])
        {
            sum += x;
            if (sum < 0)
                sum = 0;
            if (sum > m)
                m = sum;
        }
        if (m > m2)
            m2 = m;
    }
    cout << m2;
}
