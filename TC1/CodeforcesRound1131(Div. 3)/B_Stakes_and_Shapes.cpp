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
    int x, y, z;
    cin >> x >> y >> z;
    int tot = x + y + z;
    string s = "";
    // while()
    vector<pair<int, char>> vp = {{x, 'R'}, {y, 'S'}, {z, 'P'}};
    vector<pair<char, char>> bos = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    sort(vp.rbegin(), vp.rend());
    for (int i = 0; i < 3; i++)
    {
        if (vp[0].second == bos[i].first)
        {
            // int val = vp[i].first;
            int val = tot;
            while (val--)
            {
                s += bos[i].second;
            }
            break;
        }
    }
    cout << s << endl;
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