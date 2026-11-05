#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
vector<int> adj[105];
bool vis[105][2];

void dfs(int u, int c) {
    vis[u][c] = true;
    int nc = 1 - c;
    for (int v : adj[u]) {
        if (!vis[v][nc]) {
            dfs(v, nc);
        }
    }
}

void solve(int tc) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(vis, false, sizeof(vis));
    dfs(1, 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i][1] && !adj[i].empty()) {
            ans++;
        }
    }
    cout << "Case " << tc << ": " << ans << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for(int i=1; i<=t; i++){
        // cout << "Case " << i << ": ";
        solve(i);
    }
    return 0;
}