#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

using ll = long long;

template<int ALPHABET = 52>
struct Trie {
    struct Node {
        int next[ALPHABET];
        int end_cnt = 0; 
        
        Node() {
            memset(next, -1, sizeof(next));
        }
    };

    vector<Node> nodes;

    Trie() {
        nodes.emplace_back();
    }

    inline int get_id(char c) {
        if (c >= 'a' && c <= 'z') return c - 'a';
        return c - 'A' + 26;
    }

    void insert(const string& s) {
        int u = 0;
        for (char c : s) {
            int v = get_id(c);
            if (nodes[u].next[v] == -1) {
                nodes[u].next[v] = nodes.size();
                nodes.emplace_back();
            }
            u = nodes[u].next[v];
        }
        nodes[u].end_cnt++;
    }

    int count(const string& s) {
        int u = 0;
        for (char c : s) {
            int v = get_id(c);
            if (nodes[u].next[v] == -1) return 0;
            u = nodes[u].next[v];
        }
        return nodes[u].end_cnt;
    }
};

void solve(int tc) {
    int n;
    cin >> n;
    
    Trie<52> tr;
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.size() > 3) {
            sort(s.begin() + 1, s.end() - 1);
        }
        tr.insert(s);
    }

    int m;
    cin >> m;
    string line;
    getline(cin, line); 

    cout << "Case " << tc << ":\n";

    for (int i = 0; i < m; i++) {
        getline(cin, line);
        stringstream ss(line); 
        string word;
        long long ans = 1;

        while (ss >> word) {
            if (word.size() > 3) {
                sort(word.begin() + 1, word.end() - 1);
            }
            ans *= tr.count(word);
            if (ans == 0) break; 
        }
        cout << ans << "\n";
    }
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