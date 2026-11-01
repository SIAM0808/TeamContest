#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif
#define int long long
using ll = long long;

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin >> v[i][j];
    }
    int ans = 0;
    vector<int> r(n), c(m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) r[i] += v[i][j] == '*';
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++) c[i] += v[j][i] == '*';
    }
    // for(int i : c) cerr << i << " ";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j] == '*'){
                ans += (r[i] - 1) * (c[j] - 1);
            }
        }
    }
    cout << ans << endl;
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