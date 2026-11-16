#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
/*
    nxt_rem = (numRem * 10 + d) % k
    base case
    if(i == sz){
        return numRem == 0;
    }
*/
int dp[10][91][91][2];
int a, b, k;
vector<int> dig;
void reset(int a){
    memset(dp, -1, sizeof(dp));
    dig.clear();
    while(a){
        dig.push_back(a%10);
        a /= 10;
    }
    reverse(dig.begin(), dig.end());
}
int f(int i, int numRem, int sumRem, int tgt){
    if(i == dig.size()){
        return numRem == 0 && sumRem == 0;
    }
    if(dp[i][numRem][sumRem][tgt] != -1) return dp[i][numRem][sumRem][tgt];
    int lim = tgt ? dig[i] : 9;
    int ans = 0;
    for(int d=0; d<=lim; d++){
        int nTgt = tgt && d == dig[i];
        int nrem = (10 * numRem + d) % k;
        int nSumRem = (sumRem + d) % k;
        ans += f(i+1, nrem, nSumRem, nTgt);
    }
    return dp[i][numRem][sumRem][tgt] = ans;
}
int cal(int x){
    reset(x);
    return f(0, 0, 0, 1);
}
void Solve()
{
    cin >> a >> b >> k;
    if(k > 90){
        cout << 0 << endl;
        return;
    }
    cout << cal(b) - cal(a-1) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for(int i=1; i<=t; i++){
        cout << "Case " << i << ": ";
        Solve();
    }
    return 0;
}