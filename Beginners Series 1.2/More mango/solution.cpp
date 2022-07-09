#include <bits/stdc++.h>
using namespace std;
#define int long long
void hocusPocus()
{
    int w, h, n;
    cin >> w >> h >> n;
    int lo = 0;
    int hi = (sqrt(n) + 1) * (sqrt(h) + 1) * (sqrt(w) + 1) + 1000;
    auto check = [w, h, n](int a) -> bool
    {
        return ((a / w) * (a / h) >= n);
    };
    while (hi - lo > 1)
    {
        int m = (lo + hi) / 2;
        if (check(m))
            hi = m;
        else
            lo = m;
    }
    cout << hi << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    hocusPocus();
}