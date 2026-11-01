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
 
void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n+1);
    for(int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<int> dis(n+1, INT_MAX);
    queue<int> q;
    vector<int> par(n+1);
    iota(par.begin(), par.end(), 0);
    par[1] = 1;
    q.push(1);
    dis[1] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i : v[u]){
            if(dis[u] + 1 < dis[i]) dis[i] = dis[u] + 1, q.push(i), par[i] = u;
        }
    }
    if(dis[n] == INT_MAX){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    // cout << dis[n] << endl;
    int x = n;
    // cout << x << " ";
    vector<int> ans;
    int cnt = 0;
    while(par[x] != x){
        // cout << x << " ";
        ans.push_back(x);
        // cnt++;
        x = par[x];
    }
    // cnt++;
    ans.push_back(x);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i : ans) cout << i << " ";
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
