#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
const ll MAX = 5e6 + 7;
vector<bool> is_prime(MAX, true);
vector<ll> primes;

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (ll p = 2; p * p < MAX; p++) {
        if (is_prime[p]) {
            for (ll i = p * p; i < MAX; i += p)
                is_prime[i] = false;
        }
    }
    for (ll p = 2; p < MAX; p++) {
        if (is_prime[p]) primes.push_back(p);
    }
}
long long binexp(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll primeSum(ll b, ll exp, ll mod){
    if(b % mod == 1) return (exp + 1) % mod;
    ll num = (binexp(b, exp + 1, mod) - 1 + mod) % mod;
    ll den = binexp(b - 1, mod - 2, mod);
    return (num * den) % mod;
}
void Solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> v;
    ll ans = 1;
    ll mod = 1e9 + 7;
    for(ll p : primes){
        if(p * p > n) break;
        ll cnt = 0;
        while(n % p == 0) cnt++, n /= p;
        ans = (ans * primeSum(p, cnt * m, mod)) % mod;
    }
    if(n > 1){
        ans = (ans * primeSum(n, m, mod)) % mod;
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    sieve();
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        cout << "Case " << i << ": ";
        Solve();
    }
    return 0;
}