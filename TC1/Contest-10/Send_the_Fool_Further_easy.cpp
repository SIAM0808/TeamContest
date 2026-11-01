#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
#define int ll
vector<vector<pair<int,int>>> v;
vector<int> leaf;
vector<int> cost;
void dfs(int u, int p) {
    if (u != 0 && v[u].size() == 1) leaf.push_back(u);
    for (auto [x, y] : v[u]) {
        if (x != p) {
            cost[x] = cost[u] + y; 
            dfs(x, u);
        }
    }
}
void Solve()
{
    int n;
    cin >> n;
    v.assign(n+1, vector<pair<int, int>>{});
    cost.assign(n+1, 0);
    for(int i=0; i<n-1; i++){
        int x, y, z;
        cin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    dfs(0, -1);
    int mx = 0;
    // for(int i : cost) cerr << i << " ";
    for(int i  : leaf) mx = max(mx, cost[i]);
    cout << mx << endl;
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