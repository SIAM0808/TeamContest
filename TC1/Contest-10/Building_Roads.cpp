#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
void dfs(vector<vector<int>> &g, vector<int> &vis, int u, int v){
    vis[u] = 1;
    for(int i : g[u]){
        if(!vis[i]) dfs(g, vis, i, u);
    }
}
void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> ans;
    vector<int> vis(n+1);
    vector<vector<int>> v(n+1);
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int prev = -1;
    for(int i = 1; i<=n; i++){
        if(!vis[i]){
            if(prev != -1)
            ans.push_back({prev, i});
            dfs(v, vis, i, prev);
            prev = i;
        }
    }
    cout << ans.size() << endl;
    for(auto [x, y] : ans) cout << x << " " << y << endl;
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