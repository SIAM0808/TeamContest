#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
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
void Solve()
{
    int n, k;
    cin >> n >> k;
    ll val = binexp(n, k, 1000);
    long double full = log10(n) * k;
    long double frac = full - floorl(full);
    long double real = powl(10, frac);
    real *= 100;
    cout << (long)real << " ";
    cout << setw(3) << setfill('0') << val << " ";
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        Solve();
    }
    return 0;
}