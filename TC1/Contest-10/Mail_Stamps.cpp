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
    map<int, vector<int>> mp;
    for(int i=1; i<=n; i++){
        int x, y;
        cin >> x >> y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    int st = -1;
    for(auto [x, y] : mp){
        if(y.size() == 1){
            st = x;
            break;
        }
    }
    // cout << st << " ";
    int prev = -1;
    for(int i=0; i<=n; i++){
        cout << st << " ";
        int porer = -1;
        for(int u : mp[st]){
            if(prev != u){
                porer = u;
                break;
            }
        }
        prev = st;
        st = porer;
    }
    cout << endl;
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