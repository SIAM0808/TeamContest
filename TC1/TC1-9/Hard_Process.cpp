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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, z = 0;
    int mx = 0, ans = 0;

    for (int r = 0; r < n; r++) {
        if (a[r] == 0) {
            z++;
        }
        while (z > k) {
            if (a[l] == 0) {
                z--;
            }
            l++;
        }
        if (r - l + 1 > mx) {
            mx = r - l + 1;
            ans = l;
        }
    }

    for (int i = ans; i < ans + mx; i++) {
        a[i] = 1;
    }
    cout << mx << "\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
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