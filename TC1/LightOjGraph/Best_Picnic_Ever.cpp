#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;

void Solve()
{
    int k, n, m;
    cin >> k >> n >> m;
    vector<int> p(k + 1);
    for(int i = 1; i <= k; i++) cin >> p[i];
    
    vector<vector<int>> v(n + 1);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
    }

    auto bfs = [&](int c, vector<int>& vis, vector<int>& dis){
        queue<int> q;
        q.push(c);
        vis[c] = 1;
        dis[c]++;

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int i : v[cur]){
                if(!vis[i]){
                    vis[i] = 1;
                    dis[i]++; 
                    q.push(i);
                }
            }
        }
    };

    vector<int> dis(n + 1, 0);
    vector<int> vis(n + 1, 0);
    
    for(int i = 1; i <= k; i++){
        vis.assign(n + 1, 0);
        bfs(p[i], vis, dis);
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(dis[i] == k) cnt++;
    }
    cout << cnt << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for(ll i=1; i<=t; i++){
        cout << "Case " << i << ": ";
        Solve();
    }
    return 0;
}