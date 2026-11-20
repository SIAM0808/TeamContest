#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
const int MAX = 1e7 + 7;
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
    int cnt = 0;
    for(int i = 2; i<=(n/2); i++){
        int x = i;
        int y = n - i;
        if(is_prime[x] && is_prime[y]) cnt++;
    }
    cout << cnt << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    sieve();
    cin >> t;
    for(ll i=1; i<=t; i++){
        cout << "Case " << i << ": ";
        Solve();
    }
    return 0;
}