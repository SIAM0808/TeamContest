#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
template <typename T>
struct LazySegTree {
    int n;
    vector<T> tree, lazy;

    const T ID = 0;
    const T LAZY_ID = 0;

    LazySegTree(int n) : n(n), tree(4 * n, ID), lazy(4 * n, LAZY_ID) {}

    LazySegTree(const vector<T>& a) : n(a.size()), tree(4 * a.size(), ID), lazy(4 * a.size(), LAZY_ID) {
        if (n > 0) build(a, 1, 0, n - 1);
    }

    T merge(T a, T b) const {
        return a + b;
    }

    void apply(int node, int l, int r, T val) {
        tree[node] += val * (r - l + 1);
        lazy[node] += val;
    }

    void push(int node, int l, int r) {
        if (lazy[node] == LAZY_ID) return;
        int mid = l + (r - l) / 2;
        apply(2 * node, l, mid, lazy[node]);
        apply(2 * node + 1, mid + 1, r, lazy[node]);
        lazy[node] = LAZY_ID;
    }

    void build(const vector<T>& a, int node, int l, int r) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(a, 2 * node, l, mid);
        build(a, 2 * node + 1, mid + 1, r);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int ql, int qr, T val) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }
        push(node, l, r);
        int mid = l + (r - l) / 2;
        update(2 * node, l, mid, ql, qr, val);
        update(2 * node + 1, mid + 1, r, ql, qr, val);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    T query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return ID;
        if (ql <= l && r <= qr) return tree[node];
        push(node, l, r);
        int mid = l + (r - l) / 2;
        return merge(query(2 * node, l, mid, ql, qr), query(2 * node + 1, mid + 1, r, ql, qr));
    }

    void update(int l, int r, T val) {
        update(1, 0, n - 1, l, r, val);
    }

    T query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

void Solve()
{
    
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