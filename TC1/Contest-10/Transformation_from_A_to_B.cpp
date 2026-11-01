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
// int dfs(int a, int b){
//     if()
// }
void Solve()
{
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    int bb = b;
    vector<int> ans;
    while(b > a){
        if(b % 2 == 0) b /= 2, cnt++, ans.push_back(b);
        else if((b - 1) % 10 == 0) b = (b - 1) / 10, cnt++, ans.push_back(b);
        else{
            cout << "NO" << endl;
            return;
        }
    }
    if(b != a){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    ans.push_back(bb);
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i : ans) cout << i << " ";
    cout << endl;
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