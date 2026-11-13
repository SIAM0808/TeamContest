#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;
template<int ALPHABET = 26, char BASE = 'a'>
struct Trie {
    struct Node {
        int next[ALPHABET];
        int end_cnt = 0;  // Count of this exact string
        int pref_cnt = 0; // Count of strings passing through this prefix
        
        Node() {
            memset(next, -1, sizeof(next));
        }
    };

    vector<Node> nodes;
    ll ans = 0;
    Trie() {
        nodes.emplace_back();
    }

    void insert(const string& s, int k = 1) {
        int u = 0;
        nodes[u].pref_cnt += k;
        int dep = 0;
        for (char c : s) {
            int v = c - BASE;
            if (nodes[u].next[v] == -1) {
                nodes[u].next[v] = nodes.size();
                nodes.emplace_back();
            }
            u = nodes[u].next[v];
            nodes[u].pref_cnt += k;
            dep++;
            ans = max(ans, 1LL * dep * nodes[u].pref_cnt);
        }
        nodes[u].end_cnt += k;
    }
};
void Solve(int tc)
{
    int n;
    cin >> n;
    Trie<20, 'A'> tr;
    int ans = 0;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        tr.insert(s);
    }
    cout << "Case " << tc << ": " << tr.ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    for(int i=1; i<=t; i++){
        Solve(i);
    }
    return 0;
}