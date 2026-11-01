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
vector<int> com, vis;
vector<vector<int>> v;
void dfs(int c, int p){
    vis[c] = 1;
    com.push_back(c);
    for(int i : v[c]){
        if(!vis[i]){
            dfs(i, c);
        }
    }
}
void Solve()
{
    int n, m;
    cin >> n >> m;
    v.assign(n+1, vector<int>{});
    vis.assign(n+1, 0);
    vector<pair<int, int>> vp(n+1);
    for(int i=1; i<=n; i++){
        cin >> vp[i].first >> vp[i].second;
    }
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int ans = INT_MAX;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            com.clear();
            dfs(i, -1);
            int mnx = INT_MAX, mny = INT_MAX;
            int mxX = -1, mxY = -1;
            for(int j : com){
                mxX = max(mxX, vp[j].first);
                mxY = max(mxY, vp[j].second);
                mnx = min(mnx, vp[j].first);
                mny = min(mny, vp[j].second);
            }
            ans = min(ans, 2*(mxX - mnx + mxY - mny));
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    // cin >> t;
    while (t--)
        Solve();
    return 0;
}