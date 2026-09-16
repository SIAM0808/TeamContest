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
	cin >> n;
	vector<int> v(n+1);
	for(int i=1; i<=n; i++) cin >> v[i];
	vector<int> pre(n+1);
	sort(v.begin(), v.end());
	pre[1] = v[1];
	for(int i=2; i<=n; i++) pre[i] = pre[i-1] + v[i];
	int mx = 0;
	for(int i=1; i<=n;  i++){
		debug((n - i));
		debug(pre[i]);
		mx = max(mx, (n-i)*pre[i] + i*(pre[n] - pre[i]));
	}
	cout << mx << endl;
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