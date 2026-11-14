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
int dp[20][2][4];
vector<int> dig;
void reset(int x){
    memset(dp, -1, sizeof(dp));
    dig.clear();
    while(x){
        dig.push_back(x%10);
        x /= 10;
    }
    reverse(dig.begin(), dig.end());
}
int rec(int pos, int tgt, int nz){
    if(nz > 3) return 0;
    if(pos == dig.size()) return 1;
    if(dp[pos][tgt][nz] != -1) return dp[pos][tgt][nz];
    int lim = tgt ? dig[pos] : 9;
    int cnt = 0;
    for(int d = 0; d<=lim; d++){
        // if(d > 0 && nz == 3) continue;
        int nt = tgt && d == lim;
        cnt += rec(pos + 1, nt, nz + (d > 0));
    }
    return dp[pos][tgt][nz] = cnt;
}
void Solve()
{
    int l, r;
    cin >> l >> r;
    reset(l-1);
    int ll = rec(0, 1, 0);
    reset(r);
    int rr = rec(0, 1, 0);
    cout << rr - ll << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}