#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
void Solve()
{
    int n, m;
    cin >> n >> m;
    set<char> ache;
    vector<vector<char>> v(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> v[i][j];
            if(v[i][j] != '.'){
                ache.insert(v[i][j]);
            }
        }
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    auto bfs = [&](char wall) -> void{
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0 || i == n - 1 || j == 0 || j == m - 1){
                    if(v[i][j] != wall){
                        vis[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
        }
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(int d=0; d<4; d++){
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && v[nx][ny] != wall){
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    };
    for(char c : ache){
        vis.assign(n, vector<int>(m, 0));
        bfs(c);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && v[i][j] != c){
                    v[i][j] = c;
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << v[i][j];
        }
        cout << "\n";
    }   
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for(int i=1; i<=t; i++){
        cout << "Case " << i << ":\n";
        Solve();
    }
    return 0;
}