#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
int INF = 1e9;
int sz;
vector<string> v;
vector<vector<int>> cost;
vector<vector<string>> app;
vector<vector<int>> dp;
int mn_len(int mask, int last) {
    if (mask == (1 << sz) - 1) return 0;
    if (dp[mask][last] != -1) return dp[mask][last];

    int ans = INF;
    for (int next = 0; next < sz; next++) {
        if (!(mask & (1 << next))) {
            ans = min(ans, cost[last][next] + mn_len(mask | (1 << next), next));
        }
    }
    return dp[mask][last] = ans;
}

string build(int msk, int lst){
    if(msk == (1 << sz) - 1) return "";
    string bst_add = "Z";
    int Bnxt = -1;
    for(int nxt = 0; nxt < sz; nxt++){
        if(!(msk & (1 << nxt))){
            if(dp[msk][lst] == cost[lst][nxt] + mn_len(msk | (1 << nxt), nxt)){
                if(app[lst][nxt] < bst_add){
                    bst_add = app[lst][nxt];
                    Bnxt = nxt;
                }
            }
        }
    }
    return bst_add + build(msk | (1 << Bnxt), Bnxt);
}
void Solve()
{
    int n;
    cin >> n;
    set<string> st;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        st.insert(s);
    }
    vector<string> tem(st.begin(), st.end());
    st.clear();
    for(auto i=0; i<tem.size(); i++){
        // st.erase(i);
        int f = 1;
        for(auto j=0; j<tem.size(); j++){
            if(i != j && tem[j].find(tem[i]) != string::npos){
                f = 0;
                break;
            }
        }
        if(f) st.insert(tem[i]);
    }
    sz = st.size();
    v = vector<string>(st.begin(), st.end());
    cost.assign(sz, vector<int>(sz));
    dp.assign(1 << sz, vector<int>(sz, -1));
    app.assign(sz, vector<string>(sz));
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            if (i == j) continue;
            int max_ov = 0;
            int len_i = v[i].size(), len_j = v[j].size();
            for (int len = 1; len <= min(len_i, len_j); len++) {
                if (v[i].substr(len_i - len) == v[j].substr(0, len)) {
                    max_ov = len;
                }
            }
            cost[i][j] = len_j - max_ov;
            app[i][j] = v[j].substr(max_ov);
        }
    }

    int mnTL = INF;
    for(int i = 0; i < sz; i++){
        mnTL = min(mnTL, (int)v[i].size() + mn_len(1 << i, i));
    }
    int Bstrt = -1;
    for(int i=0; i<sz; i++){
        if(v[i].size() + mn_len(1 << i, i) == mnTL){
            Bstrt = i;
            break;
        }
    }
    string ans = v[Bstrt] + build(1 << Bstrt, Bstrt);
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