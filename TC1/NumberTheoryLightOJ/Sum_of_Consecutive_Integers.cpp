#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
const ll MAX = 1e7 + 7;
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
void Solve()
{
    ll n;
    cin >> n;
    while(n&1^1) n >>= 1;
    ll ans = 1;
    for(ll p : primes){
        if(p*p > n) break;
        ll cnt = 0;
        while(n%p == 0) n /= p, cnt++;
        ans *= cnt + 1;
    }
    if(n > 1) ans *= 2;
    cout << ans - 1 << endl;
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