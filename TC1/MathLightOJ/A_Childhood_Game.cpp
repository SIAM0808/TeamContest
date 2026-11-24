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
    string s, a = "Alice", b = "Bob";
    int n;
    cin >> n >> s;
    if(s == a){
        if(n%3 == 1) cout << b;
        else cout << a;
    }else{
        if(n%3 == 0) cout << a;
        else cout << b;
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        Solve();
    }
    return 0;
}