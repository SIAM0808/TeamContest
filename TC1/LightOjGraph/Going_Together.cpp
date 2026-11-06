#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
int dis[10][10][10][10][10][10];
struct State{
    int x[3], y[3];
};
void Solve()
{
    int n;
    cin >> n;
    State start;
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
            if(grid[i][j] >= 'A' && grid[i][j] <= 'C'){
                start.x[grid[i][j]-'A'] = i;
                start.y[grid[i][j]-'A'] = j;
            }
        }
    }
    auto isValid = [&](int x, int y){
        return (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] != '#');
    };
    memset(dis, -1, sizeof(dis));
    queue<State> q;
    q.push(start);
    dis[start.x[0]][start.y[0]][start.x[1]][start.y[1]][start.x[2]][start.y[2]] = 0;
    int ans = -1;
    while(!q.empty()){
        State cur = q.front();
        q.pop();
        int curDis = dis[cur.x[0]][cur.y[0]][cur.x[1]][cur.y[1]][cur.x[2]][cur.y[2]];
        if(grid[cur.x[0]][cur.y[0]] == 'X' && grid[cur.x[1]][cur.y[1]] == 'X' && grid[cur.x[2]][cur.y[2]] == 'X'){
            ans = curDis;
            break;
        }
        for(int d=0; d<4; d++){
            State next = cur;
            for(int i=0; i<3; i++){
                int nx = cur.x[i] + dx[d];
                int ny = cur.y[i] + dy[d];
                if(isValid(nx, ny)){
                    next.x[i] = nx;
                    next.y[i] = ny;
                }
            }
            while(1){
                bool moved = false;
                for(int i=0; i<3; i++){
                    for(int j=i+1; j<3; j++){
                        if(next.x[i] == next.x[j] && next.y[i] == next.y[j]){
                            next.x[j] -= dx[d];
                            next.y[j] -= dy[d];
                            moved = true;
                        }
                    }
                }
                if(!moved) break;
            }
            int &nextDis = dis[next.x[0]][next.y[0]][next.x[1]][next.y[1]][next.x[2]][next.y[2]];
            if(nextDis == -1){
                nextDis = curDis + 1;
                q.push(next);
            }
        }
    }
    if(ans == -1) cout << "trapped" << endl;
    else
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        cout << "Case " << i << ": ";
        Solve();
    }
    return 0;
}