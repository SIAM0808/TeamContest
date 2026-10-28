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
    int n;
    cin >> n;
    int cnt = 0;
    deque<int> dq;
    int f = 0, lagbe = 1;
    for(int i=0; i<2*n; i++){
        string s;
        cin >> s;
        if(s == "add"){
            int x;
            cin >> x;
            // if(dq.empty()) dq.push_back(x);
            // else{
            //     if(dq.back() > x){
            //         f = 1;
            //         dq.push_front(x);
            //     }else dq.push_back(x);
            // }
            dq.push_back(x);
        }else{
            // cnt += f;
            // f = 0;
            if(dq.size()){
                if(dq.size())
                debug(dq.back());
                if(dq.back() == lagbe) dq.pop_back();
                else{
                    cnt++;
                    while(dq.size()){
                        // cerr << dq.back() << endl;
                        dq.pop_back();
                    }
                }
            }
            lagbe++;
        }
    }
    cout << cnt << endl;
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