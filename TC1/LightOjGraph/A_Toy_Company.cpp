#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
int parbona[26][26][26];
int dist[26][26][26];
int dx[] = {-1, 0, 0, 1, 0, 0};
int dy[] = {0, -1, 0, 0, 1, 0};
int dz[] = {0, 0, -1, 0, 0, 1};
void Solve()
{
    string a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    // memset(parbo, -1, sizeof(parbo));
    memset(parbona, 0, sizeof(parbona));
    memset(dist, -1, sizeof(dist));
    for(int i=0; i<n; i++){
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        for(char j : s1){
            for(char k : s2){
                for(char l : s3){
                    parbona[j-'a'][k-'a'][l-'a'] = 1;
                }
            }
        }
    }
    if(parbona[a[0]-'a'][a[1]-'a'][a[2]-'a'] || parbona[b[0]-'a'][b[1]-'a'][b[2]-'a']){
        cout << -1 << endl;
        return;
    }
    queue<tuple<int, int, int>> q;
    q.push({a[0]-'a', a[1]-'a', a[2]-'a'});
    dist[a[0]-'a'][a[1]-'a'][a[2]-'a'] = 0;
    while(!q.empty()){
        auto [x, y, z] = q.front();
        q.pop();
        if(x == b[0]-'a' && y == b[1]-'a' && z == b[2]-'a'){
            cout << dist[b[0]-'a'][b[1]-'a'][b[2]-'a'] << endl;
            return;
        }
        for(int i=0; i<6; i++){
            int nx = (x + dx[i] + 26) % 26;
            int ny = (y + dy[i] + 26) % 26;
            int nz = (z + dz[i] + 26) % 26;
            if(!parbona[nx][ny][nz]){
                parbona[nx][ny][nz] = 1;
                dist[nx][ny][nz] = dist[x][y][z] + 1;
                q.push({nx, ny, nz});
            }
        }
    }
    cout << dist[b[0]-'a'][b[1]-'a'][b[2]-'a'] << endl;
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