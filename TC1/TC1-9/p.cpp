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
    string s;
    cin >> s;
    // cout << s << endl;
    int k;
    cin >> k;
    deque<char> dq(s.begin(), s.end());
    if(k == 0){
        cout << s << endl;
        return;
    }
    // cout << dq.size() << endl;
    while(k--){
        if(dq[1] != '0') dq.pop_front();
        else{
            char val = dq.front();
            dq.pop_front();
            dq.pop_front();
            dq.push_front(val);
        }
    }
    for(auto i : dq) cout << i;
    cout << endl;
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