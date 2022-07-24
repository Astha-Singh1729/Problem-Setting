#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    int n = rnd.next(1, 100000);
    int q = rnd.next(1, 100000);
    cout << n << " " << q << endl;
    for (int i = 0; i < n; i++)
    {
        long long a = rnd.next(1LL, 1000000000LL);
        cout << a;
        if (i != n - 1)
            cout << " ";
    }
    cout << endl;
    for (int i = 0; i < q; i++)
    {
        int type = rnd.next(1, 2);
        if (type == 2)
        {
            cout << 2 << " ";
            int l = rnd.next(1, n);
            int r = rnd.next(l, n);
            int k = rnd.next(1, 100);
            cout << l << " " << r << " " << k << endl;
        }
        else
        {
            cout << 1 << " ";
            int pos = rnd.next(1, n);
            int value = rnd.next(1LL, 1000000000LL);
            cout << pos << " " << value << endl;
        }
    }
}
