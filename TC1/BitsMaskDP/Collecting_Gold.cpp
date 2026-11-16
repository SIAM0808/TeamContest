#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
int sz;
vector<pair<int, int>> pts;
vector<vector<int>> dp;
int dis(int u, int v){
    return max(abs(pts[u].first - pts[v].first), abs(pts[u].second - pts[v].second));
}
int rec(int msk, int u){
    if(msk == (1 << sz) - 1) return dis(u, 0);
    if(dp[msk][u] != -1) return dp[msk][u];
    int ans = INT_MAX;
    for(int i=0; i<sz; i++){
        if((msk & (1 << i)) == 0){
            ans = min(ans, dis(u, i) + rec(msk | (1 << i), i));
        }
    }
    return dp[msk][u] = ans;
}
void Solve()
{
    pts.clear();
    int m, n;
    cin >> m >> n;
    swap(m, n);
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if(c == 'x' || c == 'g'){
                pts.push_back({i, j});
            }
        }
    }
    sz = pts.size();
    dp.assign(1 << sz, vector<int>(sz, -1));
    int ans = rec(1, 0);
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for(int i=1; i<=t; i++){
        cout << "Case " << i << ": ";
        Solve();
    }
    return 0;
}