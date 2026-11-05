#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
vector<vector<char>> v;
void Solve()
{
    int n, m;
    cin >> n >> m;
    v.assign(n, vector<char>(m));
    pair<int,int> p, pa, pb, pc;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> v[i][j];
            if(v[i][j] == 'h') p = {i, j};
            if(v[i][j] == 'a') pa = {i, j};
            if(v[i][j] == 'b') pb = {i, j};
            if(v[i][j] == 'c') pc = {i, j};
        }
    }
    vector<vector<int>> dis(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int,int>> q;
    q.push(p);
    vis[p.first][p.second] = 1;
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                if(abs(i) + abs(j) == 1){
                    int nx = x + i, ny = y + j;
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && v[nx][ny] != '#' && v[nx][ny] != 'm'){
                        vis[nx][ny] = 1;
                        dis[nx][ny] = dis[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    int ans = max({dis[pa.first][pa.second], dis[pb.first][pb.second], dis[pc.first][pc.second]});
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