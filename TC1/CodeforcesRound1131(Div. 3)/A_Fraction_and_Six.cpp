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
    int n,m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    map<char, int> mp1, mp2;
    for(auto i : a) mp1[i]++;
    for(auto i : b){
        mp1[i]--;
    }
    int cnt = 0;
    for(auto [x, y] : mp1){
        if(y) cnt++;
    }
    if(cnt != 3) cout << "NO" << endl;
    else{
        if(mp1['s'] == 1 && mp1['i'] == 1 && mp1['x'] == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
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