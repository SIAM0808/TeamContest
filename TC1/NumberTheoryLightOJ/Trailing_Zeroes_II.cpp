#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
ll sz = 1e6 + 10;
vector<ll> p2(sz), p5(sz);
ll cou(ll x, ll f){
    ll cnt = 0;
    while(x % f == 0) cnt++, x /= f;
    return cnt;
}
void cal(){
    for(ll i=1; i<sz; i++){
        p2[i] = p2[i-1] + cou(i, 2);
        p5[i] = p5[i-1] + cou(i, 5);
    }
}
void Solve()
{
    ll n, r, p, q;
    cin >> n >> r >> p >> q;
    // p ^ q
    // ll mn = min(cou(p, 2), cou(p, 5));
    // ll right = q * mn;
    ll upore2 = p2[n], upore5 = p5[n];
    ll niche2 = p2[r] + p2[n-r], niche5 = p5[r] + p5[n-r];
    ll to = max(0LL, upore2 - niche2);
    ll five = max(0LL, upore5 - niche5);
    ll total2 = to + cou(p, 2) * q;
    ll total5 = five + cou(p, 5) * q;
    cout << min(total2, total5) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cal();
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        cout << "Case " << i << ": ";
        Solve();
    }
    return 0;
}