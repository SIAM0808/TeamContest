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
    vector<vector<int>> dp(n, vector<int>(3));
    int a, b, c;
    cin >> a >> b >> c;
    dp[0][0] = a, dp[0][1] = b, dp[0][2] = c;
    for(int i=1; i<n; i++){
        cin >> a >> b >> c;
        dp[i][0] = a + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = b + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = c + min(dp[i-1][0], dp[i-1][1]);
    }
    cout << min({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;
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