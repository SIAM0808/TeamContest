#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif
 
using ll = long long;
void dfs(vector<vector<char>> &v, vector<vector<int>> &vis, int i, int j, int n, int m){
    vis[i][j] = 1;
    if(j < m-1 && v[i][j+1] == '.' && !vis[i][j+1]  ) dfs(v, vis, i, j+1, n, m);
    if(j >= 1 && v[i][j-1] == '.' && !vis[i][j-1] ) dfs(v, vis, i, j-1, n, m);
    if(i < n-1 && v[i+1][j] == '.' && !vis[i+1][j]  ) dfs(v, vis, i+1, j, n, m);
    if( i >= 1 && v[i-1][j] == '.' && !vis[i-1][j]) dfs(v, vis, i-1, j, n, m);
}
void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j = 0; j < m;j ++) cin >> v[i][j];
    }
    int cnt = 0;
    vector<vector<int>> vis(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j] == '.' && !vis[i][j]){
                cnt++;
                dfs(v, vis, i, j, n, m);
            }
        }
    }
    cout << cnt << endl;
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
