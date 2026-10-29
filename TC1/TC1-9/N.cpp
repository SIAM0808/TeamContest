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
    vector<int> vis(n, 0);
    auto bfs = [&](int src) -> int{
        vector<int> pos;
        queue<int> q;
        
        vis[src] = 1;
        q.push(src);
        pos.push_back(src);
        
        while(q.size()){
            int i = q.front();
            q.pop();
            
            int pal = n - 1 - i;
            int kk = i + k;
            
            if(kk < n && !vis[kk]) {
                vis[kk] = 1;
                q.push(kk);
                pos.push_back(kk);
            }
            if(!vis[pal]) {
                vis[pal] = 1;
                q.push(pal);
                pos.push_back(pal);
            }
            if(i - k >= 0 && !vis[i-k]) {
                vis[i-k] = 1;
                q.push(i-k);
                pos.push_back(i - k);
            }
        }
        set<int> st;
        map<char, int> mp;
        for(int i : pos) st.insert(s[i]), mp[s[i]]++;
        vector<int> res;
        for(auto [x, y] : mp){
            res.push_back(y);
        }
        sort(res.begin(), res.end());
        int sum = 0;
        for(int i=0; i<res.size()-1; i++) sum += res[i];
        st.clear();
        mp.clear();
        pos.clear();
        res.clear();
        return sum;
    };
    int ans = 0;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            ans += bfs(i);
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) {
        Solve();
    }

    return 0;
}


