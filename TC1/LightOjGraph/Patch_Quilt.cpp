#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
int dx[] = {-1, 1, 0, 1, 1, -1, 0, -1, 0};
int dy[] = {0, -1, 1, 1, 0, 1, -1, -1, 0};
string dir[] = {"U", "DL", "R", "DR", "D", "UR", "L", "UL", "*"};
void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }
    int q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        vector<string> tem;
        vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(s.size()+1, 0)));
        auto dfs = [&](auto self, int x, int y, int idx) -> bool {
            if(x < 0 || x >= n || y < 0 || y >= m) return false;
            if(grid[x][y] != s[idx]) return false;
            if(idx == s.size()-1) return true;
            if(vis[x][y][idx]) return false;
            vis[x][y][idx] = 1;
            for(int i=0; i<9; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                tem.push_back(dir[i]);
                if(self(self, nx, ny, idx+1)) return true;
                tem.pop_back();
            }
            return false;
        };
        bool found = false;
        for(int i=0; i<n && !found; i++){
            for(int j=0; j<m && !found; j++){
                if(grid[i][j] == s[0]){
                    if(dfs(dfs, i, j, 0)){
                        cout << s << " found: (" << i + 1 << "," << j + 1 << ")";
                        for(auto &d : tem){
                            cout << ", " << d;
                        }
                        cout << "\n";
                        found = true;
                    }
                }
            }
        }
        if(!found){
            cout << s << " not found\n";
        }
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