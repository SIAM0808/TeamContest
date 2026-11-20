#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;

const int MAX = 1e6 + 7;
vector<ll> primes;

void sieve()
{
    vector<bool> isPrime(MAX, true);
    isPrime[0] = isPrime[1] = false;

    for(ll i = 2; i * i < MAX; i++){
        if(isPrime[i]){
            for(ll j = i * i; j < MAX; j += i){
                isPrime[j] = false;
            }
        }
    }

    for(ll i = 2; i < MAX; i++){
        if(isPrime[i]) primes.push_back(i);
    }
}

void Solve()
{
    ll n;
    cin >> n;
    ll ans = 1;
    for(auto p : primes){
        if(p > n / p) break;

        if(n % p == 0){
            ll cnt = 0;

            while(n % p == 0){
                cnt++;
                n /= p;
            }

            ans *= (cnt + 1);
        }
    }
    if(n > 1) ans *= 2;
    cout << ans - 1 << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    ll t;
    cin >> t;

    for(ll i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        Solve();
    }

    return 0;
}