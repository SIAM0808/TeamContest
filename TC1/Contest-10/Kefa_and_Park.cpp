#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
int sz = 1e5 + 10;
vector<int> vis(sz);
int ans = 0;
void dfs(vector<vector<int>>&v, int node, int par, vector<int>& cat, int m, int conct){
    if(cat[node]){
        conct++;
    }else conct = 0;
    if(conct > m) return;
    bool lf = true;
    // vis[node] = 1;
    for(int i : v[node]){
        if(i != par){
            lf = false;
            dfs(v, i, node, cat, m, conct);
        }
    }
    if(lf) ans++;
}
void Solve()
{
    fill(vis.begin(), vis.end(), 0);
    int n, m;
    cin >> n >> m;
    vector<int> cat(n+1);
    for(int i=1; i<=n; i++) cin >> cat[i];
    vector<int> par(n+1);
    par[1] = 1;
    vector<vector<int>> v(n+1);
    for(int i=0; i<n-1; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<int> leaf(n+1);
    dfs(v, 1, -1, cat, m, 0);

    cout << ans << endl;
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