#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
vector<int> digits;
int vis[20][2];
pair<ll,  ll> dp[20][2];
pair<ll, ll> dfs(int pos, int tight){
    if(pos == digits.size()) return {1, 0};
    if(vis[pos][tight]) return {dp[pos][tight]};
    ll cnt = 0, sum = 0;
    int limit = tight? digits[pos] : 9;
    for(int i=0; i<=limit; i++){
        int nt = tight && i == limit;
        auto child = dfs(pos + 1, nt);
        cnt += child.first;
        sum += child.second + 1LL * i * child.first;
    }
    vis[pos][tight] = 1;
    return dp[pos][tight] = {cnt, sum};
}
void clear(){
    for(int i=0; i<20; i++){
        dp[i][0] = dp[i][1] = {0, 0};
        vis[i][0] = vis[i][1] = 0;
    }
}
void Solve()
{
    int a, b;
    while(cin >> a >> b){
        if(a == -1) break;
        clear();
        auto dig = [&](int a) -> void{
            digits.clear();
            while(a){
                digits.push_back(a%10);
                a /= 10;
            }
            reverse(digits.begin(), digits.end());
        };
        dig(b);
        pair<ll, ll> sum = dfs(0, 1);
        if(a == 0) cout << sum.second << endl;
        else{
            clear();
            dig(a-1);
            cout << sum.second - dfs(0, 1).second << endl;
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