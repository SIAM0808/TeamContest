#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
vector<int> vis, vis1, dist;
int sz = 0;
vector<vector<int>> adj;
int diameter(int src){
    // vector<int> vis1(adj.size(), 0);
    // vis1.assign(adj.size(), 0);
    vis1[src] = 1;
    queue<int> q;
    q.push(src);
    // vector<int> dist(adj.size(), 0);

    int a = src;
    int mx = 0;
    while (!q.empty()){
        int u = q.front();
         a = u;
        q.pop();
        for (int v : adj[u]){
            if (!vis1[v]){
                vis1[v] = 1;
                dist[v] = dist[u] + 1;
                mx = max(mx, dist[v]);
                q.push(v);
            }
        }
    }
    // for(int i=1; i<=adj.size(); i++){
    //     if(dist[i] == mx){
    //         a = i;
    //         break;
    //     }
    // }
    // vis.assign(adj.size(), 0);
    q.push(a);
    vis[a] = 1;
    dist[a] = 0;
    mx = 0;
    while (!q.empty()){
        int u = q.front();
        sz++;
        q.pop();
        for (int v : adj[u]){
            if (!vis[v]){
                vis[v] = 1;
                dist[v] = dist[u] + 1;
                mx = max(mx, dist[v]);
                q.push(v);
            }
        }
    }
    return mx + 1;
}
void Solve()
{
    int n, m;
    cin >> n >> m;
    adj.assign(n + 1, vector<int>());
    vis1.assign(n + 1, 0);
    dist.assign(n + 1, 0);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vis.assign(n + 1, 0);
    int d = 0;
    vector<int> com(n+1);
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            sz = 0;
            d = diameter(i);
            com[sz] = max(com[sz], d);
        }
    }
    for(int i=n-1; i>=1; i--){
        com[i] = max(com[i], com[i+1]);
    }
    int q;
    cin >> q;
    while(q--){
        int k;
        cin >> k;
        if(k> n || com[k] == 0){
            cout << "impossible\n";
        }
        else if(com[k] < k){
            cout << com[k] - 1 + (k - com[k]) * 2 << "\n";
        }else cout << k - 1 << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ":\n";
        Solve();
    }
    return 0;
}