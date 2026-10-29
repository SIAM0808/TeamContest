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

void Solve()
{
    int n;
    cin >>  n;
    int l = 1, r = n;
    int ans = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(mid*mid <= 2*n - 1) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << (ans - 1) / 2 << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}