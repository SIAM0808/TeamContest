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
    deque<char> d;
    string s; cin >> s;
    int l = 0;
    while(s.size() && s.back() == '(') s.pop_back();
    while(l < s.size() && s[l] == ')') l++;
    for(auto i=l; i<s.size(); i++) d.push_back(s[i]);
    int cnt = 0, ln = 0;
    for(auto i : d){
        if(i == '(') cnt++;
        else if(i == ')' && cnt > 0) ln += 2, cnt--;
    }
    // cnt = abs(cnt);
    cout << ln << endl;
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