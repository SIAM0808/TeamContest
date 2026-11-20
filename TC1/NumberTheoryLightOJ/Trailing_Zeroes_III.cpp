#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
const long long mod = 1000000007;

vector<long long> fact;

void Solve()
{
    ll q;
    cin >> q;
    auto tz = [&](ll x) -> ll{
        ll cnt = 0;
        while(x) x /= 5, cnt += x;
        return cnt;
    };
    ll l = 5, r = 1e18;
    ll ans = -1;
    while(l <= r){
        ll mid = (l + r) >> 1;
        ll val = tz(mid);
        if(val >= q){
            if(val == q) ans = mid;
            r = mid - 1;
        }else l = mid + 1;
    }
    if(ans == -1) cout << "impossible" << endl;
    else cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for(ll i=1; i<=t; i++){
        cout << "Case " << i << ": ";
        Solve();
    }
    return 0;
}