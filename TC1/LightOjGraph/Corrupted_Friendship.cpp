#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
vector<ll> sub;
ll dfs(ll c, ll p, vector<vector<ll>>& v){
    ll ans = 1;
    for(ll i : v[c]){
        if(i != p){
            ans += dfs(i, c, v);
        }
    }
    sub[c] = ans - 1;
    return ans;
}
void Solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> v(n+1);
    sub.assign(n+1, 0);
    for(ll i=0; i<n-1; i++){
        ll x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    ll ans = dfs(1, -1, v);
    ll cnt = 0;
    for(ll i=1; i<=n; i++){
        cnt += sub[i];
    }
    cout << n - 1 << " " << (n*(n-1))/2 - cnt << "\n";
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