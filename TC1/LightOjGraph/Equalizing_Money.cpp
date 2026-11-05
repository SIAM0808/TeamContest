#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
ll money = 0;
ll sz = 0;
void dfs(vector<vector<ll>> &v, vector<ll> &p, vector<ll> &vis, ll u){
    vis[u] = 1;
    sz++;
    money += p[u];
    for(ll i : v[u]){
        if(!vis[i]) dfs(v, p, vis, i);
    }
}
void Solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> p(n+1);
    for(ll i=1; i<=n; i++) cin >> p[i];
    vector<vector<ll>> v(n+1, vector<ll>{});
    for(ll i=0; i<m; i++){
        ll x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<ll> vis(n+1, 0);
    set<int> st;
    for(ll i=1; i<=n; i++){
        if(!vis[i]){
            sz = 0;
            money = 0;
            dfs(v, p, vis, i);
            if(money % sz != 0){
                cout << "No" << endl;
                return;
            }
            st.insert(money / sz);
        }
    }
    if(st.size() > 1) cout << "No" << endl;
    else    
    cout << "Yes" << endl;
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