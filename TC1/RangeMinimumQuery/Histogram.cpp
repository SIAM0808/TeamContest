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
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=0; i<n; i++) cin >> v[i];
    stack<int> st;
    int ans = 0;
    for(int i=0; i<=n; i++){
        while(st.size() && v[st.top()] > v[i]){
            int h = v[st.top()];
            st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            ans = max(ans, h * w);
        }
        st.push(i);
    }
    cout << ans << endl;
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