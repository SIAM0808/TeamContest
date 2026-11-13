#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;


const int MAX_NODES = 100005; 

int trie[MAX_NODES][10]; 
int cnt_pref[MAX_NODES];
int cnt_end[MAX_NODES];
int sz = 0;

void reset() {
    for (int i = 0; i <= sz; i++) {
        memset(trie[i], 0, sizeof(trie[i]));
        cnt_pref[i] = 0;
        cnt_end[i] = 0;
    }
    sz = 0;
}

void insert(const string &s) {
    int cur = 0;
    for (char ch : s) {
        int c = ch - '0';
        if (trie[cur][c] == 0) {
            trie[cur][c] = ++sz;
        }
        cur = trie[cur][c];
        cnt_pref[cur]++;
    }
    cnt_end[cur]++;
}

void solve(int tc) {
    reset(); 
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        insert(s);
    }
    
    bool consistent = true;
    for (int u = 1; u <= sz; u++) {
        if (cnt_end[u] > 0 && cnt_pref[u] > 1) {
            consistent = false;
            break;
        }
    }
    cout << "Case " << tc << ": " << (consistent ? "YES" : "NO") << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
    return 0;
}