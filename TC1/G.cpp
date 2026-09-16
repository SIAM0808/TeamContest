#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
const long double EPS = 1e-9;
void Solve()
{
	long double l, b;
	cin >> l >> b;
	if(2*l <= b || l + b <= l){
		cout << -1 << endl;
		return;
	}
	long double area = ((b) * sqrt((4*l*l) - (b*b))) / 4;
	long double cf = (area * 2) / b;
	debug(cf);
	// debug(cf1);
	long double s = (2*l + b) / 2;
	long double r = area/s;
	long double R = (l*l*b)/(4.0 * area);
	long double ans = 0;
	if(cf - r < R){
		ans = R - cf + r;
	}else if(R == cf) ans = r;
	else ans = cf - R - r;
	debug(r);
	debug(R);
	// else
	cout << fixed << setprecision(16) << ans << endl;
	
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