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
int dp1[1005][1005];
int dp2[1005][1005];
int dp3[1005][1005];
int dp4[1005][1005];
void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n+1, vector<int>(m+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) cin >> v[i][j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp1[i][j] = v[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            dp2[i][j] = v[i][j] + max(dp2[i + 1][j], dp2[i][j + 1]);
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            dp3[i][j] = v[i][j] + max(dp3[i + 1][j], dp3[i][j - 1]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            dp4[i][j] = v[i][j] + max(dp4[i - 1][j], dp4[i][j + 1]);
        }
    }
    int ans = 0;
    for (int i = 2; i < n; i++) {
        for (int j = 2; j < m; j++) {
            int way1 = dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] + dp4[i][j + 1];
            int way2 = dp1[i][j - 1] + dp2[i][j + 1] + dp3[i + 1][j] + dp4[i - 1][j];

            ans = max({ans, way1, way2});
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