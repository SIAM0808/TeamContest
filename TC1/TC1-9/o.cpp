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
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	int x = 0, cnt = 0;
	// int l = 0, r = n-1;
	sort(v.begin(), v.end());
	vector<int> pre(n+1);
	pre[1] = v[0];
	for(int i=2; i<=n; i++) pre[i] = pre[i-1] + v[i-1];

	// for(int i=1; i<=n; i++) cerr << v[i] << " ";
	int tem = 0;
	for(int i=1; i<=n; i++){
		// debug(tem);
		// debug(v[i]);
		// debug(pre[n] - pre[i]);
		if(tem + v[i-1] < pre[n] - pre[i]) tem += v[i-1];
		else if(tem + v[i-1] == pre[n] - pre[i]){
			// debug(tem);
			cout << tem + v[i-1] + n - i << endl;
			return;
		}else{
			// cerr << "kds" << endl;
			int l = 1, r = v[i-1];
			int ans = 0;
			while(l <= r){
				int mid = (l + r) >> 1;
				if(mid*2 + tem >= pre[n] - pre[i-1]) ans = mid, r = mid - 1;
				else l = mid + 1;
			}
			int f = ans != v[i-1];
			cout << tem + ans + n - i + f << endl;
			return;
		}
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