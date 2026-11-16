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
    vector<vector<int>> pr(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> pr[i][j];
        }
    }
    vector<int> dp(1 << n, 0);
    dp[0] = 0;
    int N = (1 << n);
    for(int mask = 0; mask < N; mask++){
        int i = __builtin_popcount(mask);
        for(int j=0; j<n; j++){
            if(!((mask >> j) & 1)){
                int nxt = mask | (1 << j);
                dp[nxt] = max(dp[nxt], dp[mask] + pr[i][j]);
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