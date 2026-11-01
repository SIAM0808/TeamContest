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

void Solve()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    int ans = 0;
    int n = s.size();
    int tem = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '0') tem++;
        else{
            ans += (tem * (tem + 1)) / 2;
            tem = 0;
        }
    }
    ans += (tem * (tem + 1)) / 2;
    if(k == 0){
        cout << ans << endl;
        return;
    }
    ans = 0;
    deque<pair<int,int>> v;
    int l = 0, r = 0, cnt = 0;
    while(r < n){
        if(s[r] == '1') cnt++;
        if(cnt == k){
            while(s[l] == '0') l++;
            v.push_back({l, r});
            l++;
            // debug(l);
            cnt--;
        }
        // debug(cnt);
        // debug(r);
        r++;
    }
    v.push_front({-1, -1});
    v.push_back({n, n});
    int sz = v.size();
    debug(sz);
    // for(auto [x, y] : v) cerr << x << " " << y << endl;
    // cerr << 323 << endl;
    // ans += n - 1 - v[sz-1].second;
    for(int i=1; i<sz-1; i++){
        debug(i);
        int prevL = v[i-1].first;
        int postR = v[i+1].second;
        auto [l, r] = v[i];
        int left = l - prevL - 1;
        int right = postR - r - 1;
        // debug(left);
        // debug(right);
        ans += 1 + left + right + (left * right);
    } 
    // if(n == 1){
    //     int lft = v[0].first;
    //     int rgt = n - 1 - v[0].second;
    //     ans += 1 + lft + rgt + (lft * rgt);
    // }else{
    //     int lft 
    // }
    cout << ans << endl;
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