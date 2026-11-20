#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
int N = 1001;
vector<vector<int>> v(N);
vector<pair<int, int>> ans(N);

void Solve()
{
    int n;
    cin >> n;
    cout << ans[n].second << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    
    for(int i=1; i<=1000; i++){
        for(int j=1; j*j <= i; j++){
            if(i%j == 0){
                v[i].push_back(j);
                if(i/j != j) v[i].push_back(i/j);
            }
        }
    }
    for(int i=1; i<=1000; i++){
        ans[i].first = v[i].size();
        ans[i].second = i;
    }
    sort(ans.begin(), ans.end(), [](pair<int, int> a, pair<int, int> b){
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });



    ll t = 1;
    cin >> t;
    for(ll i=1; i<=t; i++){
        cout << "Case " << i << ": ";
        Solve();
    }
    return 0;
}