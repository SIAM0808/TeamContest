#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif
#define ll unsigned long long
// using ll = long long;
const int MAX = 5e6 + 10;
vector<int> phi(MAX);
vector<ll> phiSum(MAX, 0);
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
        phiSum[i] = (ll)((ll)phi[i] * (ll)phi[i]) + phiSum[i-1];
    }
}
void Solve()
{
    int a, b;
    cin >> a >> b;
    cout << phiSum[b] - phiSum[a-1] << endl;
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