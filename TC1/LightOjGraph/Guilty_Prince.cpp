#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

int on = 0, z = 0;
using ll = long long;
void dfs(vector<vector<char>> &v, pair<int,int> p, vector<vector<int>> &vis, int w, int h){
    auto [x, y] = p;
    vis[x][y] = 1;
    on++;
    if(x + 1 < w && !vis[x+1][y] && v[x+1][y] == '.') dfs(v, make_pair(x+1, y), vis, w, h);
    if(x - 1 >= 0 && !vis[x-1][y] && v[x-1][y] == '.') dfs(v, make_pair(x-1, y), vis, w, h);
    if(y + 1 < h && !vis[x][y+1] && v[x][y+1] == '.') dfs(v, make_pair(x, y+1), vis, w, h);
    if(y - 1 >= 0 && !vis[x][y-1] && v[x][y-1] == '.') dfs(v, make_pair(x, y-1), vis, w, h);
}
    
void Solve()
{
    on = 0;
    int w, h;
    cin >> h >> w;
    pair<int,int> p;
    vector<vector<char>> v(w, vector<char>(h));
     for(int i=0; i<w; i++){
         for(int j=0; j<h; j++){
             cin >> v[i][j];
             if(v[i][j] == '@') p = {i, j};
         }
     }
    //  debug(p.first);
     vector<vector<int>> vis(w, vector<int>(h, 0));
     dfs(v, p, vis, w, h);
     cout << on << endl;
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