#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
const int MAXN = 100000000;
const int MAXP = 5761500; 

bitset<MAXN + 5> is_prime;
int primes[MAXP];
unsigned int pref[MAXP];
int prime_cnt = 0;

void sieve() {
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    
    for (int i = 2; i * i <= MAXN; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                is_prime[j] = 0;
            }
        }
    }
    
    for (int i = 2; i <= MAXN; i++) {
        if (is_prime[i]) {
            primes[prime_cnt] = i;
            pref[prime_cnt] = (prime_cnt == 0) ? i : (pref[prime_cnt - 1] * (unsigned int)i);
            prime_cnt++;
        }
    }
}
void Solve()
{
    int n;
    cin >> n;
    
    int idx = upper_bound(primes, primes + prime_cnt, n) - primes - 1;
    unsigned int ans = pref[idx];
    
    for (int i = 0; i < prime_cnt && (ll)primes[i] * primes[i] <= n; i++) {
        ll p = primes[i];
        ll cur = p * p; 
        while (cur <= n) {
            ans *= (unsigned int)p;
            cur *= p;
        }
    }
    cout << ans << '\n';
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