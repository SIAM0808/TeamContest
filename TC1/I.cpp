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

void Solve()
{
    string s1, s2, s3, t1, t2, t3;
    cin >> s1 >> s2 >> s3 >> t1 >> t2 >> t3;
    s2.pop_back(), t2.pop_back();
    int a = stoi(s3);
    // fflush(cout);
    int b = stoi(t3);
    debug(a);
    debug(b);
    debug(t2);
    int yr = 0;
    if(s1 != "January" && s1 != "February") yr++;
    a += yr;
    auto cal = [&](int xx) -> int{
        if(xx <= 0) return 0;
        return xx/4 + xx/400 - xx/100;
    };
    if(t1 == "January") b--;
    if(t1 == "February" && stoi(t2) <= 28) b--;
    cout << cal(b) - cal(a - 1) << endl;
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