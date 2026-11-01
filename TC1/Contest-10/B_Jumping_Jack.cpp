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
   int x;
   cin >> x;
   x = abs(x);
   if(x == 0){
        cout << 0 << endl;
        return;
   }
   int n = 1;
   int l = 1, r = x;
   while(l <= r){
        int mid = (l + r) >> 1;
        int val = (mid*(mid + 1)) / 2;
        if(val >= x) n = mid , r = mid - 1;
        else l = mid + 1;
   }
   debug(n);
   int cnt = 0, ans = n;
   int diff = ((n*(n+1)) / 2) - x;
   n++;
   debug(diff);
   while(diff&1){
        cnt++;
        diff += n;
        n++;
   }
   cout << ans + cnt << endl;
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