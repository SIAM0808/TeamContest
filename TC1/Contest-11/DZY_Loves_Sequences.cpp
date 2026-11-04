#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;

void Solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    int l = 0, r = 1;
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    pair<int, int> p = {v[l], -1};
    int mx = 1, cnt = 0;
    while(r < n){
        if(r == l){
            r++;
            continue;
        }
        if(p.first >= v[r]){
            if(cnt){
                if(l < p.second - 1){
                    l = p.second - 1;
                    p.first = v[p.second];
                    cnt = 1;
                    r = p.second;
                }else{
                    l = p.second;
                    p.first = v[l];
                    cnt = 0;
                    r = l;
                }
            }else{
                bool clp = (r - 1 == l) || (v[r] - v[r-2] >= 2);
                bool rcf = (r + 1 < n) && (v[r+1] <= v[r-1] + 1);

                if(clp && rcf){
                    p.first = v[r];
                }else{
                    p.first = v[r-1] + 1;
                }
                p.second = r;
                cnt++;
            }
        }else p.first = v[r];
        mx = max(mx, r - l + 1);
        r++;
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
