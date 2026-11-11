#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
struct event{
    int x, type, y1, y2;
    int sign, id;
    bool operator<(const event& other) const{
        if(x != other.x) return x < other.x;
        return type < other.type;
    }
};
struct Fenwick {
    int n;
    vector<vector<int>> tree;
    Fenwick(int n) : n(n), tree(n + 1, vector<int>(n + 1, 0)) {}
    
    void add(int x, int y, int delta) {
        for (int i = x + 1; i <= n; i += i & -i)
            for (int j = y + 1; j <= n; j += j & -j)
                tree[i][j] += delta;
    }
    int query(int x, int y) {
        int sum = 0;
        for (int i = x + 1; i > 0; i -= i & -i)
            for (int j = y + 1; j > 0; j -= j & -j)
                sum += tree[i][j];
        return sum;
    }
    int query(int x, int l, int r) {
        if (x < 0 || l > r) return 0;
        return query(x, r) - query(x, l - 1);
    }
};
bool vis[1005][1005];
void Solve()
{
    int p, q = 0;
    cin >> p;
    vector<event> events;
    memset(vis, 0, sizeof(vis));

    for(int i=0; i<p; i++){
        int t, x1, y1;
        cin >> t >> x1 >> y1;
        if(t == 0){
            if(!vis[x1][y1]){
                vis[x1][y1] = true;
                events.push_back({x1, 0, y1, y1, 0, -1});
            }
        }else{
            int x2, y2;
            cin >> x2 >> y2;
            events.push_back({x1-1, 1, y1, y2, -1, q});
            events.push_back({x2, 1, y1, y2, 1, q});
            q++;
        }
    }
    Fenwick ft(1001);
    vector<int> ans(q, 0);
    for(auto &ev : events){
        if(ev.type == 0){
            ft.add(ev.x, ev.y1, 1);
        }else{
            int cnt = ft.query(ev.x, ev.y1, ev.y2);
            ans[ev.id] += ev.sign * cnt;
        }
    }

    for(int i : ans) cout << i << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for(int i=1; i<=t; i++){
        cout << "Case " << i << ":\n";
        Solve();
    }
    return 0;
}