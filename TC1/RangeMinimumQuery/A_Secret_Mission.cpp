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

struct DSU {
    vector<int> parent, sz;
    int components;

    DSU(int n = 0) {
        init(n);
    }

    void init(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n + 1, 1);
        components = n;
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (sz[x] < sz[y])
            swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];
        components--;
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return sz[find(x)];
    }
};
const int INF = 1e18;
struct state {
    int mx;
    state() {mx = -1e18;}
    state(int x) {
        this->mx = x;
    }
};
state make_identity() {
    return state{-INF};
}
state combine(const state &a, const state &b) {
    state c;
    c.mx = max(a.mx, b.mx);
    return c.mx;
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
    void build(int node, int l, int r) {
        if (l == r) {
            sgt[node] = a[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
        sgt[node] = combine(sgt[2 * node], sgt[2 * node + 1]);
    }
    void update(int node, int l, int r, int idx, const state &value) {
        if (l == r) {
            sgt[node] = value;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
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
    void build(const vector<state> &a) {
        this->a = a;
        build(1, 1, n);
    }
    void update(int idx, state val) { update(1, 1, n, idx, val); }
    state query(int l, int r) { 
        if (l > r) return make_identity();
        return query(1, 1, n, l, r); 
    }
};

struct HLD {
    int n;
    vector<vector<int>> g;
    vector<int> val;
    vector<int> parent, depth, heavy, sz, head, pos;
    int cur_pos;
    bool is_edge;

    SegmentTree seg;
    HLD(int n = 0) { init(n); }
    void init(int n_) {
        n = n_;
        g.assign(n + 1, {});
        val.assign(n + 1, 0);
        parent.assign(n + 1, -1);
        depth.assign(n + 1, 0);
        heavy.assign(n + 1, -1);
        sz.assign(n + 1, 0);
        head.assign(n + 1, 0);
        pos.assign(n + 1, 0);
        cur_pos = 1;
        is_edge = false;
        seg.init(n);
    }
    void addEdge(int u, int v) { g[u].push_back(v), g[v].push_back(u); }
    void setValue(int u, int x) { val[u] = x; }

    int dfs_sz(int u, int p) {
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
    void dfs_hld(int u, int h) {
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

    // Call this for Node-based HLD
    void build_node(int root = 1) {
        is_edge = false;
        dfs_sz(root, -1);
        dfs_hld(root, root);
        vector<state> base(n + 2, make_identity());
        for (int u = 1; u <= n; ++u) {
            base[pos[u]] = state(val[u]);
        }
        seg.build(base);
    }

    // Call this for Edge-based HLD (edges = {u, v, wt})
    void build_edge(int root, const vector<array<int, 3>> &edges) {
        is_edge = true;
        dfs_sz(root, -1);
        dfs_hld(root, root);
        for (auto &e : edges) {
            int child = (depth[e[0]] > depth[e[1]]) ? e[0] : e[1];
            setValue(child, e[2]);
        }
        vector<state> base(n + 2, make_identity());
        for (int u = 1; u <= n; ++u) {
            if (u != root) {
                base[pos[u]] = state(val[u]);
            }
        }
        seg.build(base);
    }

    // Node value update: u-th node = x
    void pointSet(int u, int x) {
        val[u] = x;
        seg.update(pos[u], state(x));
    }

    // Edge weight update: edge (u, v) = x
    void updateEdge(int u, int v, int x) {
        int child = (depth[u] > depth[v]) ? u : v;
        pointSet(child, x);
    }

    // Works automatically for both Node and Edge queries
    state queryPath(int u, int v) {
        state res = make_identity();
        while (head[u] != head[v]) {
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
        if (!is_edge || u != v) {
            state last = seg.query(pos[u] + is_edge, pos[v]);
            res = combine(res, last);
        }
        return res;
    }

    state SegmentQuery(int l, int r) { return seg.query(l, r); }
    state SubtreeQuery(int u) { return seg.query(pos[u] + is_edge, pos[u] + sz[u] - 1); }
    state PathQuery(int u, int v) { return queryPath(u, v); }
};
void Solve()
{
    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }
    sort(edges.begin(), edges.end(), [&](array<int, 3> &x, array<int, 3> &y){
        return x[2] < y[2];
    });

    HLD hld(n);
    DSU dsu(n);
    vector<array<int, 3>> nisi;
    for (auto [u, v, wt] : edges) {
        if (dsu.unite(u, v)) {
            nisi.push_back({u, v, wt});
            hld.addEdge(u, v);
        }
    }
    hld.build_edge(1, nisi);
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        state ans = hld.queryPath(l, r);
        cout << ans.mx << endl;
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