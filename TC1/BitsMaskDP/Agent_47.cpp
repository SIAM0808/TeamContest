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
    int n;
    cin >> n;
    vector<int> life(n);
    for(int i=0; i<n; i++) cin >> life[i];
    vector<int> dp(1 << n, 1e9);
    vector<vector<int>> dmg(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char c;
            cin >> c;
            dmg[i][j] = c - '0';
        }
    }
    int N = (1 << n);
    dp[0] = 0;
    for(int msk = 0; msk < N; msk++){
        for(int i=0; i<n; i++){
            if(!(msk & (1 << i))){
                int mx = 1;
                for(int j=0; j<n; j++){
                    if(msk & (1 << j)){
                        mx = max(mx, dmg[j][i]);
                    }
                }
                int nxt = msk | (1 << i);
                int shot = (life[i] + mx - 1) / mx;
                dp[nxt] = min(dp[nxt], dp[msk] + shot);
            }
        }
    }
    cout << dp[N-1] << endl;
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