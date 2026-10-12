#include<bits/stdc++.h>
using namespace std;
#ifndef ONLIGE_JUDGE
#define debug(x) cerr << $x << " = " << endl
#else 
#define debug(x)
#endif
#define int long long
void Solve(){
    int n;
    cin >> n;
    vector<int> v(n+1000, 0);
    for(int i=1; i<=n; i++) cin >> v[i];
    vector<vector<int>> dp(n+1, vector<int>(2, 0));
    dp[1][0] = v[1];
    dp[2][0] = v[2];
    dp[2][1] = v[1] + v[2];
    for(int i=3; i<=n; i++){    
        dp[i][0] = max({dp[i-2][1], dp[i-2][0], dp[i-3][1], dp[i-3][0]}) + v[i];
        dp[i][1] = max({dp[i-1][0], dp[i-2][0], dp[i-2][1]}) + v[i];
    } 

    int ans = -1;
    for (int i = max(n - 2, 1ll); i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    assert(ans != -1);
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
        Solve();
    return 0;
}