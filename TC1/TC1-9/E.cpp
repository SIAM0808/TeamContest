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
// int mod = 1e9 + 7;
//92675448
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
void Solve()
{
    int k;
    cin >> k;
    cout << (fact[k] - binexp(2, k-1) + mod) % mod << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    init_fact(1000000);
    // cin >> t;
    while (t--)
        Solve();
    return 0;
}