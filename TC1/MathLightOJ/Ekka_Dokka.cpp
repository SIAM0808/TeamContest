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
    ll w;
    cin >> w;
    ll cnt2 = 0;
    while(w > 1 && w&1^1) w >>= 1, cnt2++;
    if(cnt2 == 0) cout << "Impossible" << endl;
    else{
        cout << w << " " << powl(2, cnt2) << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for(ll i=1; i<=t; i++){
        cout << "Case " << i << ": ";
        Solve();
    }
    return 0;
}