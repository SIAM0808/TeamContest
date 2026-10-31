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
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    int cnt = 0;
    for(int i : v) cnt += i == 1;
    if(cnt == n){
        cout << -1 << endl;
        return;
    }
    int vitor = cnt - (v[0] == 1) - (v[n - 1] == 1);
    int sum = accumulate(v.begin(), v.end(), 0LL);
    if (vitor == n - 2) {
        cout << v[0] + v[n - 1] - 1 << endl;
    } else {
        cout << sum - 1 << endl;
    }
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