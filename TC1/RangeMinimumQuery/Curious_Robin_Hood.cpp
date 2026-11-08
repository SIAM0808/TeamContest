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
    state() {}
    state(int n) : val(n) {}
};
state make_identity() {
    return state{0};
}
state combine(const state &a, const state &b){
    state c;
    c.val = (a.val + b.val);
    return c;
}
struct SegmentTree {
    vector<state> sgt;
    vector<state> a;
    int n;
    void init(int N) {
        this -> n = N;
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
    void build(vector<int> &arr) {
        for (int i = 0; i < arr.size(); i++) {
            this->a[i + 1] = state(arr[i]);
        }
        build(1, 1, n);
    }
    void update(int idx, state val) { update(1, 1, n, idx, val); }
    state query(int l, int r) { return query(1, 1, n, l, r); }
};
void Solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    SegmentTree st;
    st.init(n);
    st.build(v);
    while(q--){
        int l;
        cin >> l;
        if(l == 1){
            int pos;
            cin >> pos;
            pos++;
            cout << st.query(pos, pos).val << endl;
            st.update(pos, 0);
        }else if(l == 2){
            int pos, val;
            cin >> pos >> val;
            pos++;
            state ans = st.query(pos, pos);
            st.update(pos, ans.val + val);
        }else{
            int i, j;
            cin >> i >> j;
            i++, j++;
            state ans = st.query(i, j);
            cout << ans.val << endl;
        }
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