#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif
#define int long long
using ll = long long;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void Solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n);
    for(int i=0; i<n; i++) cin >> vp[i].first >> vp[i].second;
    sort(vp.begin(), vp.end());
    ordered_set<int> st;
    int ans = 0;
    for(int i=0; i<n; i++){
        int val = vp[i].second;
        auto in = st.order_of_key(val);
        int dis = st.size() - in;
        ans += min(i, dis);
        st.insert(vp[i].second);
    }
    cout << ans << endl;
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