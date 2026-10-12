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
const int MAX = 1e6 + 7;
vector<bool> is_prime(MAX, true);
vector<int> primes;

const long long mod = 1000000007;

long long binexp(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

vector<long long> fact;

void init_fact(int n) {
    fact.assign(n + 1, 1);
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % mod;
}

long long nCr(int n, int r) {
    if(r == 0 || n == 0) return 1;
    if (r < 0 || r > n) return 0;
    long long num = fact[n];
    long long den = fact[r] * fact[n - r] % mod;
    return num * binexp(den, mod - 2) % mod;
}
void Solve()
{
    int n, m , t;
    cin >> n >> m >> t;
    int ans = 0;
    for(int i=4; i<=n; i++){
        int j = t - i;
        if(j >= 1 && j <= m) ans += nCr(n, i) * nCr(m, j);
    }
    // debug(nCr(m+n-5, t-5));
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    init_fact(10000);
    // cin >> t;
    while (t--)
        Solve();
    return 0;
}