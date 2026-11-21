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
    ll x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll val = __gcd(abs(x1 - x2), abs(y1 - y2));
    cout << val + 1 << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        Solve();
    }
    return 0;
}