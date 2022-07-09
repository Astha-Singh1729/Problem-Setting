#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    long long w = rnd.next(1LL, (long long)1e9);
    long long h = rnd.next(1LL, (long long)1e9);
    long long n = rnd.next(1LL, (long long)1e9);
    cout << w << " " << h << " " << n << endl;
}
