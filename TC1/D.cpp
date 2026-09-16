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
	vector<int> v(n+1);
	for(int i=1; i<=n; i++) cin >> v[i];
	map<int,int> mp;
	for(int i=1; i<=n; i++) mp[v[i]] = i;
	for(auto [x, y] : mp) cerr << x << " " << y << endl;
	// for(int i=1; i<=n; i++){
	// 	int pos = mp[v[i]];
	// 		while(pos > 1 && abs(v[pos] - v[pos-1]) > 1 && pos > i){
	// 			swap(mp[v[pos]], mp[v[pos-1]]);
	// 			swap(v[pos], v[pos-1]);
	// 			pos--;
	// 		}
	// }
	// for(int i=1; i<=n; i++){
	// 	int pos = mp[i];
	// 	if(pos < i){
	// 		while(pos < n && abs(v[pos] - v[pos+1]) > 1 && pos < i){
	// 			swap(mp[v[pos]], mp[v[pos+1]]);
	// 			swap(v[pos], v[pos+1]);
	// 		debug(v[pos-1]);
	// 		debug(v[pos]);
	// 			pos++;
	// 		}
	// 	}
	// }
	for(int i=2; i<=n; i++){
		int pos = i;
		while(pos > 1 && abs(v[pos] - v[pos-1]) > 1 && v[pos] < v[pos-1]) swap(v[pos], v[pos-1]), pos--;
	}
	for(int i=1; i<=n; i++) cout << v[i] << " ";
	cout << endl;
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