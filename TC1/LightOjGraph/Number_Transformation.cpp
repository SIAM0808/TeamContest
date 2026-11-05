#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
#define int long long
const int MAX = 1e3 + 7;
vector<bool> is_prime(MAX, true);
// vector<int> primes;
int dp[MAX];
vector<vector<int>> primes(MAX);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < MAX; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < MAX; i += p)
                is_prime[i] = false;
        }
    }
    for(int i = 2; i < MAX; i++) {
        if (is_prime[i]) {
            for(int j = 2 * i; j < MAX; j += i) {
                primes[j].push_back(i);
            }
        }
    }
}
int dfs(int s, int t){
    if(s == t) return 0;
    if(s > t) return INT_MAX;
    if(dp[s] != -1) return dp[s];
    int cost = INT_MAX;
    for(int i : primes[s]){
        if(s + i <= t){
            cost = min(cost, 1 + dfs(s + i, t));
        }
    }
    return dp[s] = cost;
}
void Solve()
{
    int s, t;
    cin >> s >> t;
    memset(dp, -1, sizeof(dp));
    if(s == t){
        cout << 0 << endl;
        return;
    }
    if(is_prime[s]){
        cout << -1 << endl;
        return;
    }
    int ans = dfs(s, t);
    if(ans >= INT_MAX) cout << -1 << endl;
    else cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    sieve();
    cin >> t;
    for(int i=1; i<=t; i++){
        cout << "Case " << i << ": ";
        Solve();
    }
    return 0;
}