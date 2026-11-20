#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
int M = 1e8 + 2;
vector<double> h(M/100 + 1);
void pre(){
    double sum = 0;
    for(int i=1; i<=M; i++){
        sum += 1.0 / i;
        if(i % 100 == 0) h[i/100] = sum;
    }
}
void Solve()
{
    int n;
    cin >> n;
    int id = n/100;
    double ans = h[id];
    for(int i=id*100 + 1; i<= n; i++){
        ans += 1.0 / i;
    }
    cout << fixed << setprecision(10) << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    pre();
    cin >> t;
    for(ll i = 1; i <= t; i++){
        cout << "Case " << i << ": ";
        Solve();
    }
    return 0;
}