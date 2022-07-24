#include <bits/stdc++.h>
using namespace std;
#define int long long
void hocusPocus()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(v[i]);
        if (i == k - 1)
            cout << pq.top() << '\n';
        if (i >= k)
            pq.pop(), cout << pq.top() << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    hocusPocus();
}