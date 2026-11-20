
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
    ll p, l;
    cin >> p >> l;

    ll x = p - l;

    if(x <= l){
        cout << "impossible" << endl;
        return;
    }

    vector<ll> v;

    for(ll i = 1; i <= x / i; i++){
        if(x % i == 0){
            if(i > l) v.push_back(i);

            if(x / i != i && x / i > l)
                v.push_back(x / i);
        }
    }

    sort(v.begin(), v.end());

    if(v.empty()){
        cout << "impossible" << endl;
        return;
    }

    for(ll i : v) cout << i << " ";
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    ll t = 1;
    cin >> t;

    for(ll i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        Solve();
    }

    return 0;
}
