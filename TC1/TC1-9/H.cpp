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
    vector<int> w(n+1);
    for(int i=1; i<=n; i++) cin >> w[i];
    vector<int> deg(n+1);
    vector<vector<int>> v(n+1);
    for(int i=0; i<n-1; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1; i<=n; i++) deg[i] = v[i].size();
    priority_queue<pair<int, int>> pq;
    for(int i=1; i<=n; i++){
        if(v[i].size() > 1)
        pq.push({w[i], i});
    }
    int sum = accumulate(w.begin(), w.end(), 0LL);
    // for(int i : deg) cerr << i << " ";
    //     cerr << endl;
    for(int i=1; i<=n-1; i++){
        if(i == 1) cout << sum << " ";
        else{
            auto [x, y] = pq.top();
            if(deg[y] > 1){
                sum += x; 
                deg[y]--;
            }
            if(deg[y] <= 1){
                pq.pop();
                // continue;
            }
            cout << sum << " ";
        }
    }
    cout << endl;
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