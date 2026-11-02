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
    int n, q;
    cin >> n >> q;
    multiset<int> ms;
    vector<vector<int>> v(n+1);
    int in = 0;
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int x;
            cin >> x;
            in++;
            ms.insert(in);
            v[x].push_back(in);
            cout << ms.size() << endl;
        }else if(t == 2){
            int x;
            cin >> x;
            // ms.erase(x);
            for(int j : v[x]){
                ms.erase(j);
            }
            v[x].clear();
            cout << ms.size() << endl;
        }else{
            int x;
            cin >> x;
            while(!ms.empty() && *ms.begin() <= x){
                ms.erase(ms.begin());
                // x--;
            }
            cout << ms.size() << endl;
        }
    }
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