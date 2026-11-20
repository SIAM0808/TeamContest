#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
const int MAX = 5e6 + 10;
vector<int> phi(MAX);
vector<ll> phiCnt(MAX, 0);
void build(){
    iota(phi.begin(), phi.end(), 0);
    for(int i=2; i<MAX; i++){
        if(phi[i] == i){
            for(int j=i; j<=MAX; j += i){
                phi[j] -= phi[j]/i;
            }
        }
    }
    for(int i=2; i<MAX; i++){
        if(phiCnt[phi[i]] == 0) phiCnt[phi[i]] = i;
    }

    for(int i=MAX-2; i>=1; i--){
        if(phiCnt[i] == 0 ||(phiCnt[i+1] != 0 && phiCnt[i+1] < phiCnt[i])){
            phiCnt[i] = phiCnt[i+1];
        }
    }
}
void Solve()
{
    int n;
    cin >> n;
    ll ans = 0;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        ans += 1LL * phiCnt[x];
    }
    cout << ans << " Xukha" << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    build();
    cin >> t;
    for(int i=1; i<=t; i++){
        cout << "Case " << i << ": ";
        Solve();
    }
    return 0;
}