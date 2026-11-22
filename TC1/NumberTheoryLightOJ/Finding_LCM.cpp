#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;

void Solve()
{
    ll a, b, l;
    cin >> a >> b >> l;
    ll gd = __gcd(a, b);
    ll lcm = (a * b) / gd;
    if (l % lcm != 0)
    {
        cout << "impossible" << endl;
        return;
    }
    ll c = l / lcm;
    ll g = __gcd(c, lcm);
    while (g > 1)
    {
        c *= g;
        lcm /= g;
        g = __gcd(c, lcm);
    }
    cout << c << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        cout << "Case " << i << ": ";
        Solve();
    }
    return 0;
}