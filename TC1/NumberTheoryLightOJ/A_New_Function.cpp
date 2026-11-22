#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
ll sum(ll l, ll r){
    if (l > r) return 0;
    return (r * (r + 1)) / 2 - ((l - 1) * l) / 2;
}
void Solve()
{
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i=2; i*i <= n; i++){
        ll cnt = (n/i) - 1;
        if(cnt > 0) ans += i * cnt;
    }
    for(ll i=2; i*i <= n; i++){
        ll l = max((ll)sqrt(n), n/(i + 1));
        ll r = n / i;
        if(l < r) ans += (i - 1) * sum(l+1, r);
    }
    cout << ans << endl;
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