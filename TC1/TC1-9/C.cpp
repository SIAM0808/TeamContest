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
    int n;
    cin >> n;
    map<int,int> mp;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        mp[x] = i;
    }
    vector<int> v(n+1);
    iota(v.begin(), v.end(), 0);
    int prev = -1;
    for(int i=1; i<=n; i++){
        if(prev != -1){
            if(prev != mp[i]){
                cout << "No" << endl;
                return;
            }
        }
        int porer = mp[i] + 1;
        debug(porer);
        if(porer > n) v[mp[i]] = -1, prev = -1;
        else v[mp[i]] = v[porer], prev = v[porer];
        v[mp[i]] = -1;
        // for(int i=1; i<=n; i++) cerr << v[i] << " ";
        // cerr << endl;
        debug(prev);
    }
    cout << "Yes" << endl;
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