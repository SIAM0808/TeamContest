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
vector<vector<int>> v;
vector<int> cost;
vector<int> par;
void Solve(){
    int n, m;
    cin >> n >> m;
    v.assign(n+1, vector<int>{});
    par.assign(n+1, 0);
    iota(par.begin(), par.end(), 0);
    cost.assign(n+1, INT_MAX);
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        // cerr << x << " " << y << endl;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    cost[1] = 0;
    while(!q.empty()){
        int nod = q.front();
        q.pop();
        for(int i : v[nod]){
            // debug(nod);
            if(cost[i] > cost[nod] + 1){
                cost[i] = cost[nod] + 1;
                par[i] = nod;
                q.push(i);
            }
        }
    }
    vector<int> ans;
    if(cost[n] >= INT_MAX){
        cout << "IMPOSSIBLE\n";
        return;
    }
    // for(int i : par) cerr << i << " ";
    int x = n;
    while(par[x] != x){
        ans.push_back(x);
        x = par[x];
    }
    ans.push_back(x);
    reverse(ans.begin(), ans.end());
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