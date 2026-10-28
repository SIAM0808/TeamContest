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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    auto parbe = [&](int tar) -> int{
        int tem = k;
        for(int i=0; i<n; i++){
            int lagbe = a[i] * tar;
            if(lagbe <= b[i]) continue;
            if(lagbe - b[i] > k){
                k = tem;
                return 0;
            }
            k -= lagbe - b[i];
        }
        k = tem;
        return 1;
    };
    int l = 1, r = 3e9, ans = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(parbe(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--)
        Solve();
    return 0;
}