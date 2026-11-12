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
    string s;
    cin >> s;
    int f = 0;
    for(int i=0; i<n/2; i++){
        if(s[i] != s[n-1-i]){
            f = 1;
            break;
        }
    }
    if(!f){
        cout << 0 << endl;
        return;
    }
    map<char, int> mp;
    for(int i=0; i<n/2; i++){
        char l = s[i];
        char r = s[n-1-i];
        for(char j = min(l, r) + 1; j <= max(l, r); j++){
            mp[j] = 1;
        }
    }
    int ans = 0;
    for(auto [x, y] : mp){
        ans += y >= 1;
    }
    cout << ans << endl;
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