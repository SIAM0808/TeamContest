#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
struct node{
    int x;
    char type;
    bool operator<(const node &other) const{
        if(x != other.x) return x < other.x;
        return type == '-' && other.type == '+';
    }
};
void Solve()
{
    int n;
    cin >> n;
    vector<node> v;
    for(int i=0; i<n; i++){
        int l, r;
        cin >> l >> r;
        v.push_back({l, '+'});
        v.push_back({r+1, '-'});
    }
    sort(v.begin(), v.end());
    int mx = 0, cnt= 0;
    for(auto nd : v){
        if(nd.type == '+') cnt++, mx = max(mx, cnt);
        else cnt--;
    }
    cout << mx << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--)
        Solve();
    return 0;
}