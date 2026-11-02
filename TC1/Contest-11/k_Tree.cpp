#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif
#define int long long
int mod = 1e9 + 7;
using ll = long long;
vector<vector<int>> dp;
int f(int w, int k, int n, int d){
    if(w == 0) return d == 1;
    if(dp[w][d] != -1) return dp[w][d];
    int cost = 0;
    for(int i=1; i<=k; i++){
        if(i <= w){
            int nd = (d == 1 || i >= n);
            cost = (cost + f(w-i, k, n, nd)) % mod;
        }
    }
    return dp[w][d] = cost;
}
void Solve()
{
    int n, k, w;
    cin >> w >> k >> n;
    dp.assign(w+1, vector<int>(2, -1));
    cout << f(w, k, n, 0) << endl;
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