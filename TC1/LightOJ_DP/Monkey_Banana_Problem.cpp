#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;

void Solve(ll tc) {
    ll n;
    cin >> n;
    ll rows = 2 * n - 1;
    vector<vector<ll>> dp(rows, vector<ll>(n + 1, 0));

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j <= i; j++) {
            cin >> dp[i][j];
            if (i > 0) {
                ll tl = (j > 0) ? dp[i - 1][j - 1] : 0;
                ll tr = (j < i) ? dp[i - 1][j] : 0;
                dp[i][j] += max(tl, tr);
            }
        }
    }

    for (ll i = n; i < rows; i++) {
        ll cols = rows - i;
        for (ll j = 0; j < cols; j++) {
            cin >> dp[i][j];
            dp[i][j] += max(dp[i - 1][j], dp[i - 1][j + 1]);
        }
    }

    cout << "Case " << tc << ": " << dp[rows - 1][0] << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for(int i=1; i<=t; i++){
        Solve(i);
    }
    return 0;
}