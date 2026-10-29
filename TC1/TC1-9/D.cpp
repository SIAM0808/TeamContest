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
    string s("codeforces");
    vector<int> cnt(10, 1);
    ll totcnt = 1;
    ll k;
    cin >> k;
    int i = 0;
    while (totcnt < k)
    {
        totcnt /= cnt[i];
        cnt[i]++;
        totcnt *= cnt[i];
        i++;
        if (i == 10) i = 0;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < cnt[i]; j++) cout << s[i];
    }
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