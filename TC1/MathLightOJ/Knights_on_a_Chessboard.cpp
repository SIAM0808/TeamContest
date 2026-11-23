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
    int n, m;
    cin >> n >> m;
    int mn = min(m, n);
    int mx = max(m, n);
    int ans = 0;

    if (mn == 1) {
        ans = mx;
    } 
    else if (mn == 2) {
        ans = (mx / 4) * 4;
        int rem = mx % 4;
        if (rem == 1) ans += 2;
        else if (rem >= 2) ans += 4;
    } 
    else {
        ans = (m * n + 1) / 2;
    }

    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for(int i=1; i<=t; i++){
        cout << "Case " << i << ": ";
        Solve();
    }
    return 0;
}