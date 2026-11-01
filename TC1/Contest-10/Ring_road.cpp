#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif
#define int long long
using ll = long long;
int cost = 0;
vector<int> w;
map<pair<int, int>, int> mp;
vector<vector<int>> v;
vector<int> vis;
void dfs(int c, int u){
    debug(c);
    vis[c] = 1;
    for(int i : v[c]){
        if(vis[i] && i != u) cost += mp[{c, i}];
        if(!vis[i]){
            dfs(i, c);
            cost += mp[{c, i}];
            break;
        }
    }
}
void Solve()
{
    int n;
    cin >> n;
    v.assign(n+1, vector<int>{});
    // w.assign(n+1, 0);
    vis.assign(n+1, 0);
    int sum = 0;
    for(int i=0; i<n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        // debug(x);
        // debug(y);
        // debug(z);
        // debug(i);
        v[x].push_back(y);
        v[y].push_back(x);
        sum += z;
        mp[{x, y}] = z;
    }
    dfs(1, -1);
    debug(sum);
    debug(cost);
    // for(int i=1; i<=n; i++) cerr << w[i] << " ";
    // for(int i=1; i<=n-1; i++) sum += w[i];
    cout << min(cost, sum - cost) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--)
        Solve();
    return 0;
}