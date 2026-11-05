#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
const int MAX = 20005; 

vector<vector<int>> v;
int n;
int c1 = 0, c2 = 0;
vector<int> vis;

void dfs(int c, int p, int f){
    if(f) c1++;
    else c2++;
    vis[c] = 1;
    for(int i : v[c]){
        if(!vis[i]) dfs(i, c, 1-f);
    }
}

void Solve()
{
    cin >> n;
    v.assign(MAX, vector<int>{});
    vis.assign(MAX, 0);
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int ans = 0;
    for(int i=1; i<MAX; i++){
        if(!v[i].empty() && !vis[i]){
            c1 = 0, c2 = 0;
            dfs(i, -1, 0);
            ans += max(c1, c2);
        }
    }
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