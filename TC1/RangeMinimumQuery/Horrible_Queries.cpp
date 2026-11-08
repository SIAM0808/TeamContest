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
    ll val;
};
struct lazy_state {
    ll add, assignemnt;
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
void propagate(state &x, lazy_state &g, const lazy_state &f, ll len) {
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
    ll n;
    vector<state> st;
    vector<lazy_state> lz;

    void init(ll _n) {
        n = _n;
        st.assign(4 * n + 4, identity_state());
        lz.assign(4 * n + 4, identity_lazy());
    }
    void apply(ll p, ll l, ll r, const lazy_state &f) {
        propagate(st[p], lz[p], f, r - l + 1);
    }
    void push(ll p, ll l, ll r) {
        ll m = (l + r) >> 1;
        apply(p << 1, l, m, lz[p]);
        apply(p << 1 | 1, m + 1, r, lz[p]);
        lz[p] = identity_lazy();
    }
    void build(vector<state> &base, ll p, ll l, ll r) {
        if (l == r) {
            st[p] = base[l];
            return;
        }
        ll mid = (l + r) >> 1;
        build(base, p << 1, l, mid);
        build(base, p << 1 | 1, mid + 1, r);
        st[p] = combine(st[p << 1], st[p << 1 | 1]);
    }
    void update(ll p, ll l, ll r, ll ql, ll qr, const lazy_state &f) {
        if (qr < l or r < ql) return;
        if (ql <= l and r <= qr) {
            apply(p, l, r, f);
            return;
        }
        push(p, l, r);
        ll m = (l + r) >> 1;
        update(p << 1, l, m, ql, qr, f);
        update(p << 1 | 1, m + 1, r, ql, qr, f);
        st[p] = combine(st[p << 1], st[p << 1 | 1]);
    }
    state query(ll p, ll l, ll r, ll ql, ll qr) {
        if (qr < l or r < ql) return identity_state();
        if (ql <= l and r <= qr) return st[p];
        push(p, l, r);
        ll mid = (l + r) >> 1;
        state left = query(p << 1, l, mid, ql, qr);
        state right = query(p << 1 | 1, mid + 1, r, ql, qr);
        return combine(left, right);
    }
    void build(vector<state> &base) { build(base, 1, 1, n); }
    void update(ll l, ll r, const lazy_state &f) { update(1, 1, n, l, r, f); }
    state query(ll l, ll r) { return query(1, 1, n, l, r); }
};
void Solve()
{
    ll n, q;
    cin >> n >> q;
    segment_tree ls;
    ls.init(n);
    while(q--){
        ll x;
        cin >> x;
        ll i, j;
        cin >> i >> j;
        i++, j++;

        if(x){
            cout << ls.query(i, j).val << endl;
        }else{
            ll val;
            cin >> val;
            lazy_state f = {val, 0, 0};
            ls.update(i, j, f);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for(ll i=1; i<=t; i++){
        cout << "Case " << i << ": \n";
        Solve();
    }
    return 0;
}