#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
void dfs(int c, int p, vector<int>&dis, vector<vector<pair<int,int>>> &v){
    // if(p == -1) dis[c] = 0;
    for(auto [x, y] : v[c]){
        if(x != p){
            dis[x] = dis[c] + y;
            dfs(x, c, dis, v);
        }
    }
}
void Solve()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> v(n+1, vector<pair<int, int>>{});
    for(int i=0; i<n-1; i++){
        int x, y, z;
        cin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    vector<int> dis(n+1, 0);
    // dis[1] = 0;
    dfs(0, -1, dis, v);
    int nod = 0, mx = 0;
    for(int i=0; i<=n; i++){
        if(mx < dis[i]){
            mx = dis[i];
            nod = i;
        }
    }
    int a = nod;
    dis.assign(n+1, 0);
    dfs(a, -1, dis, v);
    vector<int> dis2(n+1, 0);
    mx = 0;
    for(int i=0; i<=n; i++){
        if(mx < dis[i]){
            mx = dis[i];
            nod = i;
        }
    }
    mx = 0;
    int b = nod;
    dfs(b, -1, dis2, v);
    for(int i=0; i<n; i++){
        cout << max(dis[i], dis2[i]) << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for(int i=1; i<=t; i++){
        cout << "Case " << i << ": ";
        cout << endl;
        Solve();
    }
    return 0;
}