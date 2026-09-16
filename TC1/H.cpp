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
	int i = 1;
	auto tem = v;
	int sum = v[0];
	v[0] = 0;
	int tran = 0;
	for(int i=0; i<n-1; i++){
		if(v[i] > v[i+1]) tran += v[i] - v[i+1], v[i] -= v[i] - v[i+1];
	}
	// for(int i=0; i<n; i++){
	// 	if(v[i] == 0) tran += tem[i];
	// }
	int cnt = 0;
	vector<int> pos;
	debug(tran);
	// for(int i : v) cerr << i << " ";
	int lo = 0;
	while(lo != 100){
		for(int i=0; i<n-1; i++){
			if(v[i] > v[i+1]){
				tran += v[i];
				v[i+1] += v[i];
				v[i] = 0;
			}
		}
		lo++;
	}
	// for(int i=0; i<n; i++)
	cout << tran << endl;
	// for(int i : v) cout << i << " ";
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