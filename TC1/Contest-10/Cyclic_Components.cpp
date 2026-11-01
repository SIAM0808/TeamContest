#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
int n, m;
vector<vector<int>> g;
vector<int> vis;
int sz = 0;
// int f = 0;
vector<int> path;
void dfs(int c, int p){
    path.push_back(c);
    vis[c] = 1;
    for(int i : g[c]){
        if(!vis[i]){
            dfs(i, c);
        }
    }
}
void Solve()
{
    int n, m;
    cin >> n >> m;
    g.assign(n+1, vector<int>{});
    vis.assign(n+1, 0);
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1; i<=n; i++){
        // sz = 0;
        path.clear();   
        if(!vis[i]){
            dfs(i, -1);
            int f = 1;
            for(int j : path){
                if(g[j].size() != 2){
                    f = 0;
                    break;
                }
            }
            sz += f;
        }
    }
    cout << sz << endl;
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