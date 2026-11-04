#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
long long MOD = 1000000007;

void Solve()
{
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    vector<long long> dp(n + 2, 0);
    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i + 1] = (2 * dp[i] - dp[p[i]] + 2 + MOD) % MOD;
    }
    cout << dp[n + 1] << endl;
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