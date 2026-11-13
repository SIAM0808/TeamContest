#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
const int MOD = 100000007;

int n, k;
int a[55], c[55];
int dp[55][1005];

int rec(int i, int rem) {
    if (rem == 0) return 1;
    if (i == n) return 0;
    if (dp[i][rem] != -1) return dp[i][rem];

    ll ways = 0;
    for (int cnt = 0; cnt <= c[i]; cnt++) {
        if (rem - cnt * a[i] >= 0) {
            ways = (ways + rec(i + 1, rem - cnt * a[i])) % MOD;
        } else {
            break;
        }
    }
    return dp[i][rem] = ways;
}

void Solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    memset(dp, -1, sizeof(dp));
    cout << rec(0, k) << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        Solve();
    }
    return 0;
}