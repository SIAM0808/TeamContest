#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif
#define endl '\n'
using ll = long long;

struct segment_tree
{
    vector<int> a;
    vector<int> sgt, lazy;
    int n;
    segment_tree(int N)
    {
        this->n = N;
        a.assign(N + 1, 0);
        sgt.assign(N * 4, 0);
        lazy.assign(N * 4, 0);
    }
    void push(int node, int start, int end)
    {
        if (lazy[node] != 0)
        {
            sgt[node] += (end - start + 1) * lazy[node]; // Sum
            if (start != end)
            {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    int combine(int left, int right)
    {
        return left + right;
    }
    void build(int node, int start, int end)
    {
        if (start == end)
        {
            sgt[node] = a[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);
        sgt[node] = combine(sgt[2 * node], sgt[2 * node + 1]);
    }
    void update(int node, int start, int end, int l, int r, int value)
    {
        push(node, start, end);
        if (start > r or end < l)
        {
            return;
        }

        if (start >= l and r >= end)
        {
            lazy[node] += value;
            push(node, start, end);
            return;
        }
        int mid = start + (end - start) / 2;
        update(node * 2, start, mid, l, r, value);
        update(node * 2 + 1, mid + 1, end, l, r, value);
        sgt[node] = combine(sgt[2 * node], sgt[2 * node + 1]);
    }
    int query(int node, int start, int end, int ql, int qr)
    {
        push(node, start, end);
        if (start > qr or end < ql)
        {
            return 0; // Edit here
        }
        if (start >= ql and end <= qr)
        {
            return sgt[node];
        }
        int mid = start + (end - start) / 2;
        int left = query(node * 2, start, mid, ql, qr);
        int right = query(node * 2 + 1, mid + 1, end, ql, qr);
        return combine(left, right);
    }
    void build() { build(1, 1, n); }
    void update(int l, int r, int val) { update(1, 1, n, l, r, val); }
    int query(int l, int r) { return query(1, 1, n, l, r); }
};
void Solve(int tc)
{
    string s;
    cin >> s;
    vector<int> v(1, 0);
    for(auto i : s) v.push_back(i - '0');
    int n = s.size();
    segment_tree seg(n);
    seg.a = v;
    seg.build();

    int q;
    cin >> q;
    cout << "Case " << tc << ":" << endl;
    while(q--){
        char c;
        cin >> c;
        if(c == 'I'){
            int l, r;
            cin >> l >> r;
            if(l > r) swap(l, r);
            seg.update(l, r, 1);
        }else{
            int i;
            cin >> i;
            cout << seg.query(i, i) % 2 << endl;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case " << i << ":" << endl;
        Solve(i);
    }
    return 0;
}