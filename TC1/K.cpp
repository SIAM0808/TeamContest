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
vector<int> arr;
vector<int> seg_tree;
void build(int node, int begin, int end){
    if(begin == end){
        seg_tree[node] = arr[begin];
        return;
    }
    int l, r, mid;
    l = node * 2;
    r = node * 2 + 1;
    mid = (begin + end) >> 1;
    build(l, begin, mid);
    build(r, mid + 1, end);
    seg_tree[node] = min(seg_tree[l], seg_tree[r]);
}
int query(int node, int begin, int end, int i, int j){
    if(end < i || j < begin) return LLONG_MAX;
    if(i <= begin && end <= j) return seg_tree[node];
    int l = node*2;
    int r = node*2 + 1;
    int mid = (begin + end) >> 1;
    int q1 = query(l, begin, mid, i, j);
    int q2 = query(r, mid + 1, end, i, j);
    return min(q1, q2);
}
void Solve()
{
    int n, q;
    cin >> n >> q;
    arr.assign(n+2, 0);
    seg_tree.assign(4*n + 2, 0);
    for(int i=1; i<=n; i++) cin >> arr[i];
    build(1, 1, n);
    while(q--){
        int i, j;
        cin >> i >> j;
        cout << query(1, 1, n, i, j) << endl;
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