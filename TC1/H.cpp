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
    int n;
    cin >> n;
    string s; cin >> s;
    int m; cin >> m;
    vector<vector<int>> v(n+1, vector<int>(27, 1e9));
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<27; j++){
            v[i][j] = v[i+1][j];
        }
        if(s[i] =='#') v[i][26] = i;
        else v[i][s[i] - 'a'] = i;
    }
    while(m--){
        string t;
        cin >> t;
        int cur = 0, f = 1;
        for(auto i : t){
            if(cur >= n){
                f = 0;
                break;
            }
            int dis = min(v[cur][i - 'a'], v[cur][26]);
            if(dis == 1e9){
                f = 0;
                break;
            }
            cur = dis + 1;
        }
        if(f) cout << "Plan will be successful" << endl;
        else cout << "Plan should be changed" << endl;
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