#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;

int binToDec(int n)
{
    int dec = 0, base = 1;
    while (n > 0) {
        int rem = n % 10;
        dec += rem * base;
        n /= 10;
        base *= 2;
    }
    return dec;
}

void Solve()
{
    int a, b, c, d;
    char dot;
    cin >> a >> dot >> b >> dot >> c >> dot >> d;

    int ba, bb, bc, bd;
    cin >> ba >> dot >> bb >> dot >> bc >> dot >> bd;

    if (a == binToDec(ba) && b == binToDec(bb) && c == binToDec(bc) && d == binToDec(bd)) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        Solve();
    }
    return 0;
}