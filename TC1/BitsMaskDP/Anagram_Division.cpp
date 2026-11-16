#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
#define int long long
int dp[1 << 10][1005];
int fact[11];
void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= 10; i++) {
        fact[i] = fact[i - 1] * i;
    }
}
int rec(int msk, int rem, int n, string &s){
    if(msk == (1 << s.size()) - 1){
        return rem == 0;
    }
    if(dp[msk][rem] != -1) return dp[msk][rem];
    int ans = 0;
    for(int i=0; i<s.size(); i++){
        if((msk & (1 << i)) == 0){
            int dg = s[i] - '0';
            int nxt = msk | (1 << i);
            int nrem = (rem * 10 + dg) % n;
            ans += rec(nxt, nrem, n, s);
        }
    }
    return dp[msk][rem] = ans;
}
void Solve()
{
    memset(dp, -1, sizeof(dp));
    string s;
    int n;
    cin >> s >> n;
    int total = rec(0, 0, n, s);
    int fre[10] = {0};
    for(auto i : s) fre[i -'0']++;
    for(int i=0; i<10; i++) total /= fact[fre[i]];
    cout << total << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    precompute();
    cin >> t;
    for(int i=1; i<=t; i++){
        cout << "Case " << i << ": ";
        Solve();
    }
    return 0;
}