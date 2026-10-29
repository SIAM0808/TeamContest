#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
vector<ll> deg;
void dfs(vector<vector<ll>> &v, ll c, ll p){
    for(ll i : v[c]){
        if(i != p){
            dfs(v, i, c);
            deg[c]++;
        }
    }
}
void Solve()
{
    ll n;
    cin >> n;
    deg.assign(n+1, 0);
    vector<ll> w(n+1);
    for(ll i=1; i<=n; i++) cin >> w[i];
    vector<vector<ll>> v(n+1);
    for(ll i=0; i<n-1; i++){
        ll x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    // dfs(v, 1, -1);
    // for(ll i : deg) cerr << i << " ";

    priority_queue<pair<ll, ll>> pq;
    for(ll i=1; i<=n; i++){
        if(v[i].size() > 1)
        pq.push({w[i], i}), deg[i] = v[i].size();
    }
    ll sum = accumulate(w.begin(), w.end(), 0LL);
    for(ll i=1; i<=n-1; i++){
        if(i == 1) cout << sum << " ";
        else{
            auto p = pq.top();
            if(deg[p.second] > 1) sum += p.first, deg[p.second]--;
            if(deg[p.second] <= 1) pq.pop();
            cout << sum << " ";
        }
    }
    cout << endl;
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