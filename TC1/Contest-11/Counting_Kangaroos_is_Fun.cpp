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
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    sort(v.begin(), v.end());
    int r = n-1, l = n/2 - 1;
    int cnt = 0;
    vector<int> vis(n);
    while(l >= 0 && r >= n/2){
        if(v[l]*2 <= v[r]){
            cnt++;
            // vis[l] = 1;
            r--;
            // while(vis[r] == 1) r--;
        }
        l--;
    }
    cout << n - cnt << endl;
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