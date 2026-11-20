
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
vector<bool> is_prime(MAX, true);
vector<int> primes;

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < MAX; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < MAX; i += p)
                is_prime[i] = false;
        }
    }
    for (int p = 2; p < MAX; p++) {
        if (is_prime[p]) primes.push_back(p);
    }
}

void Solve()
{
    int n;
    cin >> n;

    cout << n << " = ";

    bool first = true;

    for(int p : primes){
        if(p > n) break;

        int cnt = 0;
        int x = n;

        while(x){
            x /= p;
            cnt += x;
        }

        if(!first) cout << " * ";
        cout << p << " (" << cnt << ")";
        first = false;
    }

    cout << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    sieve();

    ll t = 1;
    cin >> t;

    for(ll i=1; i<=t; i++){
        cout << "Case " << i << ": ";
        Solve();
    }

    return 0;
}
