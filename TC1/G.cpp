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
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    vector<int> pre(n + 1);
    pre[1] = v[0];
    for(int i=2; i<=n; i++) pre[i] = pre[i-1] + v[i-1];
    int mx = 0;
    for(int i=1; i<=n; i++){
        int l = i, r = n;
        while(l <= r){
            int mid = (l + r) >> 1;
            int val = pre[mid] - pre[i-1];
            if(val <= t) l = mid + 1, mx = max(mx, mid - i + 1);
            else r = mid - 1;
        }
    }
    cout << mx << endl;
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