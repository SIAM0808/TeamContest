#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
struct state {
    int val;
};
struct lazy_state {
    int add, assignemnt;
    bool pending;
};
state combine(state a, state b) {
    return {a.val + b.val};      // sum
    // return {min(a.val , b.val)}; // min
}
state identity_state() {
    return {0};                  // Edit here
}
lazy_state identity_lazy() {
    return {0, 0, false};        // edit here
}
void propagate(state &x, lazy_state &g, const lazy_state &f, int len) {
    if (f.pending) {
        x.val = f.assignemnt * len;
        g.assignemnt = f.assignemnt;
        g.pending = true;
        g.add = 0;
    }
    if (f.add != 0) {
        x.val += f.add * len;
        g.add += f.add;
    }
}
struct segment_tree {
    int n;
    vector<state> st;
    vector<lazy_state> lz;

    void init(int _n) {
        n = _n;
        st.assign(4 * n + 4, identity_state());
        lz.assign(4 * n + 4, identity_lazy());
    }
    void apply(int p, int l, int r, const lazy_state &f) {
        propagate(st[p], lz[p], f, r - l + 1);
    }
    void push(int p, int l, int r) {
        int m = (l + r) >> 1;
        apply(p << 1, l, m, lz[p]);
        apply(p << 1 | 1, m + 1, r, lz[p]);
        lz[p] = identity_lazy();
    }
    void build(vector<state> &base, int p, int l, int r) {
        if (l == r) {
            st[p] = base[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(base, p << 1, l, mid);
        build(base, p << 1 | 1, mid + 1, r);
        st[p] = combine(st[p << 1], st[p << 1 | 1]);
    }
    void update(int p, int l, int r, int ql, int qr, const lazy_state &f) {
        if (qr < l or r < ql) return;
        if (ql <= l and r <= qr) {
            apply(p, l, r, f);
            return;
        }
        push(p, l, r);
        int m = (l + r) >> 1;
        update(p << 1, l, m, ql, qr, f);
        update(p << 1 | 1, m + 1, r, ql, qr, f);
        st[p] = combine(st[p << 1], st[p << 1 | 1]);
    }
    state query(int p, int l, int r, int ql, int qr) {
        if (qr < l or r < ql) return identity_state();
        if (ql <= l and r <= qr) return st[p];
        push(p, l, r);
        int mid = (l + r) >> 1;
        state left = query(p << 1, l, mid, ql, qr);
        state right = query(p << 1 | 1, mid + 1, r, ql, qr);
        return combine(left, right);
    }
    void build(vector<state> &base) { build(base, 1, 1, n); }
    void update(int l, int r, const lazy_state &f) { update(1, 1, n, l, r, f); }
    state query(int l, int r) { return query(1, 1, n, l, r); }
};
void Solve()
{
    int n;
    cin >> n;
    segment_tree st;
    st.init(2*n);
    int idx = 1;
    for(int i=0; i<n; i++){
        int l, r;
        cin >> l >> r;
        lazy_state lz = {0, idx, true};
        st.update(l, r, lz);
        ++idx;
    }
    set<int> s;
    for(int i=1; i<=2*n; i++){
        int val = st.query(i, i).val;
        if(val)
        s.insert(val);
    }
    cout << s.size() << endl;
    // for(int i : s) cerr << i << " ";
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for(int i=1; i<=t; i++){
        cout << "Case " << i  << ": ";
        Solve();
    }
    return 0;
}