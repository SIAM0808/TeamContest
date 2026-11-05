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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> v[i][j];
        }
    }
    int f = 0;
    vector<pair<int, int>> border;
    for(int i=0; i<n; i++){
        if(v[i][0] == '.') border.push_back({i, 0});
    }
    for(int i=0; i<n; i++){
        if(v[i][m-1] == '.') border.push_back({i, m-1});
    }
    for(int j=0; j<m; j++){
        if(v[0][j] == '.') border.push_back({0, j});
    }
    for(int j=0; j<m; j++){
        if(v[n-1][j] == '.') border.push_back({n-1, j});
    }
    if(border.size() == 0){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vector<vector<int>> distF(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j] == 'F'){
                distF[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(auto [dx, dy] : vector<pair<int, int>>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}){
            int nx = x + dx;
            int ny = y + dy;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(v[nx][ny] == '#' || distF[nx][ny] != -1) continue;
            distF[nx][ny] = distF[x][y] + 1;
            q.push({nx, ny});
        }
    }
    vector<vector<int>> distJ(n, vector<int>(m, -1));
    queue<pair<int, int>> q2;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j] == 'J'){
                distJ[i][j] = 0;
                q2.push({i, j});
            }
        }
    }
    while(!q2.empty()){
        auto [x, y] = q2.front();
        q2.pop();
        for(auto [dx, dy] : vector<pair<int, int>>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}){
            int nx = x + dx;
            int ny = y + dy;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(v[nx][ny] == '#' || distJ[nx][ny] != -1) continue;
            distJ[nx][ny] = distJ[x][y] + 1;
            q2.push({nx, ny});
        }
    }
    pair<int, int> ans = {-1, -1};
    for(auto [x, y] : border){
        if(distJ[x][y] != -1 && distJ[x][y] < distF[x][y]){
            if(ans.first == -1 || distJ[x][y] < distJ[ans.first][ans.second]){
                ans = {x, y};
            }
        }
    }
    if(ans.first == -1){
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << distJ[ans.first][ans.second] + 1 << endl;
    }

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