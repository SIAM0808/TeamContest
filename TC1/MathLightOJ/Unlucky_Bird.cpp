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
    double v1,v2,v3,a1,a2,t1,t2,t3, bird, trains;
    cin >> v1 >> v2 >> v3 >> a1 >> a2;
    t3 = max((1.0 * v1)/a1, (1.0 * v2)/a2);
    bird = t3 * v3;
    trains = v1 * (v1/a1) - (0.5 * a1 * (v1/a1) * (v1/a1));
    trains += v2 * (v2 / a2) - (0.5 * a2 * (v2/a2) * (v2/a2));
    cout << fixed << setprecision(10) << trains << " " << bird << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        Solve();
    }
    return 0;
}