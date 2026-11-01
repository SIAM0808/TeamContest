#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
bool bptr;
ll c1 = 0, c2 = 0;
ll mod = 998244353;
vector<vector<ll>> v;
vector<ll> color;
void dfs(ll u, ll c){
    color[u] = c;
    if(c == 0) c1++;
    else c2++;
    for(ll i : v[u]){
        if(color[i] == c) bptr = false;
        if(color[i] == -1) dfs(i, 1 - c);
    }
}
long long binexp(long long a, long long b) {
    long long res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void Solve()
{
    ll n, m;
    cin >> n >> m;
    v.assign(n+1, vector<ll>());
    color.assign(n+1, -1);
    for(ll i=0; i<m; i++){
        ll x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    ll ans = 1;
    for(ll i=1; i<=n; i++){
        if(color[i] == -1){
            c1 = 0, c2 = 0;
            bptr = true;
            dfs(i, 0);
            if(!bptr){
                cout << 0 << endl;
                return;
            }
            ll tem = (binexp(2, c1) + binexp(2, c2)) % mod;
            ans = (ans * tem) % mod;
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}