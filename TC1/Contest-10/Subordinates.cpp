#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
vector<vector<int>> g;
vector<int> sub;
vector<int> vis;
int dfs(int c, int p){
    // if(g[c].size() == 1) return 0;
    int cost = 0;
    vis[c] = 1;
    for(int i : g[c]){
        if(!vis[i]){
            cost += 1 + dfs(i, c);
        }
    }
    sub[c] = cost;
    return cost;
}
void Solve()
{
    int n;
    cin >> n;
    vector<int> v(n+1);
    vis.assign(n+1, 0);
    g.assign(n+1, vector<int>{});
    sub.assign(n+1, 0);
    for(int i=2; i<=n; i++){
        // cin >> v[i];
        int x;
        cin >> x;
        g[i].push_back(x);
        g[x].push_back(i);
    }
    dfs(1, -1);
    for(int i=1; i<=n; i++) cout << sub[i] << " ";
    cout << endl;
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