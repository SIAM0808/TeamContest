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
    string s;
    cin >> s;
    int nb, ns, nc;
    cin >> nb >> ns >> nc;
    int pb, ps, pc;
    cin >> pb >> ps >> pc;
    int rr; cin >> rr;
    map<char, int> mp, pr, ache;
    ache['B'] = nb, ache['S'] = ns, ache['C'] = nc;
    pr['B'] = pb, pr['C'] = pc, pr['S'] = ps;

    auto parbe = [&](int k) -> int{
        int khoroch = 0;
        for(auto [x, y] : mp){
            int lagbe = y * k;
            if(ache[x] < lagbe) khoroch += (lagbe - ache[x]) * pr[x];
        }
        return khoroch <= rr;
    };
    for(auto i : s) mp[i]++;
    int l = 0, r = 2e12;
    int ans = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(parbe(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << endl;
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