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
    vector<vector<int>> cost(1 << n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> cost[i][j];
    }
    vector<int> dp(1 << n, 1e9);
    dp[0] = 0;
    int N = 1 << n;
    for(int ms = 0; ms < N; ms++){
        for(int i=0; i<n; i++){
            int cur = cost[i][i];
            for(int j=0; j<n; j++){
                if(ms&(1 << j)){
                    cur += cost[i][j];
                }
            }
            int nx = ms | (1 << i);
            dp[nx] = min(dp[nx], dp[ms] + cur);
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