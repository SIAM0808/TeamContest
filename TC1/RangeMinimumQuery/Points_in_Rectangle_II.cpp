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
    vector<int> tree;
    Fenwick(int n) : n(n), tree(n + 1, 0) {}
    void add(int i, int delta) {
        for (++i; i <= n; i += i & -i) tree[i] += delta;
    }
    int query(int i) {
        int sum = 0;
        for (++i; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
    int query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};
void Solve()
{
    int p, q;
    cin >> p >> q;
    vector<int> y_cor;
    vector<event> events;
    for(int i=0; i<p; i++){
        int x, y;
        cin >> x >> y;
        events.push_back({x, 0, y, y, 0, -1});
        y_cor.push_back(y);
    }
    for(int i=0; i<q; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        events.push_back({x1-1, 1, y1, y2, -1, i});
        events.push_back({x2, 1, y1, y2, 1, i});
        y_cor.push_back(y1);
        y_cor.push_back(y2);
    }
    sort(y_cor.begin(), y_cor.end());
    y_cor.erase(unique(y_cor.begin(), y_cor.end()), y_cor.end());
    auto get_y_idx = [&](int y){
        return lower_bound(y_cor.begin(), y_cor.end(), y) - y_cor.begin();
    };
    sort(events.begin(), events.end());
    Fenwick ft(y_cor.size());
    vector<int> ans(q);
    for(auto &ev : events){
        if(ev.type == 0){
            int y_idx = get_y_idx(ev.y1);
            ft.add(y_idx, 1);
        }else{
            int l = get_y_idx(ev.y1);
            int r = get_y_idx(ev.y2);
            int cnt = ft.query(l, r);
            ans[ev.id] += ev.sign * cnt;
        }
    }
    // cout << "Case"
    for(int i : ans) cout << i << endl;
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