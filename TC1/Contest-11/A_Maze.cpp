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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    vector<vector<char>> v(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin >> v[i][j];
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cnt += v[i][j] == '.';
    }
    vector<vector<int>> vis(n, vector<int>(m));
    int tar = cnt - k;
    queue<pair<int, int>> q;
    int f= 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j] == '.'){
                q.push({i, j});
                vis[i][j] = 1;
                f = 1;
                break;
            }
        }
        if(f) break;
    }
    tar--;
    debug(tar);
    while(!q.empty() && tar > 0){
        auto [x, y] = q.front();
        q.pop();
        // vis[x][y] = 1;
        // tar--;
        // if(tar == 0){
        //     break;
        // }
        int ff = 0;
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >=0 && nx < n && ny >= 0 && ny < m){
                if(v[nx][ny] == '.' && !vis[nx][ny]){
                    // tar--;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                    tar--;
                    if(tar == 0){
                        // ff = 1;
                        break;
                    }
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && v[i][j] == '.') v[i][j] = 'X';
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cout << v[i][j];
        cout << endl;
    }
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