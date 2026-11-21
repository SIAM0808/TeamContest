#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;

void Solve()
{
    long long n;
    cin >> n ;
    cout << n - (long)sqrt(n) - (long)sqrt(n/2) << endl;
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