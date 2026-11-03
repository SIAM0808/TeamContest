#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
vector<int> ans;
vector<vector<int>> v;
map<pair<int, int>, int> mp;
int dfs(int c, int p){
    // if(v[c].size() == 1){
    //     if(mp[{p, c}] == 2){
    //         ans.push_back(c);
    //         return 1;
    //     }
    // }
    int cost = 0;
    for(int i : v[c]){
        if(i != p){
            cost += dfs(i, c);
        }
    }
    int f =  cost == 0 && mp[{p, c}] == 2;
    if(f){
        ans.push_back(c);
        return 1;
    }
    else return cost;
}
void Solve()
{
    int n;
    cin >> n;
    v.assign(n+1, vector<int>{});
    for(int i=0; i<n-1; i++){
        int x, y, z;
        cin >> x >> y >> z;
        v[x].push_back(y);
        v[y].push_back(x);
        mp[{x, y}] = z;
        mp[{y, x}] = z;
    }
    dfs(1, -1);
    cout << ans.size() << endl;
    for(int i : ans) cout << i << " ";
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