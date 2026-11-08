#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif
#define int long long
const int INF = 1e18;
using ll = long long;
struct state {
    int mn, mx;
    state() {}
    state(int x) : mn(x), mx(x) {}
    state(int mn, int mx) : mn(mn), mx(mx) {}
};
state make_identity() {
    state node =  state(INF, -INF);
    return {INF, -INF};
}
state combine(const state &a, const state &b){
    state c;
    c.mn = min(a.mn, b.mn);
    c.mx = max(a.mx, b.mx);
    return c;
}
struct SegmentTree {
    vector<state> sgt;
    vector<state> a;
    int n;
    void init(int N) {
         this->n = N;
        a.assign(N + 1, make_identity());
        sgt.assign(N * 4 + 4, make_identity());
    }
    void build (int node, int l, int r) {
        if (l == r) {
            sgt[node] = a[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        sgt[node] = combine(sgt[2 * node], sgt[2 * node + 1]);
    }
    void update(int node, int l, int r, int idx, state &value) {
        if (l == r) {
            sgt[node] = value;
            return;
        }
        int mid = l + (r - l) / 2;
        if(idx <= mid) {
            update(node * 2, l, mid, idx, value);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, value);
        }
        sgt[node] = combine(sgt[2 * node], sgt[2 * node + 1]);
    }
    state query(int node, int l, int r, int ql, int qr) {
        if (l > qr or r < ql) {
            return make_identity();
        }
        if (l >= ql and r <= qr) {
            return sgt[node];
        }
        int mid = l + (r - l) / 2;
        state left = query(node * 2, l, mid, ql, qr);
        state right = query(node * 2 + 1, mid + 1, r, ql, qr);
        return combine(left, right);
    }
    void build(vector<state> &a) {
        this->a = a;
        build(1, 1, n);
    }
    void update(int idx, state val) { update(1, 1, n, idx, val); }
    state query(int l, int r) { return query(1, 1, n, l, r); }
};
struct HLD {
    int n;
    vector<vector<int>> g;
    vector<int> val;
    vector<int> parent, depth, heavy, sz, head, pos;
    int cur_pos;

    SegmentTree seg;
    HLD(int n = 0){ init(n); }
    void init(int n_) {
        n = n_;
        g.assign(n+1, {});
        val.assign(n+1, 0);
        parent.assign(n+1, -1);
        depth.assign(n+1, 0);
        heavy.assign(n+1, -1);
        sz.assign(n+1, 0);
        head.assign(n+1, 0);
        pos.assign(n+1, 0);
        cur_pos = 1;
        seg.init(n);
    }
    void addEdge(int u, int v) { g[u].push_back(v), g[v].push_back(u); }
    void setValue(int u, int x) { val[u] = x; }
    int dfs_sz(int u, int p){
        parent[u] = p;
        depth[u] = (p == -1 ? 0 : depth[p] + 1);
        sz[u] = 1;
        heavy[u] = -1;
        int best = 0;
        for (int v : g[u]) {
            if (v != p) {
                int sub = dfs_sz(v, u);
                sz[u] += sub;
                if (sub > best) {
                    best = sub;
                    heavy[u] = v;
                }
            }
        }
        return sz[u];
    }
    void dfs_hld(int u, int h){
        head[u] = h;
        pos[u] = cur_pos++;
        if (heavy[u] != -1) {
            dfs_hld(heavy[u], h);
        }
        for (int v : g[u]) {
            if (v != parent[u] && v != heavy[u]) {
                dfs_hld(v, v);
            }
        }
    }
    void build_node(int root = 1){
        dfs_sz(root, -1);
        dfs_hld(root, root);
        vector<state> base(n + 2, 0);
        for (int u = 1; u <= n; ++u) {
            base[pos[u]] = state(val[u]);
        }
        seg.build(base);
    }
    void build_edge(int root, vector<array<int, 3>> edges){
        dfs_sz(root, -1);
        dfs_hld(root, root);
        for(auto &e : edges){
            int child = (depth[e[0]] > depth[e[1]]) ? e[0] : e[1];
            setValue(child, e[2]);
        }
        vector<state> base(n+2, make_identity());
        for(int u = 1; u<=n; u++){
            if(u != root){
                base[pos[u]] = state(val[u]);
            }
        }
        seg.build(base);
    }
    void pointSet(int u, int x) {
        val[u] = x;
        seg.update(pos[u], x);
    }
    state queryPath(int u, int v) {
        state res = make_identity();
        while(head[u] != head[v]){
            if (depth[head[u]] < depth[head[v]]) {
                swap(u, v);
            }
            state cur = seg.query(pos[head[u]], pos[u]);
            res = combine(res, cur);
            u = parent[head[u]];
        }
        if (depth[u] > depth[v]) {
            swap(u, v);
        }
        if(depth[u] != depth[v]){
            state last = seg.query(pos[u] + 1, pos[v]);
            res = combine(res, last);
        }
        return res;
    }
    state SegmentQuery(int l, int r) { return seg.query(l, r); }
    state SubtreeQuery(int u) { return seg.query(pos[u], pos[u] + sz[u] - 1); }
    state PathQuery(int u, int v) { return queryPath(u, v); }
};
void Solve()
{
    int n;
    cin >> n;
    HLD hld(n);
    vector<array<int, 3>> edges;
    for(int i=0; i<n-1; i++){
        int x, y, wt;
        cin >> x >> y >> wt;
        hld.addEdge(x, y);
        edges.push_back({x, y, wt});
    }
    hld.build_edge(1, edges);
    int q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        state ans = hld.queryPath(u, v);
        cout << ans.mn << " " << ans.mx << endl;
    }
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