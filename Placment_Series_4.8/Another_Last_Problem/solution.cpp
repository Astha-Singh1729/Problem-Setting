#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mx = 101;
class segU
{
    struct element
    {
        int value;
        vector<int> v;
    };
    int n;
    vector<element> t;
    element null = {0, vector<int>(mx, 0)};

    void point_update(int v, int l, int r, element value, int pos)
    {

        if (r - l == 1)
        {
            t[v] = value;
            return;
        }

        int mid = (l + r) / 2;
        if (pos < mid)
            point_update(v * 2, l, mid, value, pos);
        else
            point_update(v * 2 + 1, mid, r, value, pos);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }

    element ans_chahiye(int l, int r, int ql, int qr, int v)
    {
        if (l >= ql && r <= qr)
            return t[v];
        if (r <= ql || qr <= l)
            return null;
        int mid = (l + r) / 2;
        return merge(ans_chahiye(l, mid, ql, qr, v * 2), ans_chahiye(mid, r, ql, qr, v * 2 + 1));
    }

    element merge(element a, element b)
    {
        element c = null;
        c.value = a.value + b.value;
        for (int i = 1; i < mx; i++)
            c.v[i] = a.v[i] + b.v[i];
        return c;
    }

public:
    segU(int n)
    {
        this->n = n;
        t.resize(4 * n, null);
    }

    void point_update(int pos, int value)
    {
        vector<int> v(mx);
        for (int i = 1; i < mx; i++)
            if ((value % i) == 0)
                v[i] = value;
        point_update(1, 0, n, {value, v}, pos);
    }

    element ans_chahiye(int ql, int qr)
    {
        return ans_chahiye(0, n, ql, qr, 1);
    }
};
void hocusPocus()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    segU nhp(n);

    for (int i = 0; i < n; i++)
        cin >> v[i], nhp.point_update(i, v[i]);

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 2)
        {
            int l, r, k;
            cin >> l >> r >> k;
            cout << nhp.ans_chahiye(l - 1, r).v[k] << endl;
            continue;
        }
        int pos, value;
        cin >> pos >> value;

        nhp.point_update(pos - 1, value);
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    hocusPocus();
}