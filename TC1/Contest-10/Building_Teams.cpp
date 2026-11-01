#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif
 
using ll = long long;
vector<int> g;
vector<int> vis;
vector<vector<int>> v;
int f = 0;
int n, m;
void dfs(int p, int c){
    vis[c] = 1;
    g[c] = p;
    for(int i : v[c]){
        if(!vis[i]){
            dfs(p == 1 ? 2 : 1, i);
        }else{
            if(g[i] == p) f = 1;
        }
    }
}
void Solve()
{
    cin >> n >> m;
    v.resize(n+1);
    vis.resize(n+1, 0);
    g.resize(n+1);
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1; i<=n; i++){
        if(!vis[i])
        dfs(1, i);
    }
    if(f){
        cout << "IMPOSSIBLE\n";
        return;
    }
    for(int i=1; i<=n; i++) cout << g[i] << " ";
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