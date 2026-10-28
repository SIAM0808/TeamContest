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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char, int> mp;
    int cnt = 0,  l = 0;
    int ans = 0;
    for(int i=0; i<n; i++){
        if(s[i] == 'b') cnt++;
        // mp[s[i]]++;
        if(cnt > k){
            while(cnt > k){
                if(s[l] == 'b') cnt--;
                l++;
            }
        }
        ans = max(ans, i - l + 1);
    }
    mp.clear();
    cnt = 0, l = 0;
    for(int i=0; i<n; i++){
        if(s[i] == 'a') cnt++;
        // mp[s[i]]++;
        if(cnt > k){
            while(cnt > k){
                // mp[s[l]]--;
                if(s[l] == 'a') cnt--;
                l++;
            }
        }
        ans = max(ans, i - l + 1);
    }
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